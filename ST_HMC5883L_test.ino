#include <Wire.h>
#include <HMC5883L.h>

HMC5883L compass;
unsigned long START;
void setup()
{
  Wire.begin(); 
  Serial.begin(9600);
  compass = HMC5883L();
  compass.SetMeasurementMode(Measurement_Continuous);
   
  //compass.SetBiasConfig(0);
  //compass.SetScale(1.3);
  START = millis();
}

void loop()
{
   if ((millis()- START)<4000)
   {
    MagnetometerRaw raw = compass.ReadRawAxis();
    
    Serial.print(raw.XAxis);
    Serial.print(",");
    Serial.print(raw.YAxis);
    Serial.print(",");
    Serial.println(raw.ZAxis);
   }
   delay(64);
}
