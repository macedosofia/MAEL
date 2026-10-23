#include "raylib.h"
#include "map.h"
#include "map_renderer.h"
#include "robot.h"

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

    constexpr int START_ROW = 1;
    constexpr int START_COL = 1;

    Robot player{START_ROW, START_COL, 100, 3, 0};

    if (!isValidStartingPosition(player, map)) {
        std::cerr << "Invalid starting position!" << std::endl;
        return 1;
    }

    InitWindow(windowWidth, windowHeight, "RoboLab - O Despertar");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        drawMap(map, TILE_SIZE, 0, 0);
        drawRobot(player, TILE_SIZE, 0, 0);
        
        const int panelX = COLS * TILE_SIZE;
        DrawRectangle(panelX, 0, PANEL_WIDTH, windowHeight, Color{25, 28, 35, 255});

        DrawText("FASE 1", panelX + 20, 40, 24, RAYWHITE);
        DrawText("O DESPERTAR", panelX + 20, 80, 18, LIGHTGRAY);
        DrawText("Pressione ESC para sair", panelX + 20, 550, 14, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}