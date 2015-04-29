/* This c file is used to create functions that will be used to create/manipulate the dungeon */

#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"
#include "../dbg/dbg.h"

#define DUNGEONROOMS 4

// create a new dungeon room
room *create_room(char *room_name)
{
  room *new_room = calloc(1, sizeof(room));
  new_room->room_name = room_name;

  // gather info for this room's enemy
  size_t n_bytes = 200; // initial allocation for stdin in this function
  char *enemy_name;

  printf("What dwells in this room?: ");
  getline(&enemy_name, &n_bytes, stdin);
      // create a new enemy for this room
  enemy *new_enemy = create_enemy(enemy_name);

  // put the enemy in the room
  new_room->enemy = new_enemy;

  return new_room;
}

// destroy a dungeon room
void destroy_room(room *room)
{
  free(room);
}

int main(int argc, char *argv[])
{
  room  *test_room = create_room("Test Room");

  return 0;
}

// create the actualy dungeon
void create_dungeon(char *dungeon_name)
{
    int i;

    // create a linked list of dungeon rooms
    // create the starting area
    room *start = create_room("Starting Zone");
    start->room_level = 1;
    start->enemy->health_points = (start->room_level * 2);

    // create the boiler room
    room *boiler = create_room("Boiler Room");
    boiler->room_level = 1;
    boiler->enemy->health_points = (boiler->room_level * 2);

    // create the kitchen
    room *kitchen = create_room("Kitchen");
    kitchen->room_level = 2;
    kitchen->enemy->health_points = (kitchen->room_level * 2);

    // create the attic
    room *attic = create_room("Attic");
    attic->room_level = 2;
    attic->enemy->health_points = (attic->room_level * 2);

    // teir 2 rooms
    // create the dungeon - many rooms will spawn off of this in the future
    room *dungeon = create_room("Dungeon");
    dungeon->room_level = 2;
    dungeon->enemy->health_points = (dungeon->room_level * 2);

    // create the living room
    room *living_room = create_room("Living Room");
    living_room->room_level = 2;
    living_room->enemy->health_points = (living_room->room_level * 2);

    // create the garage
    room *garage = create_room("Garage");
    garage->room_level = 2;
    garage->enemy->health_points = (garage->room_level * 2);

    // create the bedroom
    room *bedroom = create_room("Bedroom");
    bedroom->room_level = 3;
    bedroom->enemy->health_points = (bedroom->room_level * 2);


}
