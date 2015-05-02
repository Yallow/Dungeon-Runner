#include <stdio.h>
#include <stdlib.h>
#include "../dbg/dbg.h"
#include "dungeon.h"

item *create_item(char *item_name)
{
  item *new_item = calloc(1, sizeof(item));
  // name the item
  new_item->item_name = item_name;

  return new_item;
}

item *loot_item(char *item_name)
{
  // create a new duplicate item
  item *dup_item = create_item(item_name);

  printf("You have looted: %s\n", dup_item->item_name);

  return dup_item;
}

void destroy_item(item *item)
{
  free(item->item_name);
  free(item);
}
