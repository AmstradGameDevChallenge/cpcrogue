#include "cpctelera.h"
#include "fast_math.h"
#include "conio.h"

void TraceLine (u8 x1, u8 y1, u8 x2, u8 y2) //, u8 *coords)
{
  u8 dx, dy;
  i8 sx, sy;
  i8 error, error2;
  //u8* ptr = coords;

  dx = x2-x1;
  dy = y2-y1;
  sx = sign (dx);
  sy = sign (dy);
  dx = abs (dx);
  dy = abs (dy);
  error = dx-dy;


  while(1) {
    //*ptr++ = x1;
    //*ptr++ = y1;
    //locate (x1,y1);putchar('#');

    if (x1==x2 && y1==y2) {
      //*ptr=0xff;
      break;
    }

    error2 = error << 1;
    if (error2 > -dx) {
      error -= dy;
      x1 += sx;
    }
    if (error2 < (i8)dx) {
      error += dx;
      y1 += sy;
    }
  }
}