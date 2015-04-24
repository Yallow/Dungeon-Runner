/* This header is currently holding structures for the player, enemy and room. I will eventually devide out these into seprate file ex. player.h, dungeon.h, enemy.h */

#ifndef dungeon_h
#define dungeon_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// max size of the player bag
extern int MAX_BAG = 10;

enum move {
  MOVE_LEFT,
  MOVE_RIGHT,
  MOVE_UP,
  MOVE_DOWN
};

// create a variable type of bag
typedef *char[MAX_BAG] bag;

// create a structure for each room in the dungeon
typedef struct *room {
  char *room_name;
  int room_level;
  room *room_up;
  room *room_down;
  room *room_left;
  room *room_right;
  enemy *enemy;
} room;

// create a structure for the player
typedef struct *player {
  char *name;
  int health_points;
  int strength;
  
  room *current_room;
  bool alive_dead;
} player;

// enemy structure
typedef struct *enemy {
  char *enemy_name;
  int health_points;
  int strength;
} enemy;

// function to create a new player
player create_player(char *name, int health_points, int strength);
// create a new enemy
enemy create_enemy(char *name, int health_points, int strength);
// create new rooms
room room_create(char *room_name, enemy *enemy);
// move the player (up, down, left, right)
void player_move(move direction);
// fight the enemy
void fight(player *player, enemy *enemy);

#endif
