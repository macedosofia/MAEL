#ifndef MAP_H
#define MAP_H

const int ROWS = 30;
const int COLS = 30;

struct Map {
    int cells[ROWS][COLS];
};

bool loadMap(const char* filePath, Map& map);

#endif