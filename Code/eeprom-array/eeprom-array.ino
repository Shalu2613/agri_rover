#include <EEPROM.h>

char  a[20]="final";;
char value;
int i;int n=6;

void setup()
{
  Serial.begin(9600);

  
  for(i=0;i<=n;i++)
  {
    EEPROM.write(i,a[i]);
  }
  

  for(i=0;i<=n;i++)
  
  {
    value = EEPROM.read(a[i]);
    Serial.print(i);
  Serial.print("\t");
  Serial.print(value);
  Serial.println();
  }  
}

void loop()
{}
