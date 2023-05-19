#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "raylib.h"
#include <iostream>

class Entity {
protected:
  double x, y;
  Texture2D *texture;
  float frameWidth, frameHeight;
  int numberOfFrames;
public:
  Entity();
  Entity(double x, double y);
  Entity(double x, double y, int numberOfFrames);
  Entity(double x, double y, Texture2D *texture);
  Entity(double x, double y, Texture2D *texture, int numberOfFrames);
  Entity(const Entity& e);
  virtual void draw(void);
  ~Entity();
};

#endif // ENTITY_HPP