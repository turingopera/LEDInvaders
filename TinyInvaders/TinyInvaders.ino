/*
  Name:		Tiny_Invaders.ino
  Created:	12/10/2020 7:22:03 PM
  Author:	Richard deCosta

  Purpose:
*/

#include <LiquidCrystal.h>

// joystick
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

CustomChars chars;

void setup() {
  Serial.begin(9600);

  chars = new CustomChars();
}

void loop() {

}

class CustomChars
{

  // custom characters for LCD screen

// unbroken
byte block_b00[] = {
  0B11111,
  0B11011,
  0B10111,
  0B11111,
  0B11111,
  0B10101,
  0B11011,
  0B11111
};

// slightly broken
byte block_b01[] = {
  0B11111,
  0B10011,
  0B01111,
  0B00011,
  0B00011,
  0B00101,
  0B01001,
  0B11111
};

byte player01[] = {
  0B00110,
  0B00011,
  0B00111,
  0B01111,
  0B01111,
  0B00111,
  0B00011,
  0B00110
};

byte alien01[] =
{
  0B00001,
  0B01010,
  0B11110,
  0B01111,
  0B01111,
  0B11110,
  0B01010,
  0B00001
};

byte alien02[] =
{
  0B11100,
  0B11000,
  0B11110,
  0B01011,
  0B01011,
  0B11110,
  0B11000,
  0B11100
};

byte missle01[] =
{
  0B00000,
  0B00000,
  0B00000,
  0B00110,
  0B11111,
  0B00110,
  0B00000,
  0B00000
};
}
