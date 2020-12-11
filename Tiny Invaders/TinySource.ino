//www.elegoo.com
//2016.12.9


// include the library code:
#include <LiquidCrystal.h>

// joystick
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

int playerXPos = 15;
int playerYPos = 1;

int missleXPos = 14;
int missleYPos = 1;

int alien1XPos = 0;
int alien1YPos = 0;

int alien2XPos = 2;
int alien2YPos = 1;

int playerMissleX = 15;
int alienMissleX = 15;

int pos = 0;

int alien1 = 0;
int alien2 = 1;
int missle = 2;
int player = 3;
int block0 = 4;
int block1 = 5;


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

byte flipByte(byte c)
{
    c = ((c >> 1) & 0x55) | ((c << 1) & 0xAA);
    c = ((c >> 2) & 0x33) | ((c << 2) & 0xCC);
    c = (c >> 4) | (c << 4);

    return c;
}

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
    Serial.begin(9600);

    // custom chars
    lcd.createChar(alien1, alien01);
    lcd.createChar(alien2, alien02);
    lcd.createChar(missle, missle01);
    lcd.createChar(player, player01);
    lcd.createChar(block0, block_b00);
    lcd.createChar(block1, block_b01);
}

void loop() {

    Serial.println(digitalRead(2));
    if (digitalRead(2) == LOW)
    {
        //  Serial.println("FIRE!");
    }

    lcd.setCursor(missleXPos, missleYPos);
    lcd.write((char)missle);

    // defense block
    lcd.setCursor(14, 0);
    lcd.write((char)block0);

    lcd.setCursor(alien1XPos, alien1YPos);
    lcd.write(" ");
    alien1YPos = (alien1XPos == 0 ? 1 : 0);
    lcd.setCursor(alien1XPos, alien1YPos);
    lcd.write((char)alien1);

    //  disp(alien2, alien2XPos, alien2YPos);

    lcd.setCursor(alien2XPos, alien2YPos);
    lcd.write(" ");
    alien2YPos = (alien2XPos == 0 ? 1 : 0);
    lcd.setCursor(alien2XPos, alien2YPos);
    lcd.write((char)alien2);

    lcd.setCursor(playerXPos, playerYPos);
    playerYPos = map(analogRead(X_pin), 0, 1023, 0, 10);
    playerYPos = (playerYPos > 5) ? 1 : 0;

    lcd.write(" ");
    lcd.setCursor(playerXPos, playerYPos);
    lcd.write((char)player);

    // handle missles

    delay(150);
}