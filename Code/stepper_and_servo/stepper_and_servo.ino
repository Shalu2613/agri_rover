#include<Servo.h>
#include<Servo.h>
#include<AccelStepper.h>

Servo servo1;
Servo servo2;

#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1

void servo1on();
void servo1off();
void servo2on();
void servo2off();
void stepperon();
void stepperoff();


AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  
  servo1.attach(4);
  servo2.attach(5);
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(15);

  int servo1on=1;
  int servo2on=1;
  int stepperon=1;
//  int servo1on=1;
//  delay(1000);
//  int servo1on=0;
//  int servo2on=1;
//  delay(1000);
//  int servo2on=0;
}

void loop() {
  
  if(servo1on==1)
  {
    servo1on();
  }
  else
  {
    servo1off();
  }

  
  if(servo2on==1)
  {
    servo2on();
  }
  else
  {
    servo2off();
  }
  if(stepperon==1)
  {
    stepperon();
  }
  else
  {
    stepperoff();
  }

}

void servo1on()
{
    for(int i=0;i<=90;i++)
  {
    servo1.write(i);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(i);
  }
  delay(1000);
}
void servo1off()
{
  for(int j=90;j>=0;j--)
  {
    servo1.write(j);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(j);
  }
  delay(1000);
}

void servo2on()
{
    servo2.write(90);
    delay(1000);
    Serial.println("angle is:90");
}
void servo2off()
{
    servo2.write(0);
    delay(1000);
    Serial.println("angle is:0");
}
void stepperon()
{
    // Set the target position:
  stepper.moveTo(90);
  // Run to target position with set speed and acceleration/deceleration:
  stepper.runToPosition();

  delay(1000);
}

void stepperoff()
{
    // Move back to zero
    stepper.moveTo(0);
    stepper.runToPosition();

    delay(1000);
  
    
}
