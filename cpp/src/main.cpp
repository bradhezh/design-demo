#include "component.h"
#include "window.h"

#define FONT_SIZE 20
#define WIDTH 200
#define HEIGHT 60
#define MARGIN 8

int main(void) {
  Window win(WIDTH + MARGIN * 2, HEIGHT * 2 + MARGIN * 3, "Components");
  Component com1("Component 1", FONT_SIZE, MARGIN, MARGIN, WIDTH, HEIGHT, &win);
  Component com2("Component 2", FONT_SIZE, MARGIN, HEIGHT + MARGIN * 2, WIDTH, HEIGHT, &win);

  win.Run();

  return 0;
}
