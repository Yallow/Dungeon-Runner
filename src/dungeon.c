/* This c file is used to create functions that will be used to create/manipulate the dungeon */

#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"
#include "../dbg/dbg.h"


// create a new dungeon room
room *create_room(char *room_name)
{
  room *new_room = calloc(1, sizeof(room));
  new_room->room_name = room_name;

  // gather info for this room's enemy
  size_t n_bytes = 200; // initial allocation for stdin in this function
  char enemy_name[n_bytes];

  // set these as the default. they will change after this function is called
  int def_hp = 20;
  int def_str = 2;
  item *def_item = create_item("Rubber Chicken", "o", 100);
  enemy *new_enemy = create_enemy(enemy_name, def_hp, def_str, def_item);

  // put the enemy in the room
  new_room->enemy = new_enemy;

  return new_room;
}

// destroy a dungeon room
void destroy_room(room *room)
{
    // free any links that the room has made
  free(room->room_up);
  free(room->room_down);
  free(room->room_right);
  free(room->room_left);
  free(room->enemy);
  free(room);
}

// create the actual dungeon and return the address of the starting location
room *create_dungeon(char *dungeon_name)
{
    printf("Welcome to: %s\n", dungeon_name);
    // create a linked list of dungeon rooms
    // create the starting area
    room *start = create_room("Starting Zone");
    start->room_level = 1;
    start->enemy->enemy_name = "Terry";
    start->enemy->health_points = 12;
    start->enemy->strength = 2;
    start->enemy->enemy_item = make_items(0);

    // create the boiler room
    room *boiler = create_room("Boiler Room");
    boiler->room_level = 1;
    boiler->enemy->enemy_name = "Bertha";
    boiler->enemy->health_points = 22;
    boiler->enemy->strength = 1;
    boiler->enemy->enemy_item = make_items(1);

    // create the kitchen
    room *kitchen = create_room("Kitchen");
    kitchen->room_level = 2;
    kitchen->enemy->enemy_name = "Zed";
    kitchen->enemy->health_points = 10;
    kitchen->enemy->strength = 4;
    kitchen->enemy->enemy_item = make_items(2);

    // create the attic
    room *attic = create_room("Attic");
    attic->room_level = 2;
    attic->enemy->enemy_name = "Gertrude";
    attic->enemy->health_points = 17;
    attic->enemy->strength = 3;
    attic->enemy->enemy_item = make_items(3);

    // teir 2 rooms
    // create the dungeon - many rooms will spawn off of this in the future
    room *dungeon_r = create_room("Dungeon");
    dungeon_r->room_level = 2;
    dungeon_r->enemy->enemy_name = "Goliath";
    dungeon_r->enemy->health_points = 37;
    dungeon_r->enemy->strength = 1;
    dungeon_r->enemy->enemy_item = make_items(4);

    // create the living room
    room *living_room = create_room("Living Room");
    living_room->room_level = 2;
    living_room->enemy->enemy_name = "Henry";
    living_room->enemy->health_points = 22;
    living_room->enemy->strength = 3;
    living_room->enemy->enemy_item = make_items(5);

    // create the garage
    room *garage = create_room("Garage");
    garage->room_level = 2;
    garage->enemy->enemy_name = "Kit";
    garage->enemy->health_points = 20;
    garage->enemy->strength = 3;
    garage->enemy->enemy_item = make_items(6);

    // create the bedroom
    room *bedroom = create_room("Bedroom");
    bedroom->room_level = 3;
    bedroom->enemy->enemy_name = "Don";
    bedroom->enemy->health_points = 27;
    bedroom->enemy->strength = 4;
    bedroom->enemy->enemy_item = make_items(7);

    // setup room links (doors)
    start->room_up = attic;
    start->room_down = boiler;
    start->room_right = kitchen;

    attic->room_down = start;

    boiler->room_up = start;
    boiler->room_right = dungeon_r;

    kitchen->room_left = start;
    kitchen->room_right = living_room;
    kitchen->room_down = garage;

    dungeon_r->room_left = boiler;

    living_room->room_left = kitchen;
    living_room->room_right = bedroom;

    garage->room_up = kitchen;

    bedroom->room_left = living_room;

    return start;
}
