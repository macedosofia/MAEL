#include "map.h"

#include <fstream>
#include <string>

bool loadMap(const char* filePath, Map& map) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        return false;
    }

    std::string line;

    for (int row = 0; row < ROWS; row++) {
        if (!std::getline(file, line)) {
            return false;
        }

        if (line.length() != COLS) {
            return false;
        }

        for (int col = 0; col < COLS; col++) {
            char character = line[col];
            if (character < '0' || character > '6') {
                return false;
            }

            map.cells[row][col] = character - '0';
        }
    }

    if (std::getline(file, line)) {
        return false;
    }

    bool hasExit = false;

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (map.cells[row][col] == TILE_EXIT) {
                hasExit = true;
            }
        }
    }

    if (!hasExit) {
        return false;
    }

    return true;

}

bool isInsideMap(int row, int col) {
    return row >= 0 && row < ROWS &&
           col >= 0 && col < COLS;
}

bool isWalkable(const Map& map, int row, int col) {
    if (!isInsideMap(row, col)) {
        return false;
    }

    return map.cells[row][col] != TILE_WALL;
}

bool isExit(const Map& map, int row, int col) {
    if (!isInsideMap(row, col)) {
        return false;
    }

    return map.cells[row][col] == TILE_EXIT;
}
