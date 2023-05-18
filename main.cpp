#include <iostream>
#include "raylib.h"
#include "entity.hpp"
#include "player.hpp"

const int windowH = 800,
          windowW = 450;

int main(void) {
  InitWindow(windowH, windowW, "very nice game :)");

  Texture2D text = LoadTexture("textures/Mario.png");
  text.height *= 2;
  text.width  *= 2;

  Player p(windowH/2, windowW/2, &text);

  while(!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(BLACK);

      const bool moveArr[4] = {
        IsKeyDown(KEY_W),
        IsKeyDown(KEY_A),
        IsKeyDown(KEY_S),
        IsKeyDown(KEY_D)
      };
      p.move(moveArr);

      p.draw();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}