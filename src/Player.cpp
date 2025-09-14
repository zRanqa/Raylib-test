
#include "Player.h"

Player::Player(int id, int x, int y, int width, int height, Color color) {
    this->id = id;
    Vector2 pos;
    pos.x = x;
    pos.y = y;
    this->pos = pos;
    this->width = width;
    this->height = height;
    this->color = color;
}
void Player::move(Vector2 movePos) {
    Vector2 newPos = Vector2();
    newPos.x = pos.x + movePos.x;
    newPos.y = pos.y + movePos.y;
    this->pos = newPos;

}