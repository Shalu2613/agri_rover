#include<Servo.h>
#include<AccelStepper.h>

#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1
#define RightF 6
#define RightB 7
#define LeftF 8
#define LeftB 9
#define ForwardGC 10
#define BackwardGC 11

const int motor1input1=10,motor1input2=11;
int trigpin=12,echopin=13,data="GF";
long duration,distance,dist;

Servo servo1;
Servo servo2;
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void servo1on();
void servo1off();
void servo2on();
void servo2off();
void stepperon();
void stepperoff();
void dc1on();
void dc1off();
void ultrasonic();

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
  pinMode(RightF,OUTPUT);
  pinMode(RightB,OUTPUT);
  pinMode(LeftF,OUTPUT);
  pinMode(LeftB,OUTPUT);

  //set ultrasonic sensor pins
  pinMode(trigpin,OUTPUT);
  pinMode(echopin, INPUT);
         
  // Set the maximum speed and acceleration for stepper motor:
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(15);
}

void loop() {

  ultrasonic();
  
  if(distance<=30)
  {
    Stop();
  }

/*  -------------------
----------MOTOR MOVENENT CONTROL-----------
 -------------------- */
 
  if(data=='F')
  {
    Forward();
  }
  if(data=='B')
  {
    Backward();
  }
  if(data=='S')
  {
    Stop();
  }
  if(data=='R')
  {
    Rightturn();
  }
  if(data=='L')
  {
    Leftturn();
  }
  
/*  -------------------
MOTOR CONTROL---------------------
 -------------------- */

 /*  -------------------
---------Grass Cutter------------
 -------------------- */
 if(data=="GF")
  {
    Forward();
  }
   if(data=="GB")
  {
    Backward();
  }
  /*  -------------------
---------Grass Cutter------------
 -------------------- */
 

 /*  -------------------
----------SERVO-----------
 -------------------- */
 
  if(data=="S1on")
  {
    servo1on();
  }
  else
  {
    servo1off();
  }
  if(data=="S2on")
  {
    servo2on();
  }
  else
  {
    servo2off();
  }

   /*  -------------------
----------SERVO-----------
 -------------------- */

  /*  -------------------
----------STEPPER-----------
 -------------------- */
  if(data=="Ston")
  {
    stepperon();
  }
  else
  {
    stepperoff();
  }

  //grass cutting
//  if(data==1 && distance>=30)
//  {
//    dc1on();
//  }
//  else if(data==1 && distance<=30)
//  {
//    dc1off();
//  }
//  else
//  {
//    dc1off();
//  }
  
  /*  -------------------
----------STEPPER-----------
 -------------------- */
}

  /*  -------------------
----------Function-----------
 -------------------- */

void ultrasonic(){
    digitalWrite(trigpin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(20);
  duration=pulseIn(echopin,HIGH);
  distance=duration/58.2;
  delay(100);
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
       digitalWrite(RightF, HIGH);
      digitalWrite(RightB, LOW);
      digitalWrite(LeftF, HIGH);
      digitalWrite(LeftB, LOW);
}
void Backward(){
       digitalWrite(RightF, LOW);
      digitalWrite(RightB, HIGH);
      digitalWrite(LeftF, LOW);
      digitalWrite(LeftB, HIGH);
}
void Stop(){
       digitalWrite(RightF, LOW);
      digitalWrite(RightB, LOW);
      digitalWrite(LeftF, LOW);
      digitalWrite(LeftB, LOW);
}
void Rightturn(){
       digitalWrite(RightF, LOW);
      digitalWrite(RightB,HIGH);
      digitalWrite(LeftF, HIGH);
      digitalWrite(LeftB, LOW);
}
void Leftturn(){
       digitalWrite(RightF, HIGH);
      digitalWrite(RightB,LOW);
      digitalWrite(LeftF, LOW);
      digitalWrite(LeftB, HIGH);
}

void ForwardG(){
       digitalWrite(ForwardGC, HIGH);
      digitalWrite(BackwardGC, LOW);
}
void BackwardG(){
       digitalWrite(ForwardGC, LOW);
      digitalWrite(BackwardGC, HIGH);

}
  /*  -------------------
----------Function-----------
 -------------------- */
