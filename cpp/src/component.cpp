#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "component.h"
#include "window.h"

#define PADDING 4

Component::Component(
    char const *text, int fontSize, int x, int y, int width, int height, Window *win) {
  this->text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
  strcpy(this->text, text);
  this->fontSize = fontSize;
  this->rec.x = x;
  this->rec.y = y;
  this->rec.width = width;
  this->rec.height = height;
  win->AddCom(this);
}

Component::~Component() { free(this->text); }

void Component::Render() {
  DrawRectangleRec(this->rec, GREEN);
  DrawText(this->text, this->rec.x + PADDING, this->rec.y + PADDING, this->fontSize, BLACK);
}
