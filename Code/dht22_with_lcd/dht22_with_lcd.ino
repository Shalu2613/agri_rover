 #include "DHT.h"  
 DHT dht2(2,DHT22);
#include<LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.begin(16, 2);
  dht2.begin();
  Serial.begin(9600); 
  
}
void loop()
{
  float temp=dht2.readTemperature();
  float humidity=dht2.readHumidity();
   Serial.println("Temperature in C:");  
   Serial.println(temp);  
   Serial.println("Humidity in C:");  
   Serial.println(humidity);  
   delay(1000);
   
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURE:");
  lcd.print(temp);
 
  
  lcd.setCursor(0,1);
  lcd.print("HUMIDITY:");
  lcd.print(humidity);

 
  
}
