/*
    ADXL345 Triple Axis Accelerometer. Simple Example.
    Read more: http://www.jarzebski.pl/arduino/czujniki-i-sensory/3-osiowy-akcelerometr-adxl345.html
    GIT: https://github.com/jarzebski/Arduino-ADXL345
    Web: http://www.jarzebski.pl
    (c) 2014 by Korneliusz Jarzebski
*/

#include <Wire.h>
#include <ADXL345.h>

ADXL345 accelerometer;
int CSpin=8;// To enable I2C mode

void setup(void) 
{
  Serial.begin(9600);
  pinMode(CSpin,OUTPUT);
  digitalWrite(CSpin,HIGH); //I2C enabled
  Serial.println("Initialize ADXL345");
  if (!accelerometer.begin())
  {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");
    delay(500);
  }

}

void loop(void) 
{
  // Read raw values
  Vector raw = accelerometer.readRaw();
  
  Serial.print(raw.XAxis); 
  Serial.print(", ");
  Serial.print(raw.YAxis);
  Serial.print(", ");
  Serial.println(raw.ZAxis); 
//  delay(100);
}
