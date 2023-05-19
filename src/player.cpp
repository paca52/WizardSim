#include "player.hpp"

Player::Player() 
  :Entity() { }

Player::Player(double x, double y) 
  :Player(x, y, 1) { }

Player::Player(double x, double y, int numberOfFrames) 
  :Entity(x, y, numberOfFrames) {
    texture = new Texture2D[4] {
      LoadTexture("textures/Carobnjak2.png"),
      LoadTexture("textures/Carobnjak1.png"),
      LoadTexture("textures/Carobnjak2.png"),
      LoadTexture("textures/Carobnjak3.png")
    };

    for(int i=0; i<4; ++i) {
      texture[i].width  *= 2;
      texture[i].height *= 2;
    }

    frameWidth  = texture[0].width / numberOfFrames;
    frameHeight = texture[0].height;
}

Player::Player(const Player& player) 
  :Entity(player) { }

/*
  key - key pressed, can be any key but will only move for w, a, s and d
*/
void Player::move(char key) {
  const int move_dist = 32;

  if(key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D) timeStandingStill = 0.0f;
  else timeStandingStill += 0.01f;

  switch(key) {
    case KEY_W:
      y = y - move_dist < 0 ? y : y - move_dist;
      lastDirection = GORE;
      break;
    case KEY_A:
      x = x - move_dist < 0 ? x: x - move_dist;
      lastDirection = LEVO;
      break;
    case KEY_S:
      y = y + move_dist + frameHeight > GetScreenHeight() ? y : y + move_dist;
      lastDirection = DOLE;
      break;
    case KEY_D:
      x = x + move_dist + frameWidth > GetScreenWidth() ? x : x + move_dist;
      lastDirection = DESNO;
      break;
    default:
      break;
  }
}

void Player::draw(int frameCount) {
  DrawTextureRec(
    texture[lastDirection],
    Rectangle{
      timeStandingStill < 1.0f ? 0 : (frameWidth * ( frameCount % numberOfFrames )),
      0,
      frameWidth,
      frameHeight
    },
    Vector2{
      (float)x,
      (float)y
    },
    RAYWHITE
  );
}

Player::~Player() {
  for(int i=0; i<4; ++i) {
    UnloadTexture(texture[i]);
  }
  delete [] texture;
}