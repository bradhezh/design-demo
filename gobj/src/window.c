#include <glib-object.h>
#include <raylib.h>

#include "component.h"
#include "window.h"

typedef struct _ComNode {
  Com *com;
  struct _ComNode *next;
} ComNode;

struct _Win {
  GObject parent_instance;

  ComNode *nodes;
};

G_DEFINE_TYPE(Win, win, G_TYPE_OBJECT)

static void win_finalize(GObject *obj) {
  CloseWindow();
  Win *self = WIN_OBJ(obj);
  for (ComNode *p = self->nodes; p;) {
    ComNode *node = p;
    p = p->next;
    g_object_unref(node->com);
    g_free(node);
  }
  G_OBJECT_CLASS(win_parent_class)->finalize(obj);
}

static void win_class_init(WinClass *klass) {
  GObjectClass *gobj_class = G_OBJECT_CLASS(klass);
  gobj_class->finalize = win_finalize;
}

static void win_init(Win *self) { self->nodes = NULL; }

Win *win_new(char const *title, Vector2 const *vec2) {
  g_return_val_if_fail(title && vec2, NULL);
  Win *win = WIN_OBJ(g_object_new(WIN_TYPE, NULL));
  InitWindow(vec2->x, vec2->y, title);
  return win;
}

void win_add_com(Win *self, Com *com) {
  g_return_if_fail(self && com);
  ComNode *node = g_malloc(sizeof(ComNode));
  node->com = g_object_ref_sink(com);
  node->next = NULL;
  if (!self->nodes) {
    self->nodes = node;
    return;
  }
  ComNode *p = self->nodes;
  for (; p->next; p = p->next)
    ;
  p->next = node;
}

void win_run(Win const *self) {
  g_return_if_fail(self);
  EnableEventWaiting();
  while (!WindowShouldClose()) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Vector2 pos = GetMousePosition();
      for (ComNode *p = self->nodes; p; p = p->next) {
        if (CheckCollisionPointRec(pos, *com_rec(p->com))) {
          com_clicked(p->com);
        }
      }
    }
    BeginDrawing();
    ClearBackground(WHITE);
    for (ComNode *p = self->nodes; p; p = p->next) {
      com_render(p->com);
    }
    EndDrawing();
  }
}
