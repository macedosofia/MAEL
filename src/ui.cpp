#include "ui.h"
#include "raylib.h"

void drawSidePanel(int x, int y, int width, int height, int levelNumber, const char* levelName) {
    DrawRectangle(x, y, width, height, Color{25, 28, 35, 255});

    DrawText(TextFormat("FASE %d", levelNumber), x + 20, y + 40, 24, RAYWHITE);

    DrawText(levelName, x + 20, y + 80, 18, LIGHTGRAY);

    DrawText("ESC: sair",x + 20,y + height - 50, 16, GRAY);
}

void drawLevelCompletedMessage(int x, int y) {
    DrawText("FASE CONCLUÍDA!", x, y, 16, GREEN);
}
