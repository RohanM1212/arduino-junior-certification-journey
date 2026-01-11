
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
  // Check the button at the very start of every loop
  checkButton();
  potValue = analogRead(potPin);

  if (mode == 0) {
    // MODE 0: Steady
    int brightness = potValue / 4;
    analogWrite(led1, brightness);
    analogWrite(led2, brightness);
    analogWrite(led3, brightness);
    analogWrite(led4, brightness);
  } 
  else if (mode == 1) {
    // MODE 1: Blink
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    responsiveDelay(potValue); // Use the new function instead of delay()
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    responsiveDelay(potValue);
  } 
  else if (mode == 2) {
    // MODE 2: Chase
    int chaseSpeed = potValue / 4;
    
    digitalWrite(led1, HIGH); responsiveDelay(chaseSpeed); digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH); responsiveDelay(chaseSpeed); digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH); responsiveDelay(chaseSpeed); digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH); responsiveDelay(chaseSpeed); digitalWrite(led4, LOW);
  }
}

// The fix to the problem we were having in the other code
void responsiveDelay(int duration) {
  int start = 0;
  // Break the long delay into 10ms chunks
  while (start < duration) {
    checkButton(); // Check the button EVERY 10 milliseconds
    delay(10);
    start = start + 10;
  }
}

void checkButton() {
  int currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    mode = mode + 1;
    if (mode > 2) {
      mode = 0;
    }
    Serial.print("Mode switched to: ");
    Serial.println(mode);
    delay(200); // Small debounce
  }
  lastButtonState = currentButtonState;
}