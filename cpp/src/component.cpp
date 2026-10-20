#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "component.h"
#include "window.h"

#define PADDING 4

Com::Com(char const *text, int font_size, int x, int y, int width, int height, Win *win) {
  this->text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
  strcpy(this->text, text);
  this->font_size = font_size;
  this->rec.x = x;
  this->rec.y = y;
  this->rec.width = width;
  this->rec.height = height;
  this->onClicked = NULL;
  win->AddCom(this);
}

Com::~Com() { free(this->text); }

void Com::Render() const {
  DrawRectangleRec(this->rec, GREEN);
  DrawText(this->text, this->rec.x + PADDING, this->rec.y + PADDING, this->font_size, BLACK);
}
