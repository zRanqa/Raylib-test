#ifndef BLOCK_H
#define BLOCK_H

#include "raylib.h"

class Block {
public:

    Vector2 pos;
    int width; 
    int height;
    Color color;

    Block(int x, int y, int width, int height, Color color);
    void setPos(int x, int y);

};

#endif