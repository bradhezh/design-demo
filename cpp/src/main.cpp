#include "component.h"
#include "window.h"

#define FONT_SIZE 20
#define WIDTH 200
#define HEIGHT 60
#define MARGIN 8

void Business1() { TraceLog(LOG_INFO, "Business 1"); }

void Business2() { TraceLog(LOG_INFO, "Business 2"); }

int main(void) {
  Window win(WIDTH + MARGIN * 2, HEIGHT * 2 + MARGIN * 3, "Components");
  Component com1("Component 1", FONT_SIZE, MARGIN, MARGIN, WIDTH, HEIGHT, &win);
  Component com2("Component 2", FONT_SIZE, MARGIN, HEIGHT + MARGIN * 2, WIDTH, HEIGHT, &win);

  com1.onClick = Business1;
  com2.onClick = Business2;

  win.Run();

  return 0;
}
