#include<LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
  lcd.begin(16, 2);

}
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURE");
  delay(3000);
  
  lcd.setCursor(0,1);
  lcd.print("HUMIDITY ");
  delay(3000);
 
  
}
