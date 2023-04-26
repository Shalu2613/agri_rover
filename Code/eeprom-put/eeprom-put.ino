/***********************put()
Description;
Write any data type or object to the EEPROM.

Syntax;
EEPROM.put(address, data)
Parameters;
address: the location to write to, starting from 0 (int)

data: the data to write, can be a primitive type (eg. float) or a custom struct

Returns;
A reference to the data passed in

Note: This function uses EEPROM.update() to perform the write, so does not rewrites the value if it didn't change.
 * 
 */


#include <EEPROM.h>

struct MyObject {
  float field1;
  byte field2;
  char name[10];
};

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  float f = 123.456f;  //Variable to store in EEPROM.
  int eeAddress = 0;   //Location we want the data to be put.


  //One simple call, with the address first and the object second.
  EEPROM.put(eeAddress, f);

  Serial.println("Written float data type!");

  /** Put is designed for use with custom structures also. **/

  //Data to store.
  MyObject customVar = {
    3.14f,
    65,
    "Working!"
  };

  eeAddress += sizeof(float); //Move address to the next byte after float 'f'.

  EEPROM.put(eeAddress, customVar);
  Serial.print("Written custom data type! \n\nView the example sketch eeprom_get to see how you can retrieve the values!");
}

void loop() {   /* Empty loop */ }
