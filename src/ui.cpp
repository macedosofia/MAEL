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

void drawEnergyIndicator(int energy, int maxEnergy, int x, int y) {
    const int barWidth = 160;
    const int barHeight = 18;

    DrawText("ENERGIA", x, y, 18, LIGHTGRAY);

    DrawText(TextFormat("%d / %d", energy, maxEnergy),
             x, y + 30, 18, RAYWHITE);

    DrawRectangle(x, y + 60, barWidth, barHeight, DARKGRAY);

    if (maxEnergy <= 0) {
        return;
    }

    int filledWidth = (energy * barWidth) / maxEnergy;

    DrawRectangle(x, y + 60, filledWidth, barHeight, GREEN);
}
