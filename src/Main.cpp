#include "raylib.h"
#include "Player.h"
#include <iostream>
#include <vector>

int main() {
    InitWindow(800, 600, "Raylib Test");

    Player p1(1, 20, 20, 20, 20, RED);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        {
            if (IsKeyDown(KEY_W)) {
                p1.move(0, -5);
            }
            if (IsKeyDown(KEY_S)) {
                p1.move(0, 5);
            }
            if (IsKeyDown(KEY_A)) {
                p1.move(-5, 0);
            }
            if (IsKeyDown(KEY_D)) {
                p1.move(5, 0);
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello, Raylib!", 10, 10, 20, DARKGRAY);
        
        DrawRectangle(p1.x, p1.y, p1.width, p1.height, p1.color);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
