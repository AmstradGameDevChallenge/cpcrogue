#include "input_handler.h"


/****************************************************************************
 *                            Handle Keyboard
 ***************************************************************************/
TAction HandleKeyboard (i8 *dx, i8 *dy)
{
  if (cpct_isKeyPressed (Key_I)) {  // i: UP
    *dx = 0; *dy = -1; return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_K)) {  // k: DOWN
    *dx = 0; *dy = 1; return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_J)) {  // j: LEFT
    *dx = -1; *dy = 0; return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_L)) {  // l: RIGHT
    *dx = 1; *dy = 0; return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_S)) {  // s: WAIT
    return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_N)) {  // s: WAIT
    return NEW_LEVEL;
  }
  return NONE;
}