#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"
#include "../dbg/dbg.h"

player *create_player(char *name, int health_points, int strength)
{
  player *new_player = calloc(1, sizeof(player));
  new_player->name = name;
  new_player->health_points = health_points;
  new_player->strength = strength;

  printf("New player created: %s\n", new_player->name);
  printf("Hit points: %d\n", new_player->health_points);
  printf("Strength: %d\n", new_player->strength);

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

int main()
{
  player *tyler = create_player("Tyler", 50, 10);
  void player_move(enum move MOVE_LEFT);

  return 0;
}
