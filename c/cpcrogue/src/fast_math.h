//#ifndef FAST_MATH_H
//#define FAST_MATH_H

#include "cpctelera.h"


inline u8 clamp (u8 value, u8 min, u8 max)
{
  return (value > max) ? max :
    (value < min) ? min : value;
}
inline u8 min (u8 a, u8 b)
{
  return (a < b) ? a : b;
}
inline u8 max (u8 a, u8 b)
{
  return (a > b) ? a : b;
}

inline u8 abs (i8 value)
{
  return value < 0 ? -value : value;
}
inline i8 sign (i8 value)
{
  return value < 0 ? -1 : 1;
}

u8 rand_range (u8 min, u8 max);

u16 manh_distance_to (u8 x1, u8 y1, u8 x2, u8 y2);


//#endif