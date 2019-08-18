#include <cpctelera.h>
#include <stdio.h>
#include <stdbool.h>
#include "constants.h"
#include "conio.h"
#include "game_map.h"
#include "entity.h"
#include "user_interface.h"

/*!
 * \ingroup user_interface
 * \hideinitializer
 *
 * \brief HUD data, in a custom coded format to reduce memmory size.
 *
 * The HUD data is just an array of bytes, arranged in a custom format:
 *  - TODO:
 */
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
  154, PEN_NORMAL, true, 6, 3,1,7, 22,1,8, 32,1,7, 3,20,26, 32,20,7, 3,25,36,
  // Vertical Lines
  149, PEN_NORMAL, false, 5, 1,3,16, 30,3,16, 40,3,16, 1,22,2, 40,22,2,
  255,
};


const u8* DrawSingleChars ()
{
  u8 ch, color;
  u8 x,y;
  u8 reps;
  const u8 *ptr;

  ptr = hud;
  while ( (ch = *ptr++) != 255) {
    color = *ptr++;
    reps = *ptr++;
    pen(color);

    for (u8 n=0; n<reps; ++n) {
      x=*ptr++;
      y=*ptr++;

      locate (x,y);
      putchar (ch);
    }
  }

  return ptr;

}

void DrawLine (u8 start, u8 other, u8 reps, u8 ch, u8 color, u8 is_hor)
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
const u8 *DrawLines (const u8 *hud_offset)
{

  u8 x,y, ch, color;
  u8 reps;
  u8 n_lines;
  u8 is_hor;

  const u8 *ptr;

  ptr = hud_offset;

  while ( (ch = *ptr++) != 255) {
    color = *ptr++;
    is_hor = *ptr++;
    n_lines = *ptr++;
    for (u8 n_line=0; n_line < n_lines; ++n_line) {
      x = *ptr++;
      y = *ptr++;
      reps = *ptr++;
      if (is_hor)
        DrawLine (x, y, reps, ch, color, is_hor);
      else
        DrawLine (y, x, reps, ch, color, is_hor);
    }
  }
  return ptr;

}

void DrawHUD ()
{
  const u8 *hud_offset;

  hud_offset = DrawSingleChars ();
  DrawLines (hud_offset);
  PrintAt (12,1, "CPCRogue", PEN_BRIGHT);
}

void DisplayLoading ()
{
  ink (1, 20, 14);
  PrintAt (LOADING_X,LOADING_Y, "Loading...", 1);
}

/*
 * Clears the status message window from *start_line* up to *nlines* lines.
 */
void ClearStatus (u8 start_line, u8 nlines)
{
  for (u8 n=0; n<nlines; ++n) {
    PrintAt (STATUS_X, start_line+n,
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

  x = 31;
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

/*!
 *
 * This function selectively calls other drawing functions to draw
 * different visible aspects of the game. What to draw is selected from a
 * set of flags in *draw_flags*. The flags can request additional actions
 * like clearing the screen, or showing a message at the status
 * line.
 *
 * \param player Player info needed when drawing the *stats*
 * \param left,top Top/left tile from the game map subregion to draw
 * \param draw_flags Bitmask to select what to draw and extra actions to do.
 */
void DrawGame (TEntity *player, u8 left, u8 top, u8 draw_flags)
{
  OffScreen ();
  if (draw_flags & CLEAR_ALL)     cls();
  if (draw_flags & STATUS_MSG)    DisplayLoading ();
  if (draw_flags & DRAW_HUD)      DrawHUD ();
  if (draw_flags & DRAW_STATS)    PrintStats(player);
  if (draw_flags & CLEAR_STATUS)  ClearStatus(LOADING_Y, 1);
  if (draw_flags & DRAW_MAP)      MapDraw (left, top,
    VIEW_WIDTH, VIEW_HEIGHT, player);

  OnScreen();
}