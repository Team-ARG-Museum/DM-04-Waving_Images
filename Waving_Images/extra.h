#ifndef EXTRA_H
#define EXTRA_H

#include "Arglib.h"

class Extra
{
  public:
    Extra(Arduboy &arduboy);

    void playBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, int16_t iCol, uint8_t color);

  private:

    Arduboy *arduboy;
    unsigned char *sBuffer;
};


#endif
