
#include<Servo.h>
#include<Servo.h>
#include<AccelStepper.h>

#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1
#define RightF 6
#define RightB 7  //28,29,30,31
#define LeftF 8
#define LeftB 9
#define ForwardGC 10
#define BackwardGC 11
//const int motor1input1=12,motor1input2=13;

/*************PESTICIDE SPRAYING*************/
#define waterpump   3
#define lorasignal  6

unsigned long int data;
int trigpin1=A0,echopin1=A1,trigpin2=A2,echopin2=A3,trigpin3=A6,echopin3=A7;
long durationL,distanceL,durationC,distanceC,durationR,distanceR;
int destination;

Servo servo1;
Servo servo2;
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void servo1on(); void servo1off();
void servo2on(); void servo2off();
void stepperon(); void stepperoff();
void dc1on(); void dc1off();

int ultrasonic_sensor1(); int ultrasonic_sensor2(); int ultrasonic_sensor3();

void setup() {
  //set servo pins
  servo1.attach(4);
  servo2.attach(5);
  Serial.begin(9600);
  
  //set stepper motor pins
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  //Set all the pin as OUTPUT for dc motor1
  pinMode(ForwardGC,OUTPUT);
  pinMode(BackwardGC,OUTPUT);
   
  //set all the pin as output for movement
  pinMode(RightF,OUTPUT);
  pinMode(RightB,OUTPUT);
  pinMode(LeftF,OUTPUT);
  pinMode(LeftB,OUTPUT);

  //set ultrasonic sensor pins
  pinMode(trigpin1,OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(trigpin2,OUTPUT);
  pinMode(echopin2, INPUT);
  pinMode(trigpin3,OUTPUT);
  pinMode(echopin3, INPUT);
         
  // Set the maximum speed and acceleration for stepper motor:
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(15);

  //set lora and waterpump pins
  pinMode(waterpump ,OUTPUT); 
  pinMode(lorasignal,INPUT);
}

void loop() {

  if(Serial.available()){
  data = Serial.read();
  Serial.println(data);
}
   /*  -------------------
----------ULTRASONIC SENSOR INTERFACE CONTROL-----------
 -------------------- */
  ultrasonic_sensor1();
  ultrasonic_sensor2();
  ultrasonic_sensor3();
  if(distanceL<=30 || distanceR<=30 || distanceC<=30)
  {
    Stop();
    delay(3000);
  }
  if(distanceL>distanceC && distanceL>distanceR)
  {
    Leftturn();
    delay(1000);
  }
  else if(distanceR>distanceL && distanceR>distanceC)
  {
    Rightturn();
    delay(1000);
  }
  else
  {
    Forward();
    delay(1000);
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
  if(data=="GS")
  {
    Stop();
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
  
  /*  -------------------
----------STEPPER-----------
 -------------------- */
 
 /*  -------------------
----------PESTICIDE SPRAYING-----------
 -------------------- */
 if(data=="PS")
 {
  Spraying();
 }
 
}

  /*  -------------------
----------Function-----------
 -------------------- */

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
//void dc1on()
//{
//  digitalWrite(motor1input1,HIGH);
//   //Turn first motor in clockwise direction
//  digitalWrite(motor1input2,LOW);
//}
//void dc1off()
//{
//  digitalWrite(motor1input1,LOW);
//  digitalWrite(motor1input2,LOW);
//}
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

void Spraying()
{
  destination= digitalRead(lorasignal);  
  if(destination== HIGH) // if water level is full then cut the relay 
  {
  digitalWrite(waterpump ,LOW); 
  }
  else
  {
  digitalWrite(waterpump ,HIGH); //high to continue providing signal and water supply
  }
  delay(400); 
}


int ultrasonic_sensor1()
{
 digitalWrite(trigpin1,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(20);
  durationL=pulseIn(echopin1,HIGH);
  //distance=duration/58.2;
  distanceL=(durationL*0.0343)/2;
  Serial.println("distanceL:");
  Serial.println(distanceL);
  delay(100);
  return(distanceL);
}
int ultrasonic_sensor2()
{
 digitalWrite(trigpin2,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin2,HIGH);
  delayMicroseconds(20);
  durationC=pulseIn(echopin2,HIGH);
  distanceC=(durationC*0.0343)/2;
  Serial.println("distanceC:");
  Serial.println(distanceC);
  delay(100);
  return(distanceC);
}
int ultrasonic_sensor3()
{
 digitalWrite(trigpin3,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin3,HIGH);
  delayMicroseconds(20);
  durationR=pulseIn(echopin3,HIGH);
  distanceR=(durationR*0.0343)/2;
  Serial.println("distanceR:");
  Serial.println(distanceR);  
  delay(100);
  return(distanceR);
}
  /*  -------------------
----------Function-----------
 -------------------- */
