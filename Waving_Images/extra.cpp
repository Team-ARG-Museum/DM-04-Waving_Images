#include "extra.h"

Extra::Extra(Arduboy &a)
{
  arduboy = &a;
  sBuffer = arduboy->getBuffer();
}

void Extra::playBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, int16_t iCol, uint8_t color) {
  if (x + w < 0 || x > WIDTH - 1 || y + h < 0 || y > HEIGHT - 1)
    return;
  int yOffset = abs(y) % 8;
  int sRow = y / 8;
  if (y < 0) {
    sRow--;
    yOffset = 8 - yOffset;
  }
  int rows = h / 8;
  if (h % 8 != 0) rows++;
  for (int a = 0; a < rows; a++) {
    int bRow = sRow + a;
    if (bRow > (HEIGHT / 8) - 1) break;
    if (bRow > -2) {
      if (iCol + x > (WIDTH - 1)) break;
      if (iCol + x >= 0) {
        if (bRow >= 0) {
          if (color) this->sBuffer[ (bRow * WIDTH) + x + iCol ]  |= pgm_read_byte(bitmap + (a * w) + iCol) << yOffset;
          else this->sBuffer[ (bRow * WIDTH) + x + iCol ]  &= ~(pgm_read_byte(bitmap + (a * w) + iCol) << yOffset);
        }
        if (yOffset && bRow < (HEIGHT / 8) - 1 && bRow > -2) {
          if (color) this->sBuffer[ ((bRow + 1)*WIDTH) + x + iCol ] |= pgm_read_byte(bitmap + (a * w) + iCol) >> (8 - yOffset);
          else this->sBuffer[ ((bRow + 1)*WIDTH) + x + iCol ] &= ~(pgm_read_byte(bitmap + (a * w) + iCol) >> (8 - yOffset));
        }
      }
    }
  }
}
