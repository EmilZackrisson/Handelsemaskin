#include <Servo.h> 

Servo myservo;

int trigPin = 9;
int echoPin = 10;
long duration, cm, inches;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(8);
  myservo.write(90);
}
 
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
 
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343

  Serial.println(cm);
  
  delay(250);

  if(cm <= 10){
    lightCandle();
  }
}

void lightCandle(){
  myservo.write(0);
}
