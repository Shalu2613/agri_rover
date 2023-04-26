#include<Servo.h>
#include<Servo.h>
Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(4);
  servo2.attach(5);
  Serial.begin(9600);

}

void loop() {
   for(int i=0;i<=90;i++)
  {
    servo1.write(i);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(i);
  }
  delay(500);
  for(int j=90;j>=0;j--)
  {
    servo1.write(j);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(j);
  }
  delay(500);

   for(int i=0;i<=90;i++)
  {
    servo2.write(i);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(i);
  }
  delay(500);
  for(int j=90;j>=0;j--)
  {
    servo2.write(j);
    Serial.println("clockwise");
    Serial.println("angle is:");
    Serial.println(j);
  }
  delay(1000);
 

}
