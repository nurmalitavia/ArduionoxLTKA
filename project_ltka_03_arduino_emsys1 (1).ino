#include <Servo.h>
Servo servo1;
int pos1 =0;
const int trigPin = 12;   //pin trigger sensor ultrasonik
const int echoPin = 11;
const int buzz = 10;
long duration;
int distance;

void setup() 
{
  servo1.attach(9);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzz, OUTPUT);
  Serial.begin(9600); 
}

void loop() 
{ 
  for(pos1 =0; pos1 <180; pos1 +=1)
  {
    servo1.write(pos1);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
     if (distance <=80 and distance >=60) {
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(buzz, LOW);
    delay(1000)  ; 
  }
  else if (distance <60 and distance >=30) {
    digitalWrite(buzz, HIGH);
    delay(500) ;
    digitalWrite(buzz, LOW);
    delay(500);
  }
  else if (distance <30 and distance >0) {
    digitalWrite(buzz, HIGH);
    delay(200) ;
    digitalWrite(buzz, LOW);
    delay(200);
  }
    
  }
  for(pos1 =180; pos1 >=1; pos1 -=1)
  {
    servo1.write(pos1);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
     if (distance <=80 and distance >=60) {
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(buzz, LOW);
    delay(1000)  ; 
  }
  else if (distance <60 and distance >=30) {
    digitalWrite(buzz, HIGH);
    delay(500) ;
    digitalWrite(buzz, LOW);
    delay(500);
  }
  else if (distance <30 and distance >0) {
    digitalWrite(buzz, HIGH);
    delay(200) ;
    digitalWrite(buzz, LOW);
    delay(200);
  }
  }
}