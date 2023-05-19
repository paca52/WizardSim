#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

const double MOVE_DIST = 0.1;

class Player : public Entity {
  float timeStandingStill    = 0.0f;
  const int numberOfFrames   = 3;
public:
  Player();
  Player(double x, double y, Texture2D *texture);
  Player(double x, double y, Texture2D *texture, int numberOfFrames);
  Player(const Player& player);

  void move(const bool arr[4]);
  void move2(char key);
  void draw(int frameCount);

  ~Player();
};

#endif // PLAYER_HPP