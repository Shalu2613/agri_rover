#include <EEPROM.h>

unsigned long previousTime = 0;
byte seconds ;

char h='A';char i='B';char j='C';char k='D';
int a = 1;int b = 2;int c = 3;int d = 4;
char value1;char value2;char value3;char value4;

void setup()
{
Serial.begin (9600);

EEPROM.write(1,h);
  EEPROM.write(2,i);
  EEPROM.write(3,j);
  EEPROM.write(4,k);

  value1 = EEPROM.read(a);
  value2 = EEPROM.read(b);
  value3 = EEPROM.read(c);
  value4 = EEPROM.read(d);

  
}

void loop ()
{
// I  think using microseconds is even more accurate
  if (millis() >= (previousTime)) 
  {
     previousTime = previousTime + 1000;  // use 100000 for uS
     seconds = seconds +1;
       if(seconds==5)
 //     Serial.print("seconds:");
 //      Serial.println(seconds);
  {
    Serial.print(a);Serial.print("\t"); Serial.print(value1);  Serial.println();
  }
       if(seconds==10)
  {
    Serial.print(b);Serial.print("\t"); Serial.print(value2);  Serial.println();
  }
      if(seconds==15)
  {
    Serial.print(c);Serial.print("\t"); Serial.print(value3);  Serial.println();
  }
       if(seconds==20)
  {
    Serial.print(d);Serial.print("\t"); Serial.print(value4);  Serial.println();
  }
  }
  //Serial.println(seconds,DEC);
  Serial.print("seconds:");Serial.print(seconds);Serial.println();
      
      delay(1000);

}
