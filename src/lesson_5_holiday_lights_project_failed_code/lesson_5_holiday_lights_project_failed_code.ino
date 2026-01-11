// Pin Variables
int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;
int buttonPin = 8;
int potPin = A0;


int mode = 0; 
int potValue = 0;
int lastButtonState = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // 1. Read Inputs
  int currentButtonState = digitalRead(buttonPin);
  potValue = analogRead(potPin);

  // 2. Change Mode (Conditional Statement)
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    mode = mode + 1;
    if (mode > 2) {
      mode = 0;
    }
    delay(200); // Wait for button release
  }
  lastButtonState = currentButtonState;

  // 3. Output Logic
  if (mode == 0) {
    // MODE 0: All on, Brightness controlled by Pot
    int brightness = potValue / 4;
    analogWrite(led1, brightness);
    analogWrite(led2, brightness);
    analogWrite(led3, brightness);
    analogWrite(led4, brightness);
  } 
  else if (mode == 1) {
    // MODE 1: All Blink, Speed controlled by Pot
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    delay(potValue);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    delay(potValue);
  } 
  else if (mode == 2) {
    // MODE 2: Chase, Speed controlled by Pot
    digitalWrite(led1, HIGH);
    delay(potValue / 4);
    digitalWrite(led1, LOW);
    
    digitalWrite(led2, HIGH);
    delay(potValue / 4);
    digitalWrite(led2, LOW);
    
    digitalWrite(led3, HIGH);
    delay(potValue / 4);
    digitalWrite(led3, LOW);
    
    digitalWrite(led4, HIGH);
    delay(potValue / 4);
    digitalWrite(led4, LOW);
  }
}