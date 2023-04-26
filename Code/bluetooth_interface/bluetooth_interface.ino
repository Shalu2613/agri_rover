char data; //declaring Variable for storing received data
void setup() {
    Serial2.begin(9600);  // baud rate for serial data transmission
     Serial.begin(9600); 
    pinMode(12, OUTPUT); /*assigning digital pin  13 to LED and giving it an output mode */
}
void loop(){
    if(Serial2.available() > 0) // checks if any data is received
    {
        data = Serial2.read(); /*Reading any receiving data and storing it into variable named data*/
        Serial.print(data);  //displaying the data
        Serial.print("\n");  //adding space by giving a New line
        if(data == 'A')      // when the value  is equal to 1
          digitalWrite(12, HIGH);  // turn the LED
        else if(data == 'B')  // when the value  is equal to 0
           digitalWrite(12, LOW);// turn off the LED      
    }                            
}
