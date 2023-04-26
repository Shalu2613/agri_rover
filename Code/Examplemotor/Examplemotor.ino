#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // run ic2_scanner sketch and get the IC2 address, which is 0x3f in my case,it could be 0x3f in many cases
Servo servo1; //initialize Servo
#define trigPin 9 //initialize pin9 for HC-SR04 trigger pin
#define echoPin 8 //initialize pin8 for HC-SR04 Echo pin
#define led 2 ////initialize pin2 for LED
int motorPin1 = 7; // Initialize pin7 to drive motor1
int motorPin2 = 6; // Initialize pin6 to drive motor2
int pos = 0;

void setup()
{
  lcd.begin (16, 2); // start LCD


  lcd.init(); // Initialize LCD
  // Set the pin modes of the above IO pins to OUTPUT

  lcd.setCursor(2, 0); // Set cursor

  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("  Hello!");
  lcd.setCursor(0, 1);
  lcd.print(" Microdigisoft");
  delay(5000);

  // initialize the lcd
  Serial.begin (9600);
  servo1.attach(10); // third wire of servo motor lead
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}
void loop()
{
  lcd.begin(16, 2);
  // clear old screen data
  lcd.clear();
  // text to be displayed on the screen
  lcd.setCursor(3, 0);
  lcd.print("OBJECT");
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  lcd.setCursor(0, 1);
  lcd.print ("distance:");
  if (distance <= 20)
  {
    // waits 15ms for the servo to reach the position

    //servo1.write(180);
    Serial.print(distance);
    lcd.print (distance);
    lcd.print ("cm");
    digitalWrite(led, HIGH);
    for (pos = 180; pos > 1; pos -= 1)              // goes from 180 degrees to 0 degrees                                                                                 // in steps of 1 degree
    {
      servo1.write (pos);                                                  // tell servo to go to position in variable 'pos'
      delay (3);                                        // waits 10ms for the servo to reach the position
    }
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    Serial.println("cm : LED is on ");
    delay(500);
    for (pos = 0; pos < 180; pos += 1) // goes from 0 degrees to 180 degrees
    { // in steps of 1 degree
      servo1.write(pos);
      delay(3);

    }
  }
  else {
    //servo1.write(0);
    Serial.print(distance);
    lcd.print (distance);
    lcd.print ("cm");
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(1000);
    digitalWrite(led, LOW);
    Serial.println(" cm : LED is off ");
    delay(500);

    servo1.write(0);// waits 15ms for the servo to reach the position
  }
}
