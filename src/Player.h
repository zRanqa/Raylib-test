#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
public:
    int id;
    int x;
    int y;
    int width;
    int height;
    Color color;

    Player(int id, int x, int y, int width, int height, Color color);
    void move(int dx, int dy);

};

#endif