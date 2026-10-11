#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "component.h"

#define PADDING 4

typedef struct {
  char *text;
  int fontSize;
  Rectangle rec;
} Component;

void *ComNew(char const *text, int fontSize, int x, int y, int width, int height) {
  Component *com = malloc(sizeof(Component));

  com->text = malloc(sizeof(char) * (strlen(text) + 1));
  strcpy(com->text, text);
  com->fontSize = fontSize;
  com->rec.x = x;
  com->rec.y = y;
  com->rec.width = width;
  com->rec.height = height;

  return com;
}

void ComDelete(void *com) {
  free(((Component *)com)->text);
  free(com);
}

// void ComRec(void *com, Rectangle *rec) { memcpy(rec, &((Component *)com)->rec,
// sizeof(Rectangle)); }

void ComRender(void *com) {
  Component *com0 = com;
  DrawRectangleRec(com0->rec, GREEN);
  DrawText(com0->text, com0->rec.x + PADDING, com0->rec.y + PADDING, com0->fontSize, BLACK);
}
