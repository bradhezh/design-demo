#include <raylib.h>

#include "component.h"

#define WIDTH 200
#define HEIGHT 60

int main(void) {
  InitWindow(WIDTH, HEIGHT, "Component");
  void *com = ComNew("Component");

  EnableEventWaiting();
  while (!WindowShouldClose()) {
    // Event
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      TraceLog(LOG_INFO, "Clicked!");
    }
    // Render
    BeginDrawing();
    ClearBackground(WHITE);
    ComRender(com, 0, 0);
    EndDrawing();
  }

  ComDelete(com);
  CloseWindow();
  return 0;
}
