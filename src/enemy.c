/* File to create and manipulate enemies */

#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"
#include "../dbg/dbg.h"

enemy *create_enemy(char *name, int enemy_hp, int enemy_str, item *enemy_item)
{
  // allocate memory for a new enemy
  enemy *new_enemy = calloc(1, sizeof(enemy));

  // setup some of the enemy features
  new_enemy->enemy_name = name;
  new_enemy->health_points = enemy_hp;
  new_enemy->strength = enemy_str;
  new_enemy->enemy_item = enemy_item;

  // print statement for debugging
  printf("A new enemy approaches! %s\n", new_enemy->enemy_name);
  printf("%s has HP of %d, Strength of: %d, and is has loot of: %s\n", new_enemy->enemy_name, new_enemy->health_points, new_enemy->strength, new_enemy->enemy_item->item_name);

  return new_enemy;
}

// call this function when an enemy has been killed
void destroy_enemy(enemy *enemy)
{
  printf("%s has been killed!\n", enemy->enemy_name);
  free(enemy);
}
