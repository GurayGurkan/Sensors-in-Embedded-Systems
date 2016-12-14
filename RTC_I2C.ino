/* DS3231 Real Time Clock Chip: I2C protocol
 *
 * Converts the received data to String and sends to Serial Monitor
 *
 * Author: Guray Gurkan
 * 12 Dec, 2016
 *
 * To do:
 * 1) Set Time
 * 2) Set Alarms
 */
#include <Wire.h>

#define ADDR 0x68

char output[512];

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Serial.println(ReadRTC());
  delay(1000);

}

String ReadRTC()
{
  String  temp;
  Wire.beginTransmission(ADDR);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(ADDR);
  Wire.requestFrom(ADDR, 7);

  int i = 0;
  byte values[7];
  while (Wire.available()) {
    values[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();

  int ones, tens;
  for (int d = 6; d > -1 ; d--)
  {
    ones = 0;
    tens = 0;
    if (d == 6) //Year
    {
      ones = values[d] & 0x0F;
      tens = (values[d] & 0x10) >> 4;
      if (tens == 0)
        temp.concat("0");
      temp.concat(ones + 10 * tens);
      temp.concat("/");
    }
    else if (d == 0) //seconds
    {
      ones = values[d] & 0x0F;
      tens = (values[d] & 0xF0) >> 4;
      if (tens == 0)
        temp.concat("0");
      temp.concat(ones + 10 * tens);

    }
    else if (d == 1) //minutes
    {
      ones = values[d] & 0x0F;
      tens = (values[d] & 0xF0) >> 4;
      if (tens == 0)
        temp.concat("0");

      temp.concat(ones + 10 * tens);
      temp.concat(":");
    }
    else if (d == 2) //Hours
    {
      ones = values[d] & 0x0F;
      if ((values[d] & 0x40) == 0x40) // 12 Hour
      {
        tens = (values[d] & 0x10) >> 4;
        if (tens == 0)
          temp.concat("0");
        temp.concat(ones + 10 * tens);
        temp.concat(":");
      }
      else //24 Hour
      {
        if ((values[d] & 0x10) == 0x10)
          tens = (values[d] & 0x10) >> 4;
        if ((values[d] & 0x20) == 0x20)
          tens = (values[d] & 0x10) >> 4;
        if (tens == 0)
          temp.concat("0");
        temp.concat(ones + 10 * tens);
        temp.concat(":");
      }
    }
    if (d == 4) //Date
    {
      ones = values[d] & 0x0F;
      tens = (values[d] & 0x30) >> 4;
      if (tens == 0)
        temp.concat("0");

      temp.concat(ones + 10 * tens);
      temp.concat("  ");
    }

    else if (d == 5) //Months
    {
      ones = values[d] & 0x0F;
      tens = (values[d] & 0x10) >> 4;
      if (tens == 0)
        temp.concat("0");

      temp.concat(ones + 10 * tens);
      temp.concat("/");
    }


  }
  return (temp);
}


