#ifndef MAP_H
#define MAP_H

const int ROWS = 30;
const int COLS = 30;

constexpr int TILE_EMPTY = 0;
constexpr int TILE_WALL = 1;
constexpr int TILE_EXIT = 4;

struct Map {
    int cells[ROWS][COLS];
};

bool loadMap(const char* filePath, Map& map);

bool isInsideMap(int row, int col);

bool isWalkable(const Map& map, int row, int col);

bool isExit(const Map& map, int row, int col);

#endif
