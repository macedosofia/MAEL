#include "character.h"
#include "raylib.h"

bool isValidStartingPosition(const Character& character, const Map& map) {
    if (!isInsideMap(character.row, character.col)) {
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

void moveCharacter(Character& character, const Map& map, int deltaRow, int deltaCol) {
    int newRow = character.row + deltaRow;
    int newCol = character.col + deltaCol;

    if (!isWalkable(map, newRow, newCol)) {
        return;
    }

    character.row = newRow;
    character.col = newCol;
}

void updateCharacter(Character& character, const Map& map) {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        moveCharacter(character, map, -1, 0);
    }
    else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
        moveCharacter(character, map, 1, 0);
    }
    else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        moveCharacter(character, map, 0, -1);
    }
    else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        moveCharacter(character, map, 0, 1);
    }
}
