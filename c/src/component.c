#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "component.h"

#define FONT_SIZE 20

typedef struct {
  char *text;
} Component;

void *ComNew(char const *text) {
  Component *com = malloc(sizeof(Component));

  com->text = malloc(sizeof(char) * (strlen(text) + 1));
  strcpy(com->text, text);

  return com;
}

void ComDelete(void *com) {
  free(((Component *)com)->text);
  free(com);
}

void ComRender(void *com, int x, int y) {
  DrawText(((Component *)com)->text, x, y, FONT_SIZE, BLACK);
}
