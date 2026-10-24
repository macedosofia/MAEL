#include "game.h"

#include "map.h"
#include "map_renderer.h"
#include "character.h"
#include "ui.h"

#include "raylib.h"

#include <iostream>

int runGame() {
    constexpr int TILE_SIZE = 20;
    constexpr int PANEL_WIDTH = 200;

    constexpr int START_ROW = 1;
    constexpr int START_COL = 1;

    const int mapWidth = COLS * TILE_SIZE;
    const int windowWidth = mapWidth + PANEL_WIDTH;
    const int windowHeight = ROWS * TILE_SIZE;

    Map map{};

    if (!loadMap("data/fase1.txt", map)) {
        std::cerr << "Error loading map!" << std::endl;
        return 1;
    }

    std::cout << "Map loaded successfully!" << std::endl;

    Character player{START_ROW, START_COL, 100, 3, 0};

    if (!isValidStartingPosition(player, map)) {
        std::cerr << "Invalid starting position!" << std::endl;
        return 1;
    }

    InitWindow(windowWidth, windowHeight, "Definir Nome - O Despertar");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        drawMap(map, TILE_SIZE, 0, 0);
        drawCharacter(player, TILE_SIZE, 0, 0);

        drawSidePanel(mapWidth, 0, PANEL_WIDTH, windowHeight, 1, "O DESPERTAR");

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
