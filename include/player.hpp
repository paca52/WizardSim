#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

const double MOVE_DIST = 0.1;

class Player : public Entity {
public:
  Player();
  Player(double x, double y, Texture2D *texture);
  Player(const Player& player);

  void move(const bool arr[4]);
  void move2(char key);

  ~Player();
};

#endif // PLAYER_HPP