#include "robot.h"
#include "raylib.h"

bool isValidStartingPosition(const Robot& robot, const Map& map) {
    if (robot.row < 0 || robot.row >= ROWS ||
        robot.col < 0 || robot.col >= COLS) {
        return false;
    }

    return map.cells[robot.row][robot.col] == 0;
}

void drawRobot(const Robot& robot, int tileSize, int offsetX, int offsetY) {
    const int padding = tileSize / 5;

    const int x = offsetX + robot.col * tileSize + padding;
    const int y = offsetY + robot.row * tileSize + padding;

    const int size = tileSize - 2 * padding;

    DrawRectangle(x, y, size, size, SKYBLUE);
}

