#include "character.h"
#include "raylib.h"

bool isValidStartingPosition(const Character& character, const Map& map) {
    if (character.row < 0 || character.row >= ROWS ||
        character.col < 0 || character.col >= COLS) {
        return false;
    }

    return map.cells[character.row][character.col] == 0;
}

void drawCharacter(const Character& character, int tileSize, int offsetX, int offsetY) {
    const int padding = tileSize / 5;

    const int x = offsetX + character.col * tileSize + padding;
    const int y = offsetY + character.row * tileSize + padding;

    const int size = tileSize - 2 * padding;

    DrawRectangle(x, y, size, size, SKYBLUE);
}

void moveCharacter(Character& character, int deltaRow, int deltaCol) {
    int newRow = character.row + deltaRow;
    int newCol = character.col + deltaCol;

    if (newRow < 0 || newRow >= ROWS ||
        newCol < 0 || newCol >= COLS) {
        return;
    }

    character.row = newRow;
    character.col = newCol;
}
