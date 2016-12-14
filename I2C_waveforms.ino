#include <Wire.h>

void setup(
{
  Wire.begin();
}

void loop()
{
  Wire.beginTransmission(0x35);
  Wire.endTransmission();
  delay(100);
}

