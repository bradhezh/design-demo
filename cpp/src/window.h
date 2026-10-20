#ifndef WINDOW_H
#define WINDOW_H

class Com;
typedef struct _ComNode ComNode;

class Win {
public:
  ComNode *nodes;

  Win(char const *title, int width, int height);
  ~Win();
  void AddCom(Com *com);
  void Run() const;
};

#endif // WINDOW_H
