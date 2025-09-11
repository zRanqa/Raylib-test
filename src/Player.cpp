
#include "Player.h"

Player::Player(int id, int x, int y, int width, int height, Color color) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->color = color;
}
void Player::move(int dx, int dy) {
    this->x += dx;
    this->y += dy;
}