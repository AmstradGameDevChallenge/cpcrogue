#include <stdio.h>
#include <string.h>
#include "logo.h"
#include "entity.h"
#include "constants.h"
#include "conio.h"


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
  strcpy (e->name, name);
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
void EntityDraw (struct TEntity *e, u8 erase)
{
  u8 x, y, color, spr;
  if (erase) {
    x = e->px;
    y = e->py;
    color = PEN_TILE;
    spr = SPR_FLOOR;
  }
  else {
    x = e->x;
    y = e->y;
    color = e->color;
    spr = e->spr;
  }
  pen (color);
  locate (PLAY_X+x, PLAY_Y+y);
  putchar (spr);
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
  PrintAt (1,23, e->name, 1);
  PrintAt (8,23, "takes     ", 2);
  PrintU8 (dmg, 14,23, 1);
  PrintAt (17,23, "points of damage", 2);
}
/****************************************************************************
 *                      Attack 'target'
 ***************************************************************************/
void EntityAttack (TEntity *e, TEntity *target)
{
  u8 dmg;
  // Show action in log window
  PrintAt (1,22, e->name, 1);
  PrintAt (10,22, "attacks", 2);
  PrintAt (23,22, target->name, 1);

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
      return TRUE;
    }
  }
  return FALSE;
}
/****************************************************************************
 *                      Draw all entities in array
 ***************************************************************************/
void EntityDrawEntities (TEntity *entities[], u8 dirty[])
{
  TEntity *e;
  u8 i=0;
  while ( (e=entities[i]) ) {
    if (dirty[i]) {
      EntityDraw (e, TRUE);
      dirty[i] = FALSE;
    }
    EntityDraw (e, FALSE);
    ++i;
  }
}
/****************************************************************************
 *                      Display Entity Stats
 ***************************************************************************/
void EntityPrintStats (TEntity *e)
{
  u8 pen1, pen2;
  u8 x, y;

  x = 30;
  y = 4;
  pen1 = 1; pen2 = 2;
  PrintAt (1,1, "i:UP, k:DN, j:LT, l:RT, s:WAIT", pen2);
  PrintAt (x,y, e->name, pen1); ++y;
  PrintAt (x, y, "HP:      ", pen1); PrintU8 (e->hp,    x+3,y, pen2);
  PrintAt (x+5, y, "/", pen1); PrintU8 (e->max_hp,x+6,y++, pen2);
  ++y;
  PrintAt (x, y, "STR:",pen1); PrintU8 (e->str,   x+4,y++, pen2);
  PrintAt (x, y, "DES:",pen1); PrintU8 (e->des,   x+4,y++, pen2);
  PrintAt (x, y, "REF:",pen1); PrintU8 (e->ref,   x+4,y++, pen2);

  ++y;
  PrintAt (x, y, "ATK:",pen1); PrintU8 (e->atk,   x+4,y++, pen2);
  PrintAt (x, y, "DEF:",pen1); PrintU8 (e->def,   x+4,y++, pen2);
}
