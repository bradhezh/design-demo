#include <raylib.h>

#include "component.h"

#define FONT_SIZE 20
#define WIDTH 200
#define HEIGHT 60
#define MARGIN 8

int main(void) {
  InitWindow(WIDTH + MARGIN * 2, HEIGHT * 2 + MARGIN * 3, "Components");
  // Reusable across different data of the type
  void *com1 = ComNew("Component 1", FONT_SIZE, MARGIN, MARGIN, WIDTH, HEIGHT);
  void *com2 = ComNew("Component 2", FONT_SIZE, MARGIN, HEIGHT + MARGIN * 2, WIDTH, HEIGHT);

  EnableEventWaiting();
  while (!WindowShouldClose()) {
    /* Event
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Rectangle rec1, rec2;
      ComRec(com1, &rec1);
      ComRec(com2, &rec2);
      Vector2 pos = GetMousePosition();
      if (CheckCollisionPointRec(pos, rec1)) {
        TraceLog(LOG_INFO, "Component 1 clicked!");
      } else if (CheckCollisionPointRec(pos, rec2)) {
        TraceLog(LOG_INFO, "Component 2 clicked!");
      }
    }
    */
    // Render
    BeginDrawing();
    ClearBackground(WHITE);
    // Reusable across different data of the type
    ComRender(com1);
    ComRender(com2);
    EndDrawing();
  }

  // Reusable across different data of the type
  ComDelete(com1);
  ComDelete(com2);
  CloseWindow();
  return 0;
}
