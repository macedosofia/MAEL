#include "raylib.h"
#include "map.h"

#include <iostream>

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;

    Map map{};

    if (!loadMap("data/fase1.txt", map)) {
        std::cerr << "Error loading the map!" << std::endl;
        return 1;
    }

    std::cout << "Map loaded successfully!" << std::endl;

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