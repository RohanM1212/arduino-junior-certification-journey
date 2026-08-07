#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

// ---- Timing (5ms = 200Hz sampling rate) ----
const unsigned long SAMPLE_INTERVAL_US = 5000;
unsigned long nextExecutionTime = 0;

// ---- Yaw integration ----
double calibratedYawAngleRad = 0.0;
float  gyroZOffset = 0.0;

// ---- Button (recalibrate on press) ----
const uint8_t BUTTON_PIN = 2;
const unsigned long DEBOUNCE_MS = 50;
bool lastButtonReading = HIGH;   // INPUT_PULLUP: released = HIGH, pressed = LOW
bool buttonState = HIGH;
unsigned long lastDebounceTime = 0;

// Pressing the button refreshes the gyro offset AND zeroes the accumulated yaw angle.

const bool RESET_ANGLE_ON_CALIBRATION = true;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  pinMode(BUTTON_PIN, INPUT_PULLUP);   // button wired between pin 10 and GND

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1) delay(10);
  }

  // 1. SPEED: Force I2C hardware bus to 400kHz Fast Mode
  Wire.setClock(400000);

  // 2. ACCURACY: Enable internal low-pass filter to block vibration
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_10_HZ);

  // Initial baseline calibration
  calibrateGyro();

  // Set up the high-precision microsecond timing gate
  resetTiming();
}

void loop() {
  // Poll the button every iteration (independent of the 5ms sample gate)
  handleButton();

  // 3. TIMING: Strict time-gated execution loop
  unsigned long currentTime = micros();

  if ((long)(currentTime - nextExecutionTime) >= 0) {

    // Precise elapsed time; using the actual difference prevents runtime drift
    double dt = (currentTime - (nextExecutionTime - SAMPLE_INTERVAL_US)) / 1000000.0;
    nextExecutionTime += SAMPLE_INTERVAL_US;

    // Grab the sensor event immediately
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // Corrected rate: subtract the calibrated offset
    float calibratedGyroZRad = g.gyro.z - gyroZOffset;
    if (abs(calibratedGyroZRad) < 0.0008) {
      calibratedGyroZRad = 0.0;
    }
    // High-speed precision integration
    calibratedYawAngleRad += calibratedGyroZRad * dt;

    // Convert to degrees for output
    double calYawRateDPS  = calibratedGyroZRad * (180.0 / M_PI);
    double calYawAngleDeg = calibratedYawAngleRad * (180.0 / M_PI);

    // 4. PRINTER: Clean, raw values separated by tabs
    // Order: dt (sec) | Yaw Rate (DPS) | Yaw Angle (Deg)
    Serial.print(dt, 6);
    Serial.print("\t");
    Serial.print(calYawRateDPS, 6);
    Serial.print("\t");
    Serial.println(calYawAngleDeg, 6);
  }
}

// Debounced, edge-triggered button: one press = one recalibration.
void handleButton() {
  bool reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_MS) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {          // falling edge = a fresh press
        Serial.println("Button pressed -> recalibrating.");
        calibrateGyro();

        if (RESET_ANGLE_ON_CALIBRATION) {
          calibratedYawAngleRad = 0.0;   // re-zero the accumulated heading
        }

        resetTiming();                   // discard the long blocking gap
      }
    }
  }

  lastButtonReading = reading;
}

// calibrateGyro() blocks for ~3s, so micros() jumps far past nextExecutionTime.
// Re-anchor the timing gate afterward or the next dt would be huge.
void resetTiming() {
  nextExecutionTime = micros() + SAMPLE_INTERVAL_US;
}

void calibrateGyro() {
  Serial.println("Calibrating... Keep sensor flat and completely still.");
  double totalZ = 0.0;
  const int samples = 1000;

  for (int i = 0; i < samples; i++) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    totalZ += g.gyro.z;
    delay(3);
  }
  gyroZOffset = totalZ / samples;
  Serial.print("Calibration Complete. Offset: ");
  Serial.println(gyroZOffset, 6);
  delay(1000); // brief pause so the message is readable before data resumes
}