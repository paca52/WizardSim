#include "level.hpp"
#include "raylib.h"

Level::Level(int height, int width) :Level(height, width, 32, 32) { }

Level::Level(int height, int width, int tileWidth, int tileHeight)
:currLevel(1), height(height), width(width), tileWidth(tileWidth), tileHeight(tileHeight), data(height, std::vector<char>(width)) {
  std::fstream file("util/levels/level" + std::to_string(currLevel));
  std::string str;

  for(int i=0; i<height/tileHeight; ++i) {
    for(int j=0; j<width/tileWidth; ++j) {
      file >> str;
      data[i][j] = str[0];
    }
  }

  while(file >> str) { walkableTiles.insert(str[0]); }  
}

std::pair<int, int> Level::tileIndex(float x, float y) const {
  return {
    x / tileWidth,
    y / tileHeight
  };
}

bool Level::isWalkable(const Ragdoll& ragdoll) const {
  auto valid = [&](std::pair<float, float> p) {
    auto [j, i] = p;
    return
      (int)j <= ( width / tileWidth ) &&
      (int)i <= ( height / tileHeight ) &&
      (int)i >= 0 &&
      (int)j >= 0 &&
      walkableTiles.find(data[i][j]) != walkableTiles.end();
  };

  auto v = ragdoll.getHitboxes();
  for(const auto& box : v) {
    auto [x1, y1, x2, y2] = box->getPoints();

    if(
      !valid(tileIndex(x1, y1)) ||
      !valid(tileIndex(x1, y2)) ||
      !valid(tileIndex(x2, y1)) ||
      !valid(tileIndex(x2, y2))
    ) return false;
  }
    
  return true;
}

void Level::printData(void) const {
  for(int i=0; i<height/tileWidth; ++i) {
    for(int j=0; j<width/tileHeight; ++j) {
      std::cout << data[i][j] << ' ';
    }
    std::cout << '\n';
  }

  std::cout << "walkable tiles: ";
  for(auto it : walkableTiles) {
    std::cout << it << " ";
  }
  std::cout << "\n";
}

void Level::drawData(void) const {
  for(int i=0; i<height/tileHeight; ++i) {
    for(int j=0; j<width/tileWidth; ++j) {
      std::string s = "";
      s += data[i][j];
      DrawText(s.c_str(), j * tileWidth, i * tileHeight, 20, RED);
    }
  }
}