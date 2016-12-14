byte LEDpin = 13;
unsigned long ADCval;

void setup() {
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  digitalWrite(LEDpin, HIGH);
  ADCval = analogRead(A0);
  digitalWrite(LEDpin, LOW);
}
