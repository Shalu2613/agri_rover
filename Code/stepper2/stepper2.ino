//// Include the AccelStepper library:
//#include <AccelStepper.h>
//
//// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
//#define dirPin 2
//#define stepPin 3
//#define motorInterfaceType 1
//
//// Create a new instance of the AccelStepper class:
//AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
//
//void setup() {
//  // Set the maximum speed and acceleration:
//  stepper.setMaxSpeed(100);//200
//  stepper.setAcceleration(15);//30
//}
//
//void loop() {
//  // Set the target position:
//  stepper.moveTo(90);
//  // Run to target position with set speed and acceleration/deceleration:
//  stepper.runToPosition();
//
//  delay(1000);
//
//  // Move back to zero:
//  stepper.moveTo(0);
//  stepper.runToPosition();
//
//  delay(1000);
//}
// Define stepper motor connections and steps per revolution:
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 200

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }

  delay(1000);

  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);

  // Spin the stepper motor 1 revolution quickly:
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
