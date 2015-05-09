/* This header is currently holding structures for the player, enemy and room. I will eventually devide out these into seprate file ex. player.h, dungeon.h, enemy.h */

#ifndef dungeon_h
#define dungeon_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// max size of the player bag
#define MAX_BAG 10

enum move {
  MOVE_LEFT,
  MOVE_RIGHT,
  MOVE_UP,
  MOVE_DOWN
};

// dungeon room names
enum dr_names {
    kitchen,
    dungeon,
    attic,
    boiler,
    livingroom,
    garage,
    bedroom
};

// a bag structure for holding items
typedef struct bag {
  char *items[MAX_BAG];
} bag;

// create a structure for each room in the dungeon
typedef struct room {
  char *room_name;
  int room_level;
  struct room *room_up;
  struct room *room_down;
  struct room *room_left;
  struct room *room_right;
  struct enemy *enemy;
} room;

// create a structure for the player
typedef struct player {
  char *name;
  int health_points;
  int strength;
  int defense;
  bag *player_bag;
  room *current_room;
  bool alive_dead;
} player;

// enemy structure
typedef struct enemy {
  char *enemy_name;
  int health_points;
  int strength;
  struct item *enemy_item;
} enemy;

typedef struct item {
  char *item_name;
  int item_stats;
  char *item_type;
} item;

typedef struct dungeon {
  struct room *starting_zone;
  struct room *boiler_room;
  struct room *kitchen;
  struct room *attic;
  struct room *dungeon;
  struct room *living_room;
  struct room *garage;
  struct room *bedroom;
}


// create a new dungeon (links together dungeon rooms)
dungeon create_dungeon(char *dungeon_room);
// function to create a new player
player *create_player(char *name, room *current_room);
// create a new enemy
enemy *create_enemy(char *name);
// create new rooms
room *create_room(char *room_name);
// create a new bag
bag *create_bag();
// move the player (up, down, left, right)
void player_move(enum move direction);
// fight the enemy
void fight(player *player, enemy *enemy);
// create a new item to attach to an enemy
item *create_item(char *item_name, char *item_type, int item_stats);
// loot item for the enemy (destroys the item on the enemy and recreates the item)
item *loot_item(char *item_name);
// destroy player
void destroy_player(player *player);
// destroy enemy
void destroy_enemy(enemy *enemy);
// destroy room
void destroy_room(room *room);
// destroy item
void destroy_item(item *item);
// destroy everything
void destroy_all();
#endif
