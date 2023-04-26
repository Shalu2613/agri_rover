// TECHATRONIC.COM  
 // DHT11 LIBRARY  
 // https://github.com/adafruit/DHT-sensor-library  
 #include "DHT.h"  
 DHT dht2(2,DHT22);  
 void setup()  
 {  
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
 }  
