#include <raylib.h>

#include "component.h"

int main(void) {
  SetTargetFPS(60);

  InitWindow(640, 480, "Canvas");
  void *com = ComNew("Component");

  while (!WindowShouldClose()) {
    // Event

    // Render
    BeginDrawing();
    ClearBackground(WHITE);
    ComRender(com, 10, 10);
    EndDrawing();
  }

  ComDelete(com);
  CloseWindow();
  return 0;
}
