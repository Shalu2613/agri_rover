//https://docs.arduino.cc/learn/electronics/stepper-motors
//C:\\Users\\shali\\AppData\\Local\\Temp\\arduino-sketch-F73B488B56D9E8AB521E1A0AD8CD952B/stepper motor driver.ino.hex
#include <Stepper.h>

const int spr=4;
Stepper steper (spr,8,9,10,11);

// const int motor1input1=3;
// const int motor1input2=5;
// const int motor2input1=6;
// const int motor2input2=7;

void setup() {
steper.setSpeed (10);
Serial.begin (9600);

// pinMode(motor1input1,OUTPUT);
// pinMode(motor1input2,OUTPUT);
// pinMode(motor2input1,OUTPUT);
// pinMode(motor2input2,OUTPUT);

// digitalWrite(motor1input1,HIGH);
//   digitalWrite(motor1input2,HIGH);
//   digitalWrite(motor2input1,HIGH);
//   digitalWrite(motor2input2,HIGH);
}

void loop() {

steper.step (60);
delay (200);
//CS01
steper.step (-40);
delay (200);

// digitalWrite(motor1input1,HIGH);
// //Turn first motor in clockwise direction
// digitalWrite(motor1input2,LOW);

// //uncomment this to rotate first motor in anti-clockwise direction
// digitalWrite(motor2input1,HIGH);

// //Turn second motor in anti-clockwise direction
// digitalWrite(motor2input2,LOW);
}
