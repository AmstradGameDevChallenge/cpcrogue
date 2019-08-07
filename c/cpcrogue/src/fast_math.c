#include "fast_math.h"


u16 manh_distance_to (u8 x1, u8 y1, u8 x2, u8 y2)
{
  i8 dx, dy;

  dx = x2 - x1;
  dy = y2 - y1;

  dx = abs (dx);
  dy = abs (dy);

  return (dx + dy);
}