#ifndef FUNCTIONS_H  
#define FUNCTIONS_H

#include "player.h"

bool turn(Player& , char(&grid)[3][3], bool turn);
void drawGrid(char(&grid)[3][3]);
void winnerCheck(Player& player, char(&grid)[3][3]);


#endif