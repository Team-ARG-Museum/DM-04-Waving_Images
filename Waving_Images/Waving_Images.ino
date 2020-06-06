
/*
  DEMO: Waving Images

  TEAM a.r.g.: http://www.team-arg.com/demos.html

  2015 - JO3RI

  Demo License: MIT : https://opensource.org/licenses/MIT

*/

#include "Arglib.h"
#include "bitmaps.h"
#include "extra.h"


Arduboy arduboy;
Extra extra (arduboy);

byte a = 0;
float b = 4.7;
char sinus[128];

void setup()
{
  arduboy.start();
  arduboy.clearDisplay();
  arduboy.display();
  arduboy.drawBitmap(0, 8, TEAMarg, 128, 48, 1);
  arduboy.display();
  delay(3000);
}

void loop()
{
  while (millis() < 8000) {
    wave(jack, 96, 48, 16, 8, 2, 0.2);
    arduboy.display();
  }
  while (millis() < 13000) {
    wave(nyan, 123, 53, 0, 8, 3, 0.1);
    arduboy.display();
  }
  while (millis() < 18000) {
    wave(boma, 60, 60, 32, 2, 2, 0.1);
  }
  while (millis() < 23000) {
    wave(mono, 69, 58, 29, 3, 2, 0.1);
  }

  wave(TEAMarg, 128, 48, 0, 8, 2, 0.1);
  arduboy.display();
}

void wave(const uint8_t *bitmap, uint16_t w, uint16_t h, uint16_t x, uint16_t y, uint16_t amp, float wl)
{
  arduboy.clearDisplay();
  for (int j = 0; j < w; j++) {
    sinus[j] = y + (amp * sin(b + (j * wl)));
  }
  for (int i = 0; i < w; i++)
  {
    extra.playBitmap(x, sinus[a], bitmap, w, h, i, 1);
    a++;
    if (a > w - 1) a = 0;
  }
  b += 0.1;
  arduboy.display();
}
