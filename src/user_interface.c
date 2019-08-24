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
  0,0, 29,0, 39,0, 0,19, 29,19, 39,19, 0,24, 39,24,
  154, PEN_BRIGHT, 12,
  1,0, 9,0, 20,0, 28,0, 30,0, 38,0, 1,19, 28,19, 30,19, 38,19, 1,24, 38,24,
  149, PEN_BRIGHT, 10,
  0,1, 29,1, 39,1, 0,18, 0,20, 29,18, 39,18, 39,20, 0,23, 39,23,
  157, PEN_BRIGHT, 1, 10,0,
  151, PEN_BRIGHT, 1, 19,0,
  255, // End of single chars
  // Horizontal Lines
  154, PEN_NORMAL, true, 6, 2,0,7, 21,0,8, 31,0,7, 2,19,26, 31,19,7, 2,24,36,
  // Vertical Lines
  149, PEN_NORMAL, false, 5, 0,2,16, 29,2,16, 39,2,16, 0,21,2, 39,21,2,
  255,
};


const u8* DrawSingleChars ()
{
  u8 ch, color;
  u8 x,y;
  u8 reps;
  u8 n;
  const u8 *ptr;

  ptr = hud;
  while ( (ch = *ptr++) != 255) {
    color = *ptr++;
    reps = *ptr++;
    //pen(color);

    for (n=0; n<reps; ++n) {
      x = *ptr++;
      y = *ptr++;
      //locate (x,y);
      putchar_f (VMEM, x,y, ch, color, PEN_CLEAR);
    }
  }

  return ptr;

}

void DrawLine (u8 start, u8 other, u8 reps, u8 ch, u8 color, u8 is_hor)
{
  u8 x, y;

  //pen (color);
  for (u8 var=start; var!= start+reps; ++var) {
    if (is_hor) {
      x = var;
      y = other;
    }
    else {
      x = other;
      y = var;
    }
    //locate (x,y);
    putchar_f (VMEM, x,y, ch, color, PEN_CLEAR);
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

/*!
 * Draw the HUD decorations at the specified buffer
 *
 * \param pvmem_start Start address of video memory buffer to draw
 */
void DrawHUD (void *pvmem_start)
{
  void *pvdest;
  const u8 *hud_offset;

  pvdest = cpct_getScreenPtr (pvmem_start, 22,0);

  hud_offset = DrawSingleChars ();
  DrawLines (hud_offset);
  cpct_drawStringM1_f ("CPCRogue", pvdest, PEN_BRIGHT, PEN_CLEAR);
}

void DisplayLoading ()
{
  cpct_drawStringM1_f ("Loading...", VMEM_STATUS,
    PEN_MESSAGES, PEN_CLEAR);
}

/*
 * Clears the status message window  up to *nrows* rows.
 *
 * \param nrows Number of rows to clear
 */
void ClearStatus (u8 nrows)
{
  clrwin (VMEM_STATUS, STATUS_W, nrows, 0x00);
}
/*!
 * Displays the player's stats in the stats window (right panel). It
 * receives an *Entitty* parameter so, in theory, it could be used to
 * display any entity stats. But in the final game, only the player stats
 * is used when calling this fn.
 *
 *  \param e Entity to display *stats*. Usually it will be the player.
 *  \param TODO: Add drawing address so we can implement backbuffer
 */
void PrintStats (TEntity *e)
{
  // All drawing will be done relative to the STATS window start address
  u8 *pvmem = VMEM_STATS;

  cpct_drawStringM1_f (e->name, pvmem, PEN_NORMAL, PEN_CLEAR);
  pvmem += ONELINE; // Next line

  cpct_drawStringM1_f ("HP:", pvmem, PEN_NORMAL, PEN_CLEAR);
  pvmem += 6; // 3 chars to the right
  PrintU8 (pvmem, e->hp, PEN_BRIGHT, PEN_CLEAR);
  pvmem += 4; // 3 chars to the right
  cpct_drawStringM1_f ("/", pvmem, PEN_NORMAL, PEN_CLEAR);
  pvmem += 2; // 1 chars to the right
  PrintU8 (pvmem, e->max_hp, PEN_BRIGHT, PEN_CLEAR);

  pvmem += -12+ONELINE*2; // Next line
  cpct_drawStringM1_f ("STR:", pvmem, PEN_NORMAL, PEN_CLEAR);
  pvmem += 8;
  PrintU8 (pvmem, e->str, PEN_BRIGHT, PEN_CLEAR);

  pvmem += ONELINE-8; // Next line
  cpct_drawStringM1_f ("DES:", pvmem, PEN_NORMAL, PEN_CLEAR);
  pvmem += 8;
  PrintU8 (pvmem, e->des, PEN_BRIGHT, PEN_CLEAR);

  pvmem += ONELINE-8; // Next line
  cpct_drawStringM1_f ("REF:", pvmem, PEN_NORMAL, PEN_CLEAR);
  pvmem += 8;
  PrintU8 (pvmem, e->ref, PEN_BRIGHT, PEN_CLEAR);

  pvmem += ONELINE*2-8; // Two lines below
  cpct_drawStringM1_f ("ATK:", pvmem, PEN_NORMAL, PEN_CLEAR);
  pvmem += 8;
  PrintU8 (pvmem, e->atk, PEN_BRIGHT, PEN_CLEAR);

  pvmem += ONELINE-8;
  cpct_drawStringM1_f ("DEF:", pvmem, PEN_NORMAL, PEN_CLEAR);
  pvmem += 8;
  PrintU8 (pvmem, e->def, PEN_BRIGHT, PEN_CLEAR);
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
  if (draw_flags & CLEAR_ALL)     clrscr(VMEM, 0x0000);
  if (draw_flags & STATUS_MSG)    DisplayLoading ();
  if (draw_flags & DRAW_HUD)      DrawHUD (VMEM);
  if (draw_flags & DRAW_STATS)    PrintStats(player);
  if (draw_flags & CLEAR_STATUS)  ClearStatus(3);
  if (draw_flags & DRAW_MAP)      MapDraw (left, top,
    VIEW_WIDTH, VIEW_HEIGHT, player);

  OnScreen();
}