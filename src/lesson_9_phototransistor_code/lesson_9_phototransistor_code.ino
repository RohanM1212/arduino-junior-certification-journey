const int sensorPin = A0;
const int LEDPin = 10;

int lightAmount = 0;
long timerLED = 0;
long timerSensor = 0;
int toggleLED = 0;

void setup() {
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  transmitter();
  receiver();
}

void transmitter() {
  if (millis() >= timerLED + 2000) {
    toggleLED = !toggleLED;
    digitalWrite(LEDPin, toggleLED);
    timerLED = millis();
  }
}

void receiver() {
  if (millis() >= timerSensor + 100) {
    lightAmount = analogRead(sensorPin);
    Serial.print("Light Intensity: ");
    Serial.println(lightAmount);
    timerSensor = millis();
  }
}