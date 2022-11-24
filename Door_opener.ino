#include<Servo.h>
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

Servo Myservo;
int pos;
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
void setup()
{
Myservo.attach(9);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
Serial.println("with Arduino UNO R3");
}

void loop()
{
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
// Displays the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");


if (distance <= 10)
{
  for(pos=0;pos<=180;pos++){
    Myservo.write(pos);
    delay(15);
  }
  Serial.print("Door Opened");
  delay(3000);
  
  for(pos=180;pos>=0;pos--){
    Myservo.write(pos);
    delay(15);
  }
  delay(1000);
  
}
}
