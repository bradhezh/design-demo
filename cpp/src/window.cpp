#include <raylib.h>
#include <stdlib.h>

#include "component.h"
#include "window.h"

struct _ComNode {
  Com *com;
  struct _ComNode *next;
};

Win::Win(char const *title, int width, int height) {
  this->nodes = NULL;
  InitWindow(width, height, title);
}

Win::~Win() {
  CloseWindow();
  for (ComNode *p = this->nodes; p;) {
    ComNode *node = p;
    p = p->next;
    free(node);
  }
}

void Win::AddCom(Com *com) {
  ComNode *node = (ComNode *)malloc(sizeof(ComNode));
  node->com = com;
  node->next = NULL;
  if (!this->nodes) {
    this->nodes = node;
    return;
  }
  ComNode *p = this->nodes;
  for (; p->next; p = p->next)
    ;
  p->next = node;
}

void Win::Run() const {
  EnableEventWaiting();
  while (!WindowShouldClose()) {
    // Event
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Vector2 pos = GetMousePosition();
      for (ComNode *p = this->nodes; p; p = p->next) {
        if (CheckCollisionPointRec(pos, p->com->rec) && p->com->onClicked) {
          p->com->onClicked();
        }
      }
    }
    // Render
    BeginDrawing();
    ClearBackground(WHITE);
    for (ComNode *p = this->nodes; p; p = p->next) {
      p->com->Render();
    }
    EndDrawing();
  }
}
