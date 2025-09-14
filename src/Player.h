#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
public:
    int id;
    Vector2 pos;
    int width; 
    int height;
    Color color;

    Player(int id, int x, int y, int width, int height, Color color);
    void move(Vector2 newPos);

};

#endif