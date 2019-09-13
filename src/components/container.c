#include <cpctelera.h>
#include "consts.h"
#include "entity.h"
#include "container.h"


void init_container (struct TContainer *container) {
  cpct_memset (container, 0, sizeof(struct TContainer));
}

void append_to_container (
  struct TContainer *container, struct TEntity *entity) {

#ifdef DEBUG
  assert (container->num_items < MAX_INVENTORY_ITEMS-1);
#endif

  container->inventory[container->num_items++] = entity;
}

void remove_from_container (struct TContainer *container,
  struct TEntity *entity) {

  u8 i;
  bool found = false;

  for (i=0; i<container->num_items; ++i) {
    if (container->inventory[i] == entity) {
      found = true;
      break;
    }
  }
  if (found) {
    cpct_memcpy (&container->inventory[i],
      &container->inventory[container->num_items--], 2);
  }
}