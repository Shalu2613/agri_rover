#include<Servo.h>
Servo s;
void setup()
{
  s.attach(3);
  Serial.begin(9600);
}

void loop()
{
  
 for(int i=0;i<=180;i++)
  {
    s.write(i);
    Serial.println("clockwise");
    Serial.print("angle is");
    Serial.println(i);
  }
  delay(3000);
  for(int j=180;j>=0;j--)
  {
     s.write(j);
    Serial.println("anti clockwise");
    Serial.print("angle is");
    Serial.println(j);
  }
  delay(3000);
  /*s.write(0);
  delay(1000);
  Serial.println(0);
  
   s.write(30);
  delay(1000);
  Serial.println(30);
  
   s.write(60);
  delay(1000);
  Serial.println(60);
  
   s.write(90);
  delay(1000);
  Serial.println(90);
   s.write(130);
  delay(1000);
  Serial.println(130);
  
   s.write(180);
  delay(1000);
Serial.println(180);*/
  
}

