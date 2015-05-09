#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"
#include "../dbg/dbg.h"
#include <stdbool.h>

player *create_player(char *name, room *current_room)
{
  int start_health_points = 20;
  player *new_player = calloc(1, sizeof(player));
  new_player->name = name;
  new_player->health_points = start_health_points;
  // pass over a pointer to a room (this will always be the starting zone)
  new_player->current_room = current_room;
  new_player->alive_dead = true;

  printf("New player created: %s\n", new_player->name);
  printf("Hit points: %d\n", new_player->health_points);
  printf("Strength: %d\n", new_player->strength);
  printf("Defense: %d\n", new_player->defense);

  // create a new bag that will be attached to the player
  bag *player_bag = create_bag();

  // create a basic sword and shield for the player
  item *sword = create_item("Playdoh Hammer", "o", 2);
  item *shield = create_item("T-Shirt Shield", "d", 2);

  // add the item stats onto the player
  new_player->strength = sword->item_stats;
  new_player->defense = shield->item_stats;

  printf("You are carrying a: %s, with stats of %d and a %s, with stats of %d\n", sword->item_name, sword->item_stats, shield->item_name, shield->stats);
  return new_player;
}

void player_move(enum move direction)
{
  switch(direction) {
  case MOVE_LEFT:
    printf("Moving Left\n");
    break;
  case MOVE_RIGHT:
    printf("Moving Right\n");
    break;
  case MOVE_UP:
    printf("Moving Up\n");
    break;
  case MOVE_DOWN:
    printf("Moving Down\n");
    break;
  default:
    printf("You can't move that direction\n");
    break;
  }
}

bag *create_bag()
{
  bag *new_bag = calloc(1, sizeof(bag));

  return new_bag;
}
