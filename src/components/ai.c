#include <cpctelera.h>
#include <stdbool.h>
#include <stdio.h>
#include "ai.h"
#include "consts.h"
#include "entity.h"

#ifdef DEBUG
  #include <assert.h>
#endif

struct TAI ai_components[MAX_AI_COMPONENTS];
u8 num_ai_components;

//---------------------------------------------------------------------------
void init_ai() {
  cpct_memset (ai_components, 0x00, sizeof (ai_components));
  num_ai_components = 0;
}

//---------------------------------------------------------------------------
struct TAI *basic_ai_create ()
{
  struct TAI *ai = NULL;

  if (num_ai_components < MAX_AI_COMPONENTS)
  {

#ifdef DEBUG
    assert (num_ai_components < MAX_AI_COMPONENTS);
#endif
    // Get an empty slot from the ai array
    ai = &ai_components[num_ai_components++];

    // Set the AI TakeTurn function
    ai->take_turn = basic_ai_take_turn;

    // Return the ai ptr as our new allocated ai
  }

#ifdef DEBUG
    assert (ai);
#endif

  return ai;

}
//---------------------------------------------------------------------------
void basic_ai_take_turn (struct TAI *ai)
{
  i8 dx, dy;
  u8 rnd_val = cpct_rand();
  if (rnd_val < 128)
    dx = -1;
  else if (rnd_val > 140)
    dx = 1;
  else
    dx = 0;

  rnd_val = cpct_rand();
  if (rnd_val < 128)
    dy = -1;
  else if (rnd_val > 140)
    dy = 1;
  else
    dy = 0;

  entity_move (ai->owner, dx, dy);
}