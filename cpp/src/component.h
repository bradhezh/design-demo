#ifndef COMPONENT_H
#define COMPONENT_H

#include <raylib.h>

class Window;

class Component {
public:
  char *text;
  int fontSize;
  Rectangle rec;

  void (*onClick)();

  Component(char const *text, int fontSize, int x, int y, int width, int height, Window *win);
  ~Component();

  void Render();
};

#endif // COMPONENT_H
