#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "component.h"

#define FONT_SIZE 20

Component::Component(char const *text) {
  this->text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
  strcpy(this->text, text);
}

Component::~Component() { free(this->text); }

void Component::Render(int x, int y) {
  DrawText(this->text, x, y, FONT_SIZE, BLACK);
}
