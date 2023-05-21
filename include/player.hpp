#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"
#include "level.hpp"
#include <cmath>

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
  void move2(char key);
  void move2(char key, const Level& level);
  void draw(int frameCount) const;
  void drawHitbox(void) const;

  ~Player();
};

#endif // PLAYER_HPP