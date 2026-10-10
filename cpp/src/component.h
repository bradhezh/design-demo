#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
  char *text;

  Component(char const *text);
  ~Component();

  void Render(int x, int y);
};

#endif // COMPONENT_H
