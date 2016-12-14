#include <SPI.h>

void setup()
{
  SPI.begin();
}

void loop()
{
  SPI.transfer(0x5A);
  delay(100);
}
