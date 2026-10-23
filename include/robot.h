#ifndef ROBOT_H
#define ROBOT_H

#include "map.h"

struct Robot {
    int row;
    int col;
    int energy;
    int lives;
    int points;
};

bool isValidStartingPosition(const Robot& robot, const Map& map);

void drawRobot(const Robot& robot, int tileSize, int offsetX, int offsetY);

#endif