#include <SPI.h>

/*
 * MCP4921 SPI DAC response test:
 * The code is written such that MCP4921 will generate maximum and minimum analog values possible. 
 * For Gain=1, the corresponding DAC input values are 0x0FFF and 0x0000.
 * If AREF = +5V is applied, the below figure is obtained at Vout pin of DAC. 
 * The response time can be measured as 10 us.
 * 
 *        ___         ___
 *       /   \       /   \
 *      /     \     /     \
 *    _/       \___/       \___
 *           | |
 *      response time
 *      
 * Author: Guray Gurkan
 * 01.12.2016
 *
 */
int CS_pin = 8;
const word maxDAC = 0x0FFF; //4095
const word minDAC = 0;

#define AB_bit 0x8000
#define BUFFER_EN 0x4000
#define GAIN 0x2000
#define OUTPUT_EN 0x1000
#define DATA_MASK 0x0FFF

void setup() {
  pinMode(CS_pin, OUTPUT);
  SPI.begin();
}

void loop() {
  send16_DAC(maxDAC);
  send16_DAC(minDAC);
  send16_DAC(maxDAC);
  send16_DAC(minDAC);
  delayMicroseconds(400);
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
