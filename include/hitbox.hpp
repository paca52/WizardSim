#ifndef HITBOX_HPP
#define HITBOX_HPP

#include "raylib.h"
#include <tuple>
#include <algorithm>

class Hitbox {
  float 
    topLeftX,
    topLeftY,
    bottomRightX,
    bottomRightY;
  Color color;
public:
  Hitbox();
  Hitbox(float topLeftX, float topLeftY, float bottomRightX, float bottomRightY);
  Hitbox(float topLeftX, float topLeftY, float bottomRightX, float bottomRightY, Color color);
  Hitbox(std::tuple<float, float, float, float> points);
  Hitbox(const Hitbox& h);
  void draw() const;
  std::tuple<float, float, float, float> getPoints(void) const;
  void translate(float x, float y);
  friend bool checkCollisionHitboxes(const Hitbox&, const Hitbox&);
};

#endif // HITBOX_HPP