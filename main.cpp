#include <iostream>
#include "raylib.h"
#include "entity.hpp"
#include "player.hpp"

const int windowW = 800,
          windowH = 464;

int main(void) {
  InitWindow(windowW, windowH, "WizardSim");

  Texture2D text = LoadTexture("textures/IdleProba.png");
  Texture2D background = LoadTexture("textures/back.png");

  text.height *= 2;
  text.width  *= 2;

  Player p(0, 0, &text, 3);
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

    // const bool moveArr[4] = {
    //   IsKeyDown(KEY_W),
    //   IsKeyDown(KEY_A),
    //   IsKeyDown(KEY_S),
    //   IsKeyDown(KEY_D)
    // };

    p.move2(GetKeyPressed());

    // DRAW
    BeginDrawing();
      ClearBackground(BLACK);
      DrawTexture(background, 0, 0, RAYWHITE);

      p.draw(frameCount);
    EndDrawing();
  }

  UnloadTexture(text);
  UnloadTexture(background);

  CloseWindow();

  return 0;
}