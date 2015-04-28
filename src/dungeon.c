/* This c file is used to create functions that will be used to create/manipulate the dungeon */

#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"
#include "../dbg/dbg.h" 

// create a new dungeon room
room create_room(char *room_name, enemy *enemy)
{
  room *new_room = calloc(1, sizeof(room));

  return new_room;
}

// destroy a dungeon room
void destroy_room(room *room)
{
  free(room);
}

int main(int argc, char *argv[])
{
  room *test_room = calloc(1, sizeof(room));
  test_room = create_room("Test Room", enemy);

  return 0;
}
