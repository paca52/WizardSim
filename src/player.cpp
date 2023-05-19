#include "player.hpp"

Player::Player() 
  :Entity() { }

Player::Player(double x, double y, Texture2D *texture) 
  :Entity(x, y, texture) { }

Player::Player(double x, double y, Texture2D *texture, int numberOfFrames) 
  :Entity(x, y, texture, numberOfFrames) { }

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
  if(key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
    timeStandingStill = 0.0f;
  else
    timeStandingStill += 0.01f;

  const int move_dist = 32;
  switch(key) {
    case KEY_W:
      y = y-move_dist < 0 ? y : y - move_dist;
      break;
    case KEY_A:
      x = x-move_dist < 0 ? x: x-move_dist;
      break;
    case KEY_S:
      y = y+move_dist+( frameHeight ) > GetScreenHeight() ? y: y+move_dist;
      break;
    case KEY_D:
      x = x+move_dist+( frameWidth ) > GetScreenWidth() ? x: x+move_dist;
      break;
    default:
      break;
  }
}

void Player::draw(int frameCount) {

  if(timeStandingStill < 4.0f) {
    DrawTextureRec(
      *this->texture,
      Rectangle{
        0,
        0,
        this->frameWidth,
        this->frameHeight
      },
      Vector2{
        (float)this->x,
        (float)this->y
      },
      RAYWHITE
    );
    return;
  }

  DrawTextureRec(
    *this->texture,
    Rectangle{
      (frameWidth * ( frameCount % numberOfFrames )),
      0,
      frameWidth,
      frameHeight
    },
    Vector2{
      (float)this->x,
      (float)this->y
    },
    RAYWHITE
  );
}

Player::~Player() { }