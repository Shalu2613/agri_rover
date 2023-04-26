/**************update()
Description
Write a byte to the EEPROM. The value is written only if differs from the one already saved at the same address.

Syntax
COPY
EEPROM.update(address, value)
Parameters
address: the location to write to, starting from 0 (int)

value: the value to write, from 0 to 255 (byte)
***************/

#include <EEPROM.h>

void setup()
{
  for (int i = 0; i < 255; i++) {
    // this performs as EEPROM.write(i, i)
    EEPROM.update(i, i);
  }
  for (int i = 0; i < 255; i++) {
    // write value "12" to cell 3 only the first time
    // will not write the cell the remaining 254 times
    EEPROM.update(3, 12);
  }
}

void loop()
{
}
