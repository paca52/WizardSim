#include "player.hpp"

Player::Player() 
  :Entity() { }

Player::Player(double x, double y, Texture2D *texture) 
  :Entity(x, y, texture) { }

Player::Player(const Player& player) 
  :Entity(player) { }


/*
  arr - sadrzi 4 elementa koji predstavljaju {w, a, s, d} tim redom
  arr[i] = 1 ako je dugme pritisnuto
  arr[i] = 0 ako dugme nije pritisnuto
*/
void Player::move(const bool arr[4]) {
  for(int i=0; i<4; ++i) {
    if(!arr[i]) continue;

    switch(i) {
      case 0:
        this->y -= MOVE_DIST;
        break;
      case 1:
        this->x -= MOVE_DIST;
        break;
      case 2:
        this->y += MOVE_DIST;
        break;
      case 3:
        this->x += MOVE_DIST;
        break;
    }
  }
}

void Player::move2(char key) {
  const int move_dist = 32;
  switch(key) {
    case KEY_W:
      this->y -= move_dist;
      break;
    case KEY_A:
      this->x -= move_dist;
      break;
    case KEY_S:
      this->y += move_dist;
      break;
    case KEY_D:
      this->x += move_dist;
      break;
    default:
      break;
  }
}

Player::~Player() { }