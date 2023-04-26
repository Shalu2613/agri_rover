#include <EEPROM.h>

unsigned long previousTime = 0;
byte seconds ;

char  a[20]="final";;
char value;
int i;int n=20;

void setup()
{
  Serial.begin (9600);

  for(i=0;i<=n;i++)
    {
      EEPROM.write(i,a[i]);
    }
}

void loop ()
{
// I  think using microseconds is even more accurate
  if (millis() >= (previousTime)) 
  {
     previousTime = previousTime + 1000;  // use 100000 for uS
     seconds = seconds +1;
for(i=0;i<=n;i+=5){
    value = EEPROM.read(a[i]);
    Serial.print(i);
  Serial.print("\t");
  Serial.print(value);
  Serial.println();
  }
  } }
