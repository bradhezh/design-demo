#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "component.h"

#define PADDING 4

struct _Com {
  char *text;
  int font_size;
  Rectangle rec;
};

Com *com_new(char const *text, int font_size, Rectangle const *rec) {
  Com *com = malloc(sizeof(Com));
  com->text = malloc(sizeof(char) * (strlen(text) + 1));
  strcpy(com->text, text);
  com->font_size = font_size;
  com->rec = *rec;
  return com;
}

void com_del(Com *self) {
  free(self->text);
  free(self);
}

// Rectangle const *com_rec(Com const *self) { return &self->rec; }

void com_render(Com const *self) {
  DrawRectangleRec(self->rec, GREEN);
  DrawText(self->text, self->rec.x + PADDING, self->rec.y + PADDING, self->font_size, BLACK);
}
