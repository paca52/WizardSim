#include "ragdoll.hpp"

Ragdoll::Ragdoll() 
:head(), body(), feet(), leftArm(), rightArm() { }

Ragdoll::Ragdoll(Points head, Points body, Points feet, Points leftArm, Points rightArm) 
:head(head), body(body), feet(feet), leftArm(leftArm), rightArm(rightArm) { }


std::vector<const Hitbox*> Ragdoll::getHitboxes(void) const {
  return std::vector<const Hitbox*> {
    &head,
    &body,
    &feet,
    &leftArm,
    &rightArm
  };
}

std::vector<Hitbox*> Ragdoll::getHitboxesChangable(void) {
  return std::vector<Hitbox*> {
    &head,
    &body,
    &feet,
    &leftArm,
    &rightArm
  };
}

void Ragdoll::translate(const std::pair<float, float>& moveVector) {
  std::vector<Hitbox*> v = getHitboxesChangable();
  for(auto it : v) { it->translate(moveVector.first, moveVector.second); }
}

void Ragdoll::draw(void) const {
  std::vector<const Hitbox*> v = getHitboxes();
  for(auto it : v) { it->draw(); }
}

bool Ragdoll::isOutOfBorders(void) {
  auto v = this->getHitboxes();
  for(const auto& it : v) {
    auto [x1, y1, x2, y2] = it->getPoints();
    if(x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) return true;
    if(x1 > GetScreenWidth() || x2 > GetScreenWidth() || y1 > GetScreenHeight() || y2 > GetScreenHeight()) return true;
  }
  return false;
}