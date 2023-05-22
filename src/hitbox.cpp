#include "hitbox.hpp"

Hitbox::Hitbox() 
: Hitbox(0, 0, 0, 0) { }

Hitbox::Hitbox(float topLeftX, float topLeftY, float bottomRightX, float bottomRightY)
: Hitbox(topLeftX, topLeftY, bottomRightX, bottomRightY, BLACK) { }

Hitbox::Hitbox(float topLeftX, float topLeftY, float bottomRightX, float bottomRightY, Color color)
: topLeftX(topLeftX),
  topLeftY(topLeftY),
  bottomRightX(bottomRightX),
  bottomRightY(bottomRightY),
  color(color) { }


Hitbox::Hitbox(std::tuple<float, float, float, float> points) {
  topLeftX     = std::get<0>(points);
  topLeftY     = std::get<1>(points);
  bottomRightX = std::get<2>(points);
  bottomRightY = std::get<3>(points);
}


Hitbox::Hitbox(const Hitbox& h) {
  topLeftX     = h.topLeftX;
  topLeftY     = h.topLeftY;
  bottomRightX = h.bottomRightX;
  bottomRightY = h.bottomRightY;
  color        = h.color;
}

void Hitbox::draw(void) const {
  DrawLine(topLeftX, topLeftY, bottomRightX, topLeftY, BLACK);
  DrawLine(topLeftX, topLeftY, topLeftX, bottomRightY, BLACK);
  DrawLine(bottomRightX, topLeftY, bottomRightX, bottomRightY, BLACK);
  DrawLine(topLeftX, bottomRightY, bottomRightX, bottomRightY, BLACK);
}

std::tuple<float, float, float, float> Hitbox::getPoints(void) const {
  return {topLeftX, topLeftY, bottomRightX, bottomRightY};
}


void Hitbox::translate(float x, float y) {
  topLeftX += x;
  bottomRightX += x;

  topLeftY += y;
  bottomRightY += y;
}

bool checkCollisionHitboxes(const Hitbox& h1, const Hitbox& h2) {
  auto [a, b, c, d] = h1.getPoints();
  auto [a1, b1, c1, d1] = h2.getPoints();

  auto intersection = [](float a, float b, float c, float d) {
    return std::min(b, d) - std::max(a, c);
  };

  return intersection(a, c, a1, c1) * intersection(a, d, a1, d1) > 0;
}