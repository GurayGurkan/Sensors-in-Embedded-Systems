#include <SPI.h>

int CS_pin = 8;
word DAC = 0x0FFF; //4095

#define AB_bit 0x8000
#define BUFFER_EN 0x4000
#define GAIN 0x2000
#define OUTPUT_EN 0x1000
#define DATA_MASK 0x0FFF

void setup() {
  pinMode(CS_pin, OUTPUT);
  SPI.begin();
}

void loop()
{
  send16_DAC(DAC);
  DAC--;
}

void send16_DAC(word val12)
{
  word val16;
  byte HIGH_byte;
  val16 = GAIN | OUTPUT_EN | (val12 & DATA_MASK);
  HIGH_byte = (val16 >> 8 );
  digitalWrite(CS_pin, LOW);
  SPI.transfer(HIGH_byte);
  SPI.transfer((val16 & 0x00FF) );
  digitalWrite(CS_pin, HIGH);
}
