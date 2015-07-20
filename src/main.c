/* This file contains the main action of the program */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../dbg/dbg.h"
#include "dungeon.h"

#define MAX_NAME 30

int main()
{
    char player_name[MAX_NAME];

    // create the dungeon while defining enemies in each room
    // Dungeon creation is working as intended * MORE TO COME *
    char *dungeon_name = "House on 14th";
    room *dungeon = create_dungeon(dungeon_name);

    printf("What do you call yourself hero?: ");
    fgets(player_name, MAX_NAME, stdin);
    // create a new player
    player *player1 = create_player(player_name, dungeon);
    // start movement
    player_move(MOVE_LEFT);

    return 0;
}
