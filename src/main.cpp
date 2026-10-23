#include "raylib.h"
#include "map.h"
#include "map_renderer.h"

#include <iostream>

int main() {
    constexpr int TILE_SIZE = 20;
    constexpr int PANEL_WIDTH = 200;
    
    const int windowWidth = COLS * TILE_SIZE + PANEL_WIDTH;
    const int windowHeight = ROWS * TILE_SIZE;

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

        drawMap(map, TILE_SIZE, 0, 0);
        const int panelX = COLS * TILE_SIZE;
        DrawRectangle(panelX, 0, PANEL_WIDTH, windowHeight, Color{25, 28, 35, 255});

        DrawText("FASE 1 - O DESPERTAR", 200, 200, 30, RAYWHITE);
        DrawText("Pressione ESC para sair", 200, 320, 20, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}