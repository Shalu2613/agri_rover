#include<Servo.h>
#include<Servo.h>
#include<AccelStepper.h>

Servo servo1;
Servo servo2;

#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1

#define Right1  6
#define Right2  7
#define Left1   8
#define Left2   9

//Define all the input pins of the motor driver
const int motor1input1=10;
const int motor1input2=11;

int trigpin=12;
int echopin=13;
long duration,distance,dist;

//void servo1on();//void servo1off();//void servo2on();//void servo2off();//void stepperon();//void stepperoff();//void dc1on();//void dc1off();

AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  //set servo pins
  servo1.attach(4);
  servo2.attach(5);
  Serial.begin(9600);
  
  //set stepper motor pins
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  //Set all the pin as OUTPUT for dc motor1
  pinMode(motor1input1,OUTPUT);
  pinMode(motor1input2,OUTPUT);
   
  //set all the pin as output for movement
  pinMode(Right1,OUTPUT);
  pinMode(Right2,OUTPUT);
  pinMode(Left1,OUTPUT);
  pinMode(Left2,OUTPUT);

  //set ultrasoin sensor pins
  pinMode(trigpin,OUTPUT);
  pinMode(echopin, INPUT);
         
  // Set the maximum speed and acceleration for stepper motor:
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(15);

  int servo1on,servo2on,stepperon,dc1on;
  int forward,backward,stop,rightturn,leftturn;
}

void loop() {
  
  int forward,backward,stop,rightturn,leftturn;
  digitalWrite(trigpin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(20);
  duration=pulseIn(echopin,HIGH);
  distance=duration/58.2;
  delay(100);

  if(distance<=30)
  {
    Stop();
  }
  
  if(forward==1)
  {
    Forward();
  }
  if(backward==1)
  {
    Backward();
  }
  if(stop==1)
  {
    Stop();
  }
  if(rightturn==1)
  {
    Rightturn();
  }
  if(leftturn==1)
  {
    Leftturn();
  }
  
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

  //grass cutting
  if(dc1on==1&&distance>=30)
  {
    dc1on();
  }
  else if(dc1on==1&&distance<=30)
  {
    dc1off();
  }
  else
  {
    dc1off();
  }
  

}

void servo1on()
{
    for(int i=0;i<=90;i++)
  {
    servo1.write(i);
    Serial.println("clockwise"); Serial.println("angle is:"); Serial.println(i);
  }
  delay(1000);
}
void servo1off()
{
  for(int j=90;j>=0;j--)
  {
    servo1.write(j); 
    Serial.println("clockwise"); Serial.println("angle is:"); Serial.println(j);
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

void dc1on()
{
  digitalWrite(motor1input1,HIGH);
   //Turn first motor in clockwise direction
  digitalWrite(motor1input2,LOW);
}

void dc1off()
{
  digitalWrite(motor1input1,LOW);
  digitalWrite(motor1input2,LOW);
}

void Forward(){
       digitalWrite(Right1, HIGH);
      digitalWrite(Right2, LOW);
      digitalWrite(Left1, HIGH);
      digitalWrite(Left2, LOW);
}

void Backward(){
       digitalWrite(Right1, LOW);
      digitalWrite(Right2, HIGH);
      digitalWrite(Left1, LOW);
      digitalWrite(Left2, HIGH);
}

void Stop(){
       digitalWrite(Right1, LOW);
      digitalWrite(Right2, LOW);
      digitalWrite(Left1, LOW);
      digitalWrite(Left2, LOW);
}

void Rightturn(){
       digitalWrite(Right1, LOW);
      digitalWrite(Right2,HIGH);
      digitalWrite(Left1, HIGH);
      digitalWrite(Left2, LOW);
}
void Leftturn(){
       digitalWrite(Right1, HIGH);
      digitalWrite(Right2,LOW);
      digitalWrite(Left1, LOW);
      digitalWrite(Left2, HIGH);
}
   
