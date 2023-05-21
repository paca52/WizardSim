#include "player.hpp"

Player::Player() 
  :Entity() { }

Player::Player(double x, double y) 
  :Player(x, y, 1) { }

Player::Player(double x, double y, int numberOfFrames) 
  :Entity(x, y, numberOfFrames) {
    texture = new Texture2D[4] {
      LoadTexture("util/textures/Carobnjak0.png"),
      LoadTexture("util/textures/Carobnjak1.png"),
      LoadTexture("util/textures/Carobnjak2.png"),
      LoadTexture("util/textures/Carobnjak3.png")
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
      if(lastDirection == GORE && y - move_dist >= 0) {
        y = y - move_dist;
      }
      lastDirection = GORE;
      break;
    case KEY_A:
      if(lastDirection == LEVO && x - move_dist >= 0) {
        x = x - move_dist;
      }
      lastDirection = LEVO;
      break;
    case KEY_S:
      if(lastDirection == DOLE && y + move_dist + frameHeight < GetScreenHeight()) {
        y = y + move_dist;
      }
      lastDirection = DOLE;
      break;
    case KEY_D:
      if(lastDirection == DESNO && x + move_dist + frameWidth < GetScreenWidth()) {
        x = x + move_dist;
      }
      lastDirection = DESNO;
      break;
    default:
      break;
  }
}

void Player::move2(char key, const Level& level) {
  float move_dist = 2.0f;
  std::pair<int, int> moveVector = { 0, 0 };

  if(IsKeyDown(KEY_W)) {
    moveVector.second -= move_dist;
    lastDirection = GORE;
  }
  if(IsKeyDown(KEY_A)) {
    moveVector.first  -= move_dist;
    lastDirection = LEVO;
  }
  if(IsKeyDown(KEY_S)) {
    moveVector.second += move_dist;
    lastDirection = DOLE;
  }
  if(IsKeyDown(KEY_D)) {
    moveVector.first  += move_dist;
    lastDirection = DESNO;
  }

  if(x + moveVector.first < 0 || x + moveVector.first + frameWidth > GetScreenWidth()) return;
  if(y + moveVector.second < 0 || y + moveVector.second + frameHeight > GetScreenHeight()) return;

  if(moveVector.first == 0 || moveVector.second == 0) {
    if(!level.isWalkable(x + moveVector.first, y + moveVector.second)) return;
    x += moveVector.first;
    y += moveVector.second;
  } else {
    if(!level.isWalkable(x + (moveVector.first / sqrt(2)), y + (moveVector.second /sqrt(2)))) return;
    x += moveVector.first / sqrt(2);
    y += moveVector.second / sqrt(2);
    lastDirection = moveVector.second > 0 ? DOLE : GORE;
  }
}

void Player::move2(char key) {

}
// void Player::move2(char key) {
//   float move_dist = 2.0f;
//   const bool arr[4] = {
//     IsKeyDown(KEY_W),
//     IsKeyDown(KEY_A),
//     IsKeyDown(KEY_S),
//     IsKeyDown(KEY_D)
//   };

//   if(arr[0] && arr[1]) {
//     move_dist /= sqrt(2);
//     if(!level.isWalkable(x - move_dist, y - move_dist)) return;
//     if(y - move_dist >= 0) { y = y - move_dist; }
//     if(x - move_dist >= 0) { x = x - move_dist; }
//     lastDirection = GORE;
//   }
//   else if(arr[0] && arr[3]) {
//     if(!level.isWalkable(x + move_dist, y - move_dist)) return;
//     if(y - move_dist >= 0) { y = y - move_dist; }
//     if(x + move_dist + frameWidth < GetScreenWidth()) { x = x + move_dist; }
//     lastDirection = GORE;
//   }
//   else if(arr[2] && arr[1]) {
//     if(!level.isWalkable(x - move_dist, y + move_dist)) return;
//     if(y + move_dist + frameHeight < GetScreenHeight()) { y = y + move_dist; }
//     if(x - move_dist >= 0) { x = x - move_dist; }
//     lastDirection = DOLE;
//   }
//   else if(arr[2] && arr[3]) {
//     if(!level.isWalkable(x + move_dist + frameWidth, y + move_dist + frameHeight)) return;
//     if(y + move_dist + frameHeight < GetScreenHeight()) { y = y + move_dist; }
//     if(x + move_dist + frameWidth < GetScreenWidth()) { x = x + move_dist; }
//     lastDirection = DOLE;
//   }
//   else if(arr[0] && arr[3]) {
//     return;
//   }
//   else if(arr[0]) {
//     if(!level.isWalkable(x, y - move_dist)) return;
//     if(y - move_dist >= 0) { y = y - move_dist; }
//     lastDirection = GORE;
//   }
//   else if(arr[1]) {
//     if(!level.isWalkable(x - move_dist, y)) return;
//     if(x - move_dist >= 0) { x = x - move_dist; }
//     lastDirection = LEVO;
//   }
//   else if(arr[2]) {
//     if(!level.isWalkable(x, y + move_dist + frameHeight)) return;
//     if(y + move_dist + frameHeight < GetScreenHeight()) { y = y + move_dist; }
//     lastDirection = DOLE;
//   }
//   else if(arr[3]) {
//     if(!level.isWalkable(x + move_dist + frameWidth, y)) return;
//     if(x + move_dist + frameWidth < GetScreenWidth()) { x = x + move_dist; }
//     lastDirection = DESNO;
//   }
// }

void Player::draw(int frameCount) const {
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

void Player::drawHitbox(void) const {
  DrawLine(x, y, x+frameWidth, y, BLACK);
  DrawLine(x, y, x, y+frameHeight, BLACK);
  DrawLine(x, y+frameWidth, x+frameWidth, y+frameHeight, BLACK);
  DrawLine(x+frameHeight, y, x+frameWidth, y+frameHeight, BLACK);
}

Player::~Player() {
  for(int i=0; i<4; ++i) {
    UnloadTexture(texture[i]);
  }
  delete [] texture;
}