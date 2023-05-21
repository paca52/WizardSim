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

std::pair<int, int> Level::tileIndex(float x, float y) const {
  return {
    x / tileWidth,
    y / tileHeight
  };
}

bool Level::isWalkable(float x, float y) const {
  auto [j, i] = tileIndex(x, y);
  // std::cout << "(i, j) = (" << i << ", " << j << "); data[i][j] = " << data[i][j] << "\n";
  std::cout << "currently on: (" << i << ", " << j << ") = " << data[i][j] << "\n";
  return
    (int)j <= ( width / tileWidth ) &&
    (int)i <= ( height / tileHeight ) &&
    (int)i >= 0 &&
    (int)j >= 0 &&
    walkableTiles.find(data[i][j]) != walkableTiles.end();
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