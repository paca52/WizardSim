#include <iostream>
#include "raylib.h"
#include "entity.hpp"
#include "player.hpp"

const int windowW = 800,
          windowH = 464;

int main(void) {
  InitWindow(windowW, windowH, "WizardSim");
  SetTargetFPS(60);

  Texture2D background = LoadTexture("textures/back.png");

  Player p(0, 0, 3);
  float timer = 0.0f;
  int frameCount = 0;

  while(!WindowShouldClose()) {

    // UPDATE
    timer += GetFrameTime();

    // count frames every ~1/4s
    if(timer > 0.3f) {
      timer = 0;
      frameCount += 1;
    }

    // wrap frames around
    frameCount %= 30;

    p.move(GetKeyPressed());

    // DRAW
    BeginDrawing();
      ClearBackground(BLACK);
      DrawTexture(background, 0, 0, RAYWHITE);
      DrawFPS(0, 0);

      p.draw(frameCount);
    EndDrawing();
  }

  UnloadTexture(background);

  CloseWindow();

  return 0;
}