#include "map_renderer.h"
#include "raylib.h"

namespace {
    Color getCellColor(int cellType) {
        switch(cellType) {
            case 0:
                return Color{45, 48, 58, 255};
            case 1:
                return Color{100, 105, 115, 255};
            case 2:
                return YELLOW;
            case 3:
                return BLUE;
            case 4:
                return GREEN;
            case 5:
                return PURPLE;
            case 6:
                return RED;
            default:
                return MAGENTA;
        }
    }
}

void drawMap(const Map& map, int tileSize, int offsetX, int offsetY) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int cellType = map.cells[row][col];

            int x = offsetX + col * tileSize;
            int y = offsetY + row * tileSize;

            Color color = getCellColor(cellType);

            DrawRectangle(x, y, tileSize, tileSize, color);
            DrawRectangleLines(x, y, tileSize, tileSize, DARKGRAY);
        }
    }
}