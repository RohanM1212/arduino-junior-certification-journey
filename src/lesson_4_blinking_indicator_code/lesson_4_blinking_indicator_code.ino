int readValue = 0;
int writeValue = 0;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(A0);
  writeValue = readValue / 4;
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
}
else if (readValue < 600) {
  analogWrite(9, writeValue);
  analogWrite(10, 0);
  analogWrite(11, 0);
}
else if (readValue < 900) {
  analogWrite(9, writeValue);
  analogWrite(10, writeValue);
  analogWrite(11, 0);
}
else {
  analogWrite(9, writeValue);
  analogWrite(10, writeValue);
  analogWrite(11, writeValue);
}

Serial.print(readValue);
Serial.print(" : ");
Serial.println(writeValue);
delay(100);
}