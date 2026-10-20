#ifndef COMPONENT_H
#define COMPONENT_H

#include <raylib.h>

class Win;

class Com {
public:
  char *text;
  int font_size;
  Rectangle rec;

  void (*onClicked)();

  Com(char const *text, int font_size, int x, int y, int width, int height, Win *win);
  ~Com();
  void Render() const;
};

#endif // COMPONENT_H
