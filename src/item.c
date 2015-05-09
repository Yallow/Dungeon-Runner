#include <stdio.h>
#include <stdlib.h>
#include "../dbg/dbg.h"
#include "dungeon.h"

item *create_item(char *item_name, char *item_type, int item_stats)
{
  item *new_item = calloc(1, sizeof(item));
  // add characteristics to the new item
  new_item->item_name = item_name;
  new_item->item_type = item_type;
  new_item->item_stats = item_stats;

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
