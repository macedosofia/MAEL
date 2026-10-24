#ifndef CHARACTER_H
#define CHARACTER_H

#include "map.h"

struct Character {
    int row;
    int col;
    int energy;
    int lives;
    int points;
};

bool isValidStartingPosition(const Character& character, const Map& map);

void drawCharacter(const Character& character, int tileSize, int offsetX, int offsetY);

void moveCharacter(Character& character, int deltaRow, int deltaCol);

void updateCharacter(Character& character);

#endif
