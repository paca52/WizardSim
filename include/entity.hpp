#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "raylib.h"
#include <iostream>

class Entity {
protected:
  double x, y;
  Texture2D *texture;
public:
  Entity();
  Entity(double x, double y, Texture2D *texture);
  Entity(const Entity& e);
  virtual void draw(void);
  ~Entity();
};

#endif // ENTITY_HPP