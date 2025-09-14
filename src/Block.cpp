
#include "Block.h"


Block::Block(int x, int y, int width, int height, Color color) {
    Vector2 pos; pos.x = x; pos.y = y;
    this->pos = pos;
    this->width = width;
    this->height = height;
    this->color = color;
}
void Block::setPos(int x, int y) {
    Vector2 pos; pos.x = x; pos.y = y;
    this->pos = pos;
}