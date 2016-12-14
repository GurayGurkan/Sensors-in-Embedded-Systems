/*   ASCII table
 Prints out byte values in all possible formats:
 * as raw binary values
 * as ASCII-encoded decimal, hex, octal, and binary values  */
void setup() {
  Serial.begin(9600);
  Serial.println("ASCII Table ~ Character Map");
}

int thisByte = 33;

void loop() {
  Serial.write(thisByte);
  Serial.print(", dec: ");
  Serial.print(thisByte);
  Serial.print(", hex: ");
  Serial.print(thisByte, HEX);
  Serial.print(", oct: ");
  Serial.print(thisByte, OCT);
  Serial.print(", bin: ");
  Serial.println(thisByte, BIN);
  if (thisByte == 126) {    // you could also use if (thisByte == '~') {
    while (true) {
      continue;  }
  }
  thisByte++;
}
