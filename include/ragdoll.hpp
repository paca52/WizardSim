#ifndef RAGDOLL_HPP
#define RAGDOLL_HPP

#include "hitbox.hpp"
#include <vector>

class Ragdoll {
  typedef std::tuple<float, float, float, float> Points;
  Hitbox head, body, feet, leftArm, rightArm;

  std::vector<Hitbox*> getHitboxesChangable(void);
public:
  Ragdoll();
  Ragdoll(Points head, Points body, Points feet, Points leftArm, Points rightArm);

  void translate(const std::pair<float, float>& moveVector);
  std::vector<const Hitbox*> getHitboxes(void) const;
  bool isOutOfBorders(void);

  // debugging functions
  void draw(void) const;
};

#endif // RAGDOLL_HPP