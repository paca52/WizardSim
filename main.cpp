#include <iostream>
#include "raylib.h"
#include "entity.hpp"
#include "player.hpp"

const int windowW = 800,
          windowH = 464;

int main(void) {
  InitWindow(windowW, windowH, "WizardSim");
  InitAudioDevice();
  SetTargetFPS(60);

  Texture2D background = LoadTexture("textures/back.png");

  Player p(0, 0, 3);
  float timer    = 0.0f;
  int frameCount = 0;

  Music music    = LoadMusicStream("sound/music1.wav");
  music.looping  = true;

  PlayMusicStream(music);

  while(!WindowShouldClose()) {
    UpdateMusicStream(music);
    
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
  UnloadMusicStream(music);
  CloseWindow();
  CloseAudioDevice();

  return 0;
}