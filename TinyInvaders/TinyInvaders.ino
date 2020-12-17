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
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int m = 120; // delay between loops
int activeMissle = 0;

class Piece
{
  public:
  int ID;
  String name;
  byte chars[8];
  int posX, posY;
  int movX, movY;
  boolean hit = false;
  boolean alive = true;
  int hitPoints = 1;
    
  public:
  Piece() {};

  public:
  Piece(String n, int id, int pX, int pY, int mX, int mY) 
  {
    name = n;
    ID = id;
    posX = pX;
    posY = pY;
    movX = mX;
    movY = mY;
  };

  public:
  void kill()
  {
    
    alive = false;
  }
  
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
  0B01111,
  0B00110,
  0B00000,
  0B00000
};

byte explosion_ba[] = {
  0B00000,
  0B01001,
  0B01010,
  0B01110,
  0B10111,
  0B00110,
  0B01010,
  0B00000
};

Piece  player, block, explosion;
Piece missles [3];
Piece aliens [2];

void setup() {
  Serial.begin(9600);  
  lcd.begin(16, 2);
  // init joystick
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);


  int len = sizeof(aliens)/sizeof(aliens[0]);
  
  // init game objects
  // Piece(int id, int pX, int pY, int mX, int mY) 
  for (int m = 0; m < len; m++)
    {
      aliens[m]    = Piece("alien", 0, 0, 0, 0, 0);
    }
  
  player    = Piece("player", 2, 15, 1, 0, 0);
  block    = Piece("block", 4, 14, 0, 0, 0);  
  explosion = Piece("explosion", 6, 0, 0, 0, 0);
  
  len = sizeof(missles)/sizeof(missles[0]);
  for (int mm = 0; mm < len; mm++)
  {
    missles[mm] = Piece("missle", 3, player.posX-1, player.posY, -1, 0);
  }
  
  // init custom LCD characters
  //lcd.createChar(alien1.ID, alien1_ba);
  //lcd.createChar(alien2.ID, alien2_ba);
  lcd.createChar(player.ID, player_ba);
  lcd.createChar(missles[activeMissle].ID, missle_ba);
  lcd.createChar(block.ID, block0_ba);
  lcd.createChar(block.ID, block1_ba);
  lcd.createChar(explosion.ID, explosion_ba);

}



void loop() {
  //updatePieces();

  int len = sizeof(aliens)/sizeof(aliens[0]);
    for (int m = 0; m < len; m++)
    {
      lcdWrite(aliens[m]);
    }

  len = sizeof(aliens)/sizeof(aliens[0]);
    for (int m = 0; m < len; m++)
    {
      lcdWrite(missles[m]);
    }
  
    lcdWrite(player);
    lcdWrite(block);
    
    delay(m); // what value?
}

void lcdWrite(Piece p)
{
  lcd.setCursor(p.posX+1, p.posY);
  lcd.write(" ");
    
  if (p.alive)
  {  
    lcd.setCursor(p.posX, p.posY);
    lcd.write(p.ID);
  } 
}

void updatePieces()
{
  if (missles[activeMissle].alive)
  {
    if (missles[activeMissle].posX < 0) missles[activeMissle].kill();

    for (int m = 0; m < sizeof(missles); m++)
    {
    // collision check (player, aliens, barrier)
      for (int a = 0; a < sizeof(aliens); a++)
      {
        posMatch(missles[m], aliens[a]);
      }
      posMatch(missles[m], player);
      posMatch(missles[m], block);
    }
  }

  // movement
  missles[activeMissle].posX += missles[activeMissle].movX;
}

// alien1, alien2, player, missle, block0, block1, explosion
void posMatch(Piece p1, Piece p2)
{
  if (p1.posX == p2.posX
  &&
  p1.posY == p2.posY)
  {
    // kill
    // spawn explosion
    // play sound
    // pause
    // remove explosion
  }

}

void fire(Piece p)
{
  missles[nextMissle()].alive = true;
  
  missles[activeMissle].posY = p.posY;
  if (p.name == "player")
  {
    missles[activeMissle].posX = p.posX-1;  
  } else if (p.name == "alien1" || p.name == "alien2")
  {
    missles[activeMissle].posX = p.posX+1;
    
  }
}

int nextMissle()
{
  return ++activeMissle;
}
