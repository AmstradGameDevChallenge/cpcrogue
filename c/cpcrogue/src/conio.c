#include <stdio.h>
#include "conio.h"

/****************************************************************************
 * Video fn: LOCATE, INK, PAPER, BORDER, PEN, CLS
 ***************************************************************************/
void locate (u8 x, u8 y)
{
   putchar(US);
   putchar (x); putchar (y);
}
void ink (u8 tinta, u8 color1, u8 color2)
{
   putchar (FS);
   putchar (tinta); putchar (color1); putchar (color2);
}

void paper (u8 color1)
{
   putchar (SO);
   putchar (color1);
}
void pen (u8 tinta)
{
   putchar (SI);
   putchar (tinta);
}
/****************************************************************************
 *                      PrintAt
 ***************************************************************************/
void PrintAt (u8 x, u8 y, char text[], u8 color)
{
  u8 i = 0, ch;

  locate (x, y);
  if (color != 0xff) pen (color);
  while ( (ch=text[i++]) )
    putchar(ch);

}
/****************************************************************************
 *                      PrintU8
 ***************************************************************************/
void PrintU8 (u8 num, u8 x, u8 y, u8 color)
{
  u8 str[4];
  sprintf (str, "%d", num);
  PrintAt (x,y, str, color);
}

void BlackScreen()
{
  ink (0, INK_BG,INK_BG);
  ink (1, INK_BG,INK_BG);
  ink (2, INK_BG,INK_BG);
  ink (3, INK_BG,INK_BG);

  border (0); paper (0);
}