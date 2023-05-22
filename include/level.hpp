#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include "ragdoll.hpp"

class Level {
  int currLevel,
      height,
      width,
      tileWidth,
      tileHeight;
  std::vector<std::vector<char>> data;
  std::unordered_set<char> walkableTiles;
public:
  Level(int height, int width);
  Level(int height, int width, int tileWidth, int tileHeight);
  std::pair<int, int> tileIndex(float x, float y) const;
  bool isWalkable(const Ragdoll& ragdoll) const;

  // debugging functions
  void printData(void) const;
  void drawData(void) const;
};

#endif // LEVEL_HPP