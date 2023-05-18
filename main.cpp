#include <iostream>
#include "raylib.h"
#include "entity.hpp"
#include "player.hpp"

const int windowW = 800,
          windowH = 464;

int main(void) {
  InitWindow(windowW, windowH, "WizardSim");

  Texture2D text = LoadTexture("textures/BoljiCarobnjak.png");
  Texture2D background = LoadTexture("textures/back.png");

  text.height *= 2;
  text.width  *= 2;

  Player p(windowW/2, windowH/2, &text);

  while(!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(BLACK);
      DrawTexture(background, 0, 0, RAYWHITE);

      const bool moveArr[4] = {
        IsKeyDown(KEY_W),
        IsKeyDown(KEY_A),
        IsKeyDown(KEY_S),
        IsKeyDown(KEY_D)
      };
      p.move2(GetKeyPressed());

      p.draw();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}