#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

enum DIRECTION { GORE, LEVO, DOLE, DESNO };

class Player : public Entity {
  float timeStandingStill = 0.0f;
  DIRECTION lastDirection = DOLE;
public:
  Player();
  Player(double x, double y);
  Player(double x, double y, int numberOfFrames);
  Player(const Player& player);

  void move(char key);
  void draw(int frameCount);

  ~Player();
};

#endif // PLAYER_HPP