#ifndef WINDOW_H
#define WINDOW_H

class Component;

typedef struct _Coms {
  Component *com;
  _Coms *next;
} Coms;

class Window {
public:
  Coms *coms;

  Window(int width, int height, char const *title);
  ~Window();

  void AddCom(Component *com);
  void Run();
};

#endif // WINDOW_H
