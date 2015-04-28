/* File to create and manipulate enemies */

#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"
#include "../dbg/dbg.h"

enemy create_enemy(char *name, int health_points, int strength)
{
  // allocate memory for a new enemy
  enemy new_enemy = calloc(1, sizeof(enemy));

  // setup some of the enemy features
  new_enemy->enemy_name = name;
  new_enemy->health_points = health_points;
  new_enemy->strength = strength;
  new_enemy->enemy_item = create_item("Wooden Sword");

  // print statement for debugging
  printf("A new enemy approaches! %s\n", new_enemy->name);

  return new_enemy;
}

// call this function when an enemy has been killed
void destroy_enemy(enemy *enemy)
{
  printf("%s has been killed!\n", enemy->enemy_name);
  free(enemy);
}
