#include "user_interface.h"
#include "conio.h"


const u8 hud[122] = {
  // Single Chars
  233, PEN_BRIGHT, 8,
  1,1, 30,1, 40,1, 1,20, 30,20, 40,20, 1,25, 40,25,
  154, PEN_BRIGHT, 12,
  2,1, 10,1, 21,1, 29,1, 31,1, 39,1, 2,20, 29,20, 31,20, 39,20, 2,25, 39,25,
  149, PEN_BRIGHT, 10,
  1,2, 30,2, 40,2, 1,19, 1,21, 30,19, 40,19, 40,21, 1,24, 40,24,
  157, PEN_BRIGHT, 1, 11,1,
  151, PEN_BRIGHT, 1, 20,1,
  255,
  // Horizontal Lines
  154, PEN_NORMAL, TRUE, 6, 3,1,7, 22,1,8, 32,1,7, 3,20,26, 32,20,7, 3,25,36,
  // Vertical Lines
  149, PEN_NORMAL, FALSE, 5, 1,3,16, 30,3,16, 40,3,16, 1,22,2, 40,22,2,
  255,
};

/****************************************************************************
 *                      Draw the entire HUD decorations
 ***************************************************************************/

u8 DrawSingleChars ()
{
  u8 i;

  u8 ch, color;
  u8 x,y;
  u8 reps;

  i=0;
  while ( (ch = hud[i++]) != 255) {
    color = hud[i++];
    reps = hud[i++];
    pen(color);

    for (u8 n=0; n<reps; ++n) {
      x=hud[i++];
      y=hud[i++];
      locate (x,y);
      putchar (ch);
    }
  }
  return i;
}

void _DrawLine (u8 start, u8 other, u8 reps, u8 ch, u8 color, u8 is_hor)
{
  u8 x, y;

  pen (color);
  for (u8 var=start; var!= start+reps; ++var) {
    if (is_hor) {
      x = var;
      y = other;
    }
    else {
      x = other;
      y = var;
    }
    locate (x,y);
    putchar (ch);
  }
}
u8 _DrawLines (u8 idx)
{
  u8 x,y, ch, color;
  u8 i;
  u8 reps;
  u8 n_lines;
  u8 is_hor;

  i = idx;
  while ( (ch = hud[i++]) != 255) {
    color = hud[i++];
    is_hor = hud[i++];
    n_lines = hud[i++];
    for (u8 n_line=0; n_line < n_lines; ++n_line) {
      x = hud[i++];
      y = hud[i++];
      reps = hud[i++];
      if (is_hor)
        _DrawLine (x, y, reps, ch, color, is_hor);
      else
        _DrawLine (y, x, reps, ch, color, is_hor);
    }
  }
  return i;
}

void DrawHUD ()
{
  u8 i=0;

  i = DrawSingleChars ();
  i = _DrawLines (i);
  PrintAt (12,1, "CPCRogue", PEN_BRIGHT);
}

void DisplayLoading ()
{
  ink (1, 20, 14);
  PrintAt (LOADING_X,LOADING_Y, "Loading...", 1);
}
void ClearStatus (u8 start_line, u8 nlines)
{
  for (u8 n=0; n<nlines; ++n) {
    PrintAt (STATUS_X, STATUS_Y+n,
      "                                      ",
      PEN_NORMAL);
  }
}
/****************************************************************************
 *                      Display Entity Stats
 ***************************************************************************/
void PrintStats (TEntity *e)
{
  u8 x, y;

  x = STATS_X;
  y = STATS_Y;

  PrintAt (x,y, e->name, PEN_NORMAL); ++y;
  PrintAt (x, y, "HP:      ", PEN_NORMAL); PrintU8 (e->hp,    x+3,y, PEN_BRIGHT);
  PrintAt (x+5, y, "/", PEN_NORMAL); PrintU8 (e->max_hp,x+6,y++, PEN_BRIGHT);
  ++y;
  PrintAt (x, y, "STR:",PEN_NORMAL); PrintU8 (e->str,   x+4,y++, PEN_BRIGHT);
  PrintAt (x, y, "DES:",PEN_NORMAL); PrintU8 (e->des,   x+4,y++, PEN_BRIGHT);
  PrintAt (x, y, "REF:",PEN_NORMAL); PrintU8 (e->ref,   x+4,y++, PEN_BRIGHT);

  ++y;
  PrintAt (x, y, "ATK:",PEN_NORMAL); PrintU8 (e->atk,   x+4,y++, PEN_BRIGHT);
  PrintAt (x, y, "DEF:",PEN_NORMAL); PrintU8 (e->def,   x+4,y++, PEN_BRIGHT);
}
