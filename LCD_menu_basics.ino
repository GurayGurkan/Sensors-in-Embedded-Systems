/*
 * LCD Menu for multiple pin control
 * 
 * The output states of 3 digital pins can be controlled via two buttons 
 * named "Select" and "Adjust" connected to pin 8 and 9, respectively.
 * The string array can be modified to name connected devices.
 * Pins 2 to 7 are adjusted for LCD connection.
 * 
 * Author: Guray Gurkan
 * Nov 2016
 * g.gurkan@iku.edu.tr
 */
 
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //RS, EN, D4-D7

int led_pins[] = {11, 12, 13};
bool states[] = {false, false, false};
byte current = 0;
String names[] = {"LED1", "LED2", "LED3"};


void setup() {
  lcd.begin(16, 2);
  pinMode(8, INPUT_PULLUP); //LED SELECT
  pinMode(9, INPUT_PULLUP); // STATE SELECT
  pinMode(led_pins[0], OUTPUT); // LED1
  pinMode(led_pins[1], OUTPUT); // LED2
  pinMode(led_pins[2], OUTPUT); // LED3
  display_menu(states, 0);
}

void loop() {
  if (!digitalRead(8)) // Led SELECT
  {
    current++;
    current %= 3;
    display_menu(states, current);
  }

  if (!digitalRead(9)) // Led STATE toggle
  {
    states[current] = !states[current];
    digitalWrite(led_pins[current], states[current]);
    display_menu(states, current);
  }
  delay(200);
}

void display_menu(bool arg_states[], int current)
{
  lcd.clear();
  put_marker(current);
  lcd.setCursor(1, 0);
  lcd.print(names[0]);
  lcd.setCursor(6, 0);
  lcd.print(names[1]);
  lcd.setCursor(11, 0);
  lcd.print(names[2]);
  lcd.setCursor(2, 1);
  if (arg_states[0])
    lcd.print(" ON");
  else
    lcd.print("OFF");
  lcd.setCursor(7, 1);
  if (arg_states[1])
    lcd.print(" ON");
  else
    lcd.print("OFF");
  lcd.setCursor(12, 1);
  if (arg_states[2])
    lcd.print(" ON");
  else
    lcd.print("OFF");
}

void put_marker(int c)
{
  if (c == 0)
    lcd.setCursor(1, 1);
  if (c == 1)
    lcd.setCursor(6, 1);
  if (c == 2)
    lcd.setCursor(11, 1);
  lcd.write(0x3E); // ">" symbol for cursor
}

