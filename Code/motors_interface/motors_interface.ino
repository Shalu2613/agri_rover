#include<Servo.h>
#include<Servo.h>
#include<Stepper.h>

Servo servo1;

Servo servo;
//const int spr=4;
//stepper steper(spr,8,9,10,11);
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 200

void setup()
{
 // steper.setspeed(10);
  servo1.attach(4);
  servo.attach(5);
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
}
void loop()
{
  for(int i=0;i<=90;i++)
  {
    servo1.write(i);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(i);
  }
  delay(1000);
  for(int j=90;j>=0;j--)
  {
    servo1.write(j);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(j);
  }
  delay(1000);

   for(int i=0;i<=90;i++)
  {
    servo.write(i);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(i);
  }
  delay(1000);
  for(int j=90;j>=0;j--)
  {
    servo.write(j);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(j);
  }
  delay(1000);


digitalWrite(dirPin, HIGH);

  // spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }

  delay(1000);

  // set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);

  // spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }

  delay(1000);

  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }

  delay(1000);

  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);

  //Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}
