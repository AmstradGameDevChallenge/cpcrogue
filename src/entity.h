#ifndef ENTITY_H
#define ENTITY_H
/****************************************************************************
 *                      ENTITY
 ***************************************************************************/


typedef struct {
  u8 x, y;      // Current position
  u8 px, py;    // Previous position
  u8 spr;       // ASCII char to draw this entity
  u8 color;     // Color to draw this entity
  u8 name[15];  // Name to display in messages
  u8 blocks;    // TRUE if blocks movement of another entity

  u16 max_hp;   // Max health
  u16 hp;       // Current health
  u8  str;      // Current strength
  u8  des;      // Current dexterity
  u8  ref;      // Current reflexes
  u16 atk;      // Current attack
  u16 def;      // Current defense
} TEntity;

extern TEntity *entities[];

void EntityInit (TEntity *c, u8 x, u8 y, u8 spr, u8 color, u8 name[],
  u8 blocks, u16 hp, u8 str, u8 destr, u8 refl);
void EntityMove (TEntity *c, i8 dx, i8 dy);
void EntityAttack (TEntity *e, TEntity *target);
u8 GetBlockingEntity (TEntity *entities[], TEntity **out_e, u8 x, u8 y);
void EntityDraw (TEntity *e, u8 left, u8 top);
void EntityDrawEntities(TEntity *entities[], u8 left, u8 top);
void EntityPrintStats (TEntity *e);

#endif