#ifndef COMPONENT_H
#define COMPONENT_H

#include <raylib.h>

class Component {
public:
  char *text;
  int fontSize;
  Rectangle rec;

  Component(char const *text, int fontSize, int x, int y, int width, int height);
  ~Component();

  // void Rec(Rectangle *rec);

  void Render();
};

#endif // COMPONENT_H
