#include <Servo.h>

const int sensorPin = A0;
const int LEDPin = 10;
const int servoPin = 3;

int lightAmount = 0;
int servoAngle = 0;
int inputCommand = 0;

Servo myServo;

void setup() {
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(servoAngle);
  delay(1000);
}

void loop() {
  if (Serial.available()) {
    inputCommand = Serial.read();

    switch (inputCommand) {
      case '+':
        servoAngle += 10;
        if (servoAngle >= 180) {
          servoAngle = 180;
          digitalWrite(LEDPin, HIGH);
          delay(500);
          digitalWrite(LEDPin, LOW);
        }
        break;

      case '-':
        servoAngle -= 10;
        if (servoAngle <= 0) {
          servoAngle = 0;
          digitalWrite(LEDPin, HIGH);
          delay(500);
          digitalWrite(LEDPin, LOW);
        }
        break;
    }

    myServo.write(servoAngle);
    delay(500);

    lightAmount = analogRead(sensorPin);

    Serial.print("Angle: ");
    Serial.print(servoAngle);
    Serial.print("  Light Intensity: ");
    Serial.println(lightAmount);
  }
}