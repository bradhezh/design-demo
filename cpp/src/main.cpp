#include "component.h"
#include "window.h"

#define FONT_SIZE 20
#define WIDTH 200
#define HEIGHT 60
#define MARGIN 8

void onCom1Clicked() { TraceLog(LOG_INFO, "Business triggered by com1 clicked"); }

void onCom2Clicked() { TraceLog(LOG_INFO, "Business triggered by com2 clicked"); }

int main(int argc, char *argv[]) {
  Win win("Components", WIDTH + MARGIN * 2, HEIGHT * 2 + MARGIN * 3);
  Com com1("Component 1", FONT_SIZE, MARGIN, MARGIN, WIDTH, HEIGHT, &win);
  Com com2("Component 2", FONT_SIZE, MARGIN, HEIGHT + MARGIN * 2, WIDTH, HEIGHT, &win);

  com1.onClicked = onCom1Clicked;
  com2.onClicked = onCom2Clicked;

  win.Run();

  return 0;
}
