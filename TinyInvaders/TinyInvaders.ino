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

class Piece
{
  public:
  String title;
  byte chars[8];
  int posX, posY;
  int movX, movY;
  boolean hit = true;
  
  public:
  Piece() {};
  
  Piece(int pX, int pY, int mX, int mY) 
  {
    posX = pX;
    posY = pY;
    movX = mX;
    movY = mY;
  };  

  
};


// unbroken
byte block0_ba[] = {
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
byte block1_ba[] = {
  0B11111,
  0B10011,
  0B01111,
  0B00011,
  0B00011,
  0B00101,
  0B01001,
  0B11111
};

byte player_ba[] = {
  0B00110,
  0B00011,
  0B00111,
  0B01111,
  0B01111,
  0B00111,
  0B00011,
  0B00110
};

byte alien1_ba[] =
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

byte alien2_ba[] =
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

byte missle_ba[] =
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

byte explosion_ba[] = {
  0B10001,
  0B11001,
  0B01010,
  0B01110,
  0B11111,
  0B00110,
  0B01011,
  0B10001
};

Piece alien1, alien2, player, missle, block0, block1, explosion;

void setup() {
  Serial.begin(9600);
  LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

  lcd.begin(16, 2);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);

  memcpy(block0.chars, block0_ba, sizeof(block0_ba));
  lcd.createChar(0, block0.chars);
  memcpy(block0.chars, block0_ba, sizeof(block0_ba));

  memcpy(block1.chars,block1_ba, sizeof(block1_ba));
  lcd.createChar(1, block1.chars);
  memcpy(block1.chars, block1_ba, sizeof(block1_ba));

  lcd.setCursor(0,0);
  lcd.write(block0.getChars());
  
}


void loop() {

}

// custom characters for LCD screen
