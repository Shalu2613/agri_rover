// AFMotor Library : https://www.arduino.cc/reference/en/libraries/adafruit-motor-shield-library/
//Technical Tamizha - YT
#include <AFMotor.h> 
          // defines Left motor connector
AF_DCMotor R_motor(2);           // defines Right motor connector
AF_DCMotor L_motor(3);
// declare variables
int distancecm=0;
const int trigPin = A0;
const int echoPin = A1;
// defines variables
long duration;
int distance;
int Data;
                

void setup() {
  Serial.begin(9600);           // sets up Serial library at 9600 bps
  
//changes the following values to make the robot  drive as straight as possible  
 
  
  L_motor.setSpeed(200);        // sets L motor speed
  R_motor.setSpeed(140);        // sets R motor speed
 
  R_motor.run(RELEASE);         //turns L motor on
  L_motor.run(RELEASE);         //turns R motor on
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
   pinMode(echoPin, INPUT); // Sets the echoPin as an Input  
}

void loop() {
  distancecm=mdistance();

  if(Serial.available()){
  Data = Serial.read();
  Serial.println(Data);
}

 if(Data == 'F'){
    L_motor.run(FORWARD);      //moves motor L Forward
  R_motor.run(FORWARD);
 }

 if(Data == 'B'){
    R_motor.run(BACKWARD);        
  L_motor.run(BACKWARD);
 }

 if(Data == 'L'){
    R_motor.run(FORWARD);         
  L_motor.run(BACKWARD);
 }

 if(Data == 'R'){
    R_motor.run(BACKWARD);         
  L_motor.run(FORWARD);
 }

 if(Data == 'S'){
  L_motor.run(RELEASE);      
  R_motor.run(RELEASE); 
 }
 
  if(distance<10){
    R_motor.run(RELEASE);         
  L_motor.run(RELEASE); 
  
  //go backward 
  R_motor.run(BACKWARD);        
  L_motor.run(BACKWARD);
   delay(700);
  L_motor.run(RELEASE);      
  R_motor.run(RELEASE); 
   
   
  }

}

int mdistance()
{

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
Serial.print(distance);

  
  
  }
