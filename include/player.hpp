#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"
#include "level.hpp"
#include <cmath>
#include "hitbox.hpp"
#include "ragdoll.hpp"

class Player : public Entity {
  enum DIRECTION { GORE, LEVO, DOLE, DESNO };

  float timeStandingStill = 0.0f;
  DIRECTION lastDirection = DOLE;
  Ragdoll ragdoll;
public:
  Player(double x, double y);
  Player(double x, double y, int numberOfFrames);
  Player(const Player& player);

  void move(char key);
  void move2(char key);
  void move2(const Level& level);
  void draw(int frameCount) const;
  void moveHitboxes(const std::pair<float, float>& moveVector);

  ~Player();

  // debugging functions
  void drawHitbox(void) const;
};

#endif // PLAYER_HPP