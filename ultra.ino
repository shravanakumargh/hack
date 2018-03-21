#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
int disp;
// Create a servo object 
Servo Servo1; 

const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
Servo1.attach(servoPin);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);       
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
if(duration>10)
{
  distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
while (duration>10 && 10<distance&&distance<30)
{
  Serial.print("step1");
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
  
    digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
duration = pulseIn(echoPin, HIGH);
digitalWrite(trigPin, LOW);
disp=1;
distance= duration*0.034/2;
  Serial.print("step3");
 goto label1;
     //disp=1;
  Serial.print("step2");
  

  label1:if(distance>10)
  {
    disp=1;
  }
  else
  {
    disp=0;
  }
 switch(disp)
  {
    case 1:Serial.print("step");
    Servo1.write(0); 
   delay(1000); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   break;
   delay(1000);
//   goto label2;
   default:break; 
  }
  
//  goto label;
}}  }

