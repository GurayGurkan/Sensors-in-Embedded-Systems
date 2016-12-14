int pin1 = 13;

unsigned long duration = 1000;

void setup() {
 pinMode(pin1, OUTPUT);
 blinker(pin1, 20, 20, 260);
}

void loop()
{
  
  
}

void blinker(int pin, unsigned long T_ON, unsigned long T_OFF,
             byte repeats)
{
  for (int c = 0; c < repeats; c++)
  {
    digitalWrite(pin, HIGH);
    delay(T_ON);
    digitalWrite(pin, LOW);
    delay(T_OFF);
  }
}
