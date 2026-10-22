#include "raylib.h"

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;

    InitWindow(windowWidth, windowHeight, "RoboLab - O Despertar");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("FASE 1 - O DESPERTAR", 200, 200, 30, RAYWHITE);

        DrawText("Prototipo em desenvolvimento", 200, 260, 20, LIGHTGRAY);

        DrawText("Pressione ESC para sair", 200, 320, 20, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}