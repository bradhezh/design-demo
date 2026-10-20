#include <raylib.h>

#include "component.h"

#define FONT_SIZE 20
#define WIDTH 200
#define HEIGHT 60
#define MARGIN 8

int main(int argc, char *argv[]) {
  void *com1 = com_new("Component 1", FONT_SIZE, &(Rectangle){MARGIN, MARGIN, WIDTH, HEIGHT});
  void *com2 =
      com_new("Component 2", FONT_SIZE, &(Rectangle){MARGIN, HEIGHT + MARGIN * 2, WIDTH, HEIGHT});

  InitWindow(WIDTH + MARGIN * 2, HEIGHT * 2 + MARGIN * 3, "Components");
  EnableEventWaiting();
  while (!WindowShouldClose()) {
    /* Event
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Vector2 pos = GetMousePosition();
      // Reusable across different instances
      if (CheckCollisionPointRec(pos, *com_rec(com1))) {
        TraceLog(LOG_INFO, "Component 1 clicked");
      } else if (CheckCollisionPointRec(pos, *com_rec(com2))) {
        TraceLog(LOG_INFO, "Component 2 clicked");
      }
    }
    */
    // Render
    BeginDrawing();
    ClearBackground(WHITE);
    // Reusable across different instances
    com_render(com1);
    com_render(com2);
    EndDrawing();
  }
  CloseWindow();

  // Reusable across different instances
  com_del(com1);
  com_del(com2);
  return 0;
}
