#include <cpctelera.h>
#include <stdbool.h>
#include "constants.h"
#include "entity.h"
#include "game_map.h"


void NewGame (TEntity *player, TEntity *enemy)
{
  EntityInit (player, 0, 0, SPR_PLAYER, PEN_BRIGHT, "Thorbag", true,
    20, 17, 14, 12);
  EntityInit (enemy, 19, 3, SPR_GOBLIN, PEN_ENTITY, "Goblin", true,
    10, 12, 13, 11);
  entities[0] = player;
  entities[1] = enemy;

  MapCreate (MAP_WIDTH, MAP_HEIGHT, player);
}


