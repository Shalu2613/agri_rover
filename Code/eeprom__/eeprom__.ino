#include <EEPROM.h>

void writeIntArrayIntoEEPROM(int address, int numbers[], int arraySize)
{
  int addressIndex = address;
  for (int i = 0; i < arraySize; i++) 
  {
    EEPROM.write(addressIndex, numbers[i] >> 8);
    EEPROM.write(addressIndex + 1, numbers[i] & 0xFF);
    addressIndex += 2;
  }
}

void readIntArrayFromEEPROM(int address, int numbers[], int arraySize)
{
  int addressIndex = address;
  for (int i = 0; i < arraySize; i++)
  {
    numbers[i] = (EEPROM.read(addressIndex) << 8) + EEPROM.read(addressIndex + 1);
    addressIndex += 2;
  }
}

void setup() {
  Serial.begin(9600);
  const int ARRAY_SIZE = 5;
  const int STARTING_EEPROM_ADDRESS = 17;

  int numbers[ARRAY_SIZE] = { 3, 25000, -1278, 34, -9999 };
  writeIntArrayIntoEEPROM(STARTING_EEPROM_ADDRESS, numbers, ARRAY_SIZE);

  int newNumbers[ARRAY_SIZE];
  readIntArrayFromEEPROM(STARTING_EEPROM_ADDRESS, newNumbers, ARRAY_SIZE);

  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    Serial.println(newNumbers[i]);
  }
}

void loop() {}
