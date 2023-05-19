#include "entity.hpp"

// constructors
Entity::Entity() 
  :Entity(0, 0, nullptr, 0) { }

Entity::Entity(double x, double y, Texture2D *texture) 
  :Entity(x, y, texture, 1) { }

Entity::Entity(double x, double y) 
  :Entity(x, y, nullptr, 0) { }

Entity::Entity(double x, double y, int numberOfFrames) 
  :Entity(x, y, nullptr, numberOfFrames) { }

Entity::Entity(double x, double y, Texture2D *texture, int numberOfFrames) 
  :texture(texture), numberOfFrames(numberOfFrames) {
  if(x < 0) {
    std::cout << "ERROR - ENTITY_CONST: X-POSITION NEGATIVE, DEFAULTING TO 0\n";
    this->x = 0;
  } else {
    this->x = x;
  }

  if(y < 0) {
    std::cout << "ERROR - ENTITY_CONST: Y-POSITION NEGATIVE, DEFAULTING TO 0\n";
    this->y = 0;
  } else {
    this->y = y;
  }

  if(texture != nullptr) {
    frameWidth  = texture->width / numberOfFrames;
    frameHeight = texture->height;
  } else {
    frameWidth = 0;
    frameHeight = 0;
  }
}

Entity::Entity(const Entity& e) {
  this->x           = e.x;
  this->y           = e.y;
  this->texture     = e.texture;
  this->frameWidth  = e.frameWidth;
  this->frameHeight = e.frameHeight;
}

// functions
void Entity::draw(void) {
  DrawTexture(
    *(this->texture),
    this->x,
    this->y,
    RAYWHITE
  );
}


// Destructor
Entity::~Entity() { }