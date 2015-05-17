#include <stdio.h>
#include <stdlib.h>
#include "../dbg/dbg.h"
#include "dungeon.h"

item *create_item(char *item_name, char *item_type, int item_stats)
{
  item *new_item = calloc(1, sizeof(item));
  // add characteristics to the new item
  new_item->item_name = item_name;
  // options are either o(ffensive) or d(efensive)
  new_item->item_type = item_type;
  // stats will be added to player strength or defense
  new_item->item_stats = item_stats;

  return new_item;
}

item *loot_item(char *item_name, char *item_type, int item_stats)
{
  // create a new duplicate item
  item *dup_item = create_item(item_name, item_type, item_stats);

  printf("You have looted: %s\n", dup_item->item_name);

  return dup_item;
}

void destroy_item(item *item)
{
  free(item->item_name);
  free(item);
}

// return a pointer to the requested item
item *make_items(int item_num)
{
  // create new items to be linked to enemies and the player
  item *wooden_sword = create_item("Wooden Sword", "o", 2);
  item *wooden_shield = create_item("Wooden Shield", "d", 2);
  item *iron_sword = create_item("Iron Sword", "o", 4);
  item *iron_shield = create_item("Iron Shield", "d", 4);
  item *steel_sword = create_item("Steel Sword", "o", 6);
  item *steel_shield = create_item("Steel Shield", "d", 6);
  item *dark_sword = create_item("Dark Sword", "o", 8);
  item *dark_shield = create_item("Dark Shield", "d", 8);
  item *mithiril_sword = create_item("Mithiril Sword", "o", 10);
  item *mithiril_shield = create_item("Mithiril Shield", "d", 10);
  item *rune_sword = create_item("Rune Sword", "o", 14);
  item *rune_shield = create_item("Rune Shield", "d", 14);

  // put created items into the holder array
  item* item_holder[] = {
    wooden_sword,
    wooden_shield,
    iron_sword,
    iron_shield,
    steel_sword,
    steel_shield,
    dark_sword,
    dark_shield,
    mithiril_sword,
    mithiril_shield,
    rune_sword,
    rune_shield
  };

  item *selected_item = item_holder[item_num];

  return selected_item;
}
