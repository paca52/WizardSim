#include "entity.hpp"

// constructors
Entity::Entity() 
  :x(0), y(0), texture(nullptr), frameWidth(0), frameHeight(0) { }

Entity::Entity(double x, double y, Texture2D *texture) 
  :Entity(x, y, texture, 1) { }

Entity::Entity(double x, double y, Texture2D *texture, int numberOfFrames) 
  :texture(texture) {
  if(x < 0) {
    std::cout << "ERROR - ENTITY_CONST: X-POSITION NEGATIVE, DEFAULTING TO 0\n";
    this->x = 0;
  } else this->x = x;

  if(y < 0) {
    std::cout << "ERROR - ENTITY_CONST: Y-POSITION NEGATIVE, DEFAULTING TO 0\n";
    this->y = 0;
  } else this->y = y;

  frameWidth  = texture->width / numberOfFrames;
  frameHeight = texture->height;
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