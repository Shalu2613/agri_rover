/********************* write()
Description;
Write a byte to the EEPROM.

Syntax:

EEPROM.write(address, value)

Parameters;
address: the location to write to, starting from 0 (int)

value: the value to write, from 0 to 255 (byte)

Returns:
none

Note: An EEPROM write takes 3.3 ms to complete. 
The EEPROM memory has a specified life of 100,000 write/erase cycles, 
so you may need to be careful about how often you write to it.
 *********************************/

#include <EEPROM.h>

//void setup()
//{
//  for (int i = 0; i < 255; i++)
//    EEPROM.write(i, i);
//}
//
//void loop()
//{
//}
char h='A';char i='B';char j='C';char k='D';char l='E';char m='F';char n='G';
int a = 1;int b = 2;int c = 3;
int d = 4;int e = 5;int f = 6;
int g = 7;

char value1;char value2;char value3;
char value4;char value5;char value6;
char value7;

void setup()
{
  Serial.begin(9600);
  
  EEPROM.write(a,h);
  EEPROM.write(b,i);
  EEPROM.write(c,j);
  EEPROM.write(d,k);
  EEPROM.write(e,l);
  EEPROM.write(f,m);
  EEPROM.write(g,n);
  
  value1 = EEPROM.read(a);
  value2 = EEPROM.read(b);
  value3 = EEPROM.read(c);
  value4 = EEPROM.read(d); 
  value5 = EEPROM.read(e);
   value6 = EEPROM.read(f);
    value7 = EEPROM.read(g);

  if(true){
  Serial.print(a);Serial.print("\t"); Serial.print(value1);  Serial.println();
  Serial.print(b); Serial.print("\t"); Serial.print(value2); Serial.println();
  Serial.print(c); Serial.print("\t"); Serial.print(value3); Serial.println();
  Serial.print(d); Serial.print("\t"); Serial.print(value4); Serial.println();
  Serial.print(e); Serial.print("\t"); Serial.print(value5); Serial.println();
  Serial.print(f); Serial.print("\t"); Serial.print(value6); Serial.println();
  Serial.print(g); Serial.print("\t"); Serial.print(value7); Serial.println();
}}

void loop()
{
  
}
