#include <stdio.h>
#include "cpctelera.h"
#include "constants.h"

void locate (u8 x, u8 y);
void ink (u8 tinta, u8 color1, u8 color2);
inline void border (u8 color1)
{
  putchar (GS);
  putchar (color1); putchar (color1);
}
void paper (u8 color1);
void pen (u8 tinta);
inline void cls () { putchar (FF); }

void PrintAt (u8 x, u8 y, u8 text[], u8 color);
void PrintU8 (u8 num, u8 x, u8 y, u8 color);