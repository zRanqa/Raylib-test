#include "raylib.h"
#include "Player.h"
#include "Block.h"
#include <iostream>
#include <vector>

int main() {
    InitWindow(800, 600, "Raylib Test");

    Player p1(1, 20, 20, 20, 20, RED);
    Block block(50, 50, 50, 50, BLUE);

    bool offsetOnce = true;
    bool boxGrabbed = false;
    Vector2 offset = {0, 0};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        {
            Vector2 pos;
            pos.x = 0;
            pos.y = 0;
            if (IsKeyDown(KEY_W)) {
                pos.y -= 5;
            }
            if (IsKeyDown(KEY_S)) {
                pos.y += 5;
            }
            if (IsKeyDown(KEY_A)) {
                pos.x -= 5;
            }
            if (IsKeyDown(KEY_D)) {
                pos.x += 5;
            }
            if (pos.x != 0 || pos.y != 0) {
                p1.move(pos);
            }
        }
        {
            // block movement

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                
                Vector2 mousePos = GetMousePosition();
                Rectangle rec1 = {mousePos.x, mousePos.y, 5, 5};
                Rectangle rec2 = {block.pos.x, block.pos.y, static_cast<float>(block.width), static_cast<float>(block.height)};
                if (offsetOnce) {
                    offsetOnce = false;
                    offset = {mousePos.x - block.pos.x, mousePos.y - block.pos.y};

                }
                if (CheckCollisionRecs(rec1, rec2) || boxGrabbed) {
                    boxGrabbed = true;
                    block.setPos(mousePos.x - offset.x, mousePos.y - offset.y);
                }

            }
            else if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                offsetOnce = true;
                boxGrabbed = false;
            }

        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello, Raylib!", 10, 10, 20, DARKGRAY);
        
        DrawRectangle(p1.pos.x, p1.pos.y, p1.width, p1.height, p1.color);
        DrawRectangle(block.pos.x, block.pos.y, block.width, block.height, block.color);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
