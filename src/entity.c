#include <cpctelera.h>
#include <stdio.h>
#include <stdbool.h>
//#include <string.h>
#include "logo.h"
#include "entity.h"
#include "constants.h"
#include "conio.h"


// List of entities in our game
TEntity *entities[MAX_ENTITIES];  // List of entities in game
/****************************************************************************
 *               Create en entity with given values
 ***************************************************************************/
void EntityInit (TEntity *e, u8 x, u8 y, u8 spr, u8 color, u8 name[],
  u8 blocks, u16 hp, u8 str, u8 destr, u8 refl)
{
  e->x = e->px = x;  // current posX
  e->y = e->py = y;  // current posY
  e->spr =spr;
  e->color = color;
  cpct_memcpy (e->name, name, 15);
  e->blocks = blocks;

  e->max_hp = hp;
  e->hp = hp;
  e->str = str;
  e->des = destr;
  e->ref = refl;

  e->atk = (str  + destr)>>1;
  e->def = (destr + refl)>>1;
}
/****************************************************************************
 *                    Draw/Erase a single entity
 ***************************************************************************/
void EntityDraw (TEntity *e, u8 left, u8 top)
{
  u8 x, y, color, spr;
  x = e->x - left;
  y = e->y - top;
  color = e->color;
  spr = e->spr;

  if (x > 127 || x > VIEW_WIDTH-1 || y > 127 || y > VIEW_HEIGHT-1) return;
  putchar_f (VMEM_MAP, x,y, spr, color, PEN_CLEAR);
}
/****************************************************************************
 *                      Move entity to new position
 ***************************************************************************/
void EntityMove (TEntity *e, i8 dx, i8 dy)
{
  e->px = e->x;     // Save old positions
  e->py = e->y;
  e->x  = e->x+dx;   // Update to new position
  e->y  = e->y+dy;
}
/****************************************************************************
 *           Get Damage points from entity stats
 ***************************************************************************/
u8 EntityCalculateDamage (TEntity *e)
{
  u8 dmg = e->atk >> 2;
  u8 r = (cpct_rand() * 7/255) - 3;
  dmg += r;
  return (dmg < 127 ? dmg : dmg+3);
}
/****************************************************************************
 *           Take dmg points of damage
 ***************************************************************************/
void EntityTakeDamage (TEntity *e, u8 dmg)
{
  e->hp -= dmg;
  /*
  PrintAt (STATUS_X,STATUS_Y+1, e->name, PEN_BRIGHT);
  PrintAt (STATUS_X+7,STATUS_Y+1, "takes     ", PEN_NORMAL);
  PrintU8 (dmg, STATUS_X+13,STATUS_Y+1, PEN_BRIGHT);
  PrintAt (STATUS_X+16,STATUS_Y+1, "points of damage", PEN_NORMAL);
  */
}
/****************************************************************************
 *                      Attack 'target'
 ***************************************************************************/
void EntityAttack (TEntity *e, TEntity *target)
{
  u8 dmg;
  // Show action in log window
/*
  PrintAt (STATUS_X,STATUS_Y, e->name, PEN_BRIGHT);
  PrintAt (STATUS_X+8,STATUS_Y, "attacks", PEN_NORMAL);
  PrintAt (STATUS_X+16,STATUS_Y, target->name, PEN_BRIGHT);
  */

  dmg = EntityCalculateDamage (e);
  EntityTakeDamage (target, dmg);
}
/****************************************************************************
 *           Get first blocking entity at given position
 ***************************************************************************/
u8 GetBlockingEntity (TEntity *entities[], TEntity **out_e, u8 x, u8 y)
{
  TEntity *e;
  u8 j = 22;

  while ( (e=*entities++) != NULL) {
    if (e->blocks && e->x == x && e->y == y) {
      *out_e = e;
      return true;
    }
  }
  return false;
}
/****************************************************************************
 *                      Draw all entities in array
 ***************************************************************************/
void EntityDrawEntities (TEntity *entities[], u8 left, u8 top)
{
  TEntity *e;
  u8 i=0;
  while ( (e=entities[i]) ) {
    EntityDraw (e, left, top);
    ++i;
  }
}