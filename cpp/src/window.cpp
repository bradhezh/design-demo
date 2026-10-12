#include <raylib.h>
#include <stdlib.h>

#include "component.h"
#include "window.h"

Window::Window(int width, int height, char const *title) {
  this->coms = NULL;
  InitWindow(width, height, title);
}

Window::~Window() {
  for (Coms *p = coms; p;) {
    Coms *p0 = p;
    p = p0->next;
    free(p0);
  }
  CloseWindow();
}

void Window::AddCom(Component *com) {
  Coms *p0 = (Coms *)malloc(sizeof(Coms));
  p0->com = com;
  p0->next = NULL;
  if (!coms) {
    coms = p0;
    return;
  }
  Coms *p = coms;
  for (; p->next; p = p->next)
    ;
  p->next = p0;
}

void Window::Run() {
  EnableEventWaiting();
  while (!WindowShouldClose()) {
    /* Event
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Vector2 pos = GetMousePosition();
      for (Coms *p = coms; p; p = p->next) {
        if (CheckCollisionPointRec(pos, p->com->rec)) {
          TraceLog(LOG_INFO, "%s clicked", p->com->text);
        }
      }
    }
    */
    // Render
    BeginDrawing();
    ClearBackground(WHITE);
    for (Coms *p = coms; p; p = p->next) {
      p->com->Render();
    }
    EndDrawing();
  }
}
