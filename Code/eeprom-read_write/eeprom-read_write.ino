/**************************
 * EEPROM[]
Description;
This operator allows using the identifier EEPROM like an array. EEPROM cells can be read and written directly using this method.

Syntax;
EEPROM[address]

Parameters;
address: the location to read/write from, starting from 0 (int)

Returns;
A reference to the EEPROM cell
 */


#include <EEPROM.h>

void setup(){

  unsigned char val;

  //Read first EEPROM cell.
  val = EEPROM[ 0 ];

  //Write first EEPROM cell.
  EEPROM[ 0 ] = val;

  //Compare contents
  if( val == EEPROM[ 0 ] ){
    //Do something...
  }
}

void loop(){ /* Empty loop */ }
