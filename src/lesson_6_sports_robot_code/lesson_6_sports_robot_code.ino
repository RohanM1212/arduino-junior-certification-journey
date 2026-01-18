#include <Servo.h>                              
Servo myServo;                                  
const int potPin = A0;                          
const int buttonPin = 7;                        
int potValue = 0;                               
int servoAngle = 0;                             
void setup() {
  myServo.attach(9);                            
  Serial.begin(9600);                           
}
 
void loop() {
  if(digitalRead(buttonPin) == HIGH) {          
    myServo.write(179);                         
  }
  else {                                        
    potValue = analogRead(potPin);              
    servoAngle = map(potValue, 0, 1023, 0, 179);  
    myServo.write(servoAngle);                  
  }
  Serial.print("potValue: ");                   
  Serial.print(potValue);                       
  Serial.print(", servoAngle: ");               
  Serial.println(servoAngle);                     
  delay(100);                                   
}