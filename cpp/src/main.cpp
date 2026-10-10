#include <raylib.h>

#include "component.h"

#define WIDTH 200
#define HEIGHT 60

int main(void) {
  InitWindow(WIDTH, HEIGHT, "Component");
  Component com("Component");

  EnableEventWaiting();
  while (!WindowShouldClose()) {
    // Event
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      TraceLog(LOG_INFO, "Clicked!");
    }
    // Render
    BeginDrawing();
    ClearBackground(WHITE);
    com.Render(0, 0);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
