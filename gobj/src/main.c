#include "component.h"
#include "raylib.h"
#include "window.h"

#define FONT_SIZE 20
#define WIDTH 200
#define HEIGHT 60
#define MARGIN 8

static gboolean business1a(Com *com, gchar const *emission, gpointer user_data) {
  TraceLog(LOG_INFO,
           "Business 1a triggered at %f with %s via %s",
           com_rec(com)->y,
           emission,
           (char *)user_data);
  return FALSE;
}

static gboolean business1b(Com *com, gchar const *emission, gpointer user_data) {
  TraceLog(LOG_INFO,
           "Business 1b triggered at %f with %s via %s",
           com_rec(com)->y,
           emission,
           (char *)user_data);
  return FALSE;
}

static gboolean business2(Com *com, gchar const *emission, gpointer user_data) {
  TraceLog(LOG_INFO, "Business 2 triggered at %f with %s", com_rec(com)->y, emission);
  return FALSE;
}

int main(int argc, char *argv[]) {
  Win *win = win_new("Components", &(Vector2){WIDTH + MARGIN * 2, HEIGHT * 2 + MARGIN * 3});
  Com *com1 = com_new("Component 1", FONT_SIZE, &(Rectangle){MARGIN, MARGIN, WIDTH, HEIGHT}, win);
  Com *com2 = com_new(
      "Component 2", FONT_SIZE, &(Rectangle){MARGIN, HEIGHT + MARGIN * 2, WIDTH, HEIGHT}, win);

  g_signal_connect(com1, ON_CLICKED, G_CALLBACK(business1a), (gpointer) "connection a");
  g_signal_connect(com1, ON_CLICKED, G_CALLBACK(business1b), (gpointer) "connection b");
  g_signal_connect(com2, ON_CLICKED, G_CALLBACK(business2), NULL);

  win_run(win);

  g_object_unref(win);
  return 0;
}
