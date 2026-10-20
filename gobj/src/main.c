#include <raylib.h>

#include "component.h"
#include "window.h"

#define FONT_SIZE 20
#define WIDTH 200
#define HEIGHT 60
#define MARGIN 8

static gboolean on_com1_clicked_0(Com *com, gchar const *emission, gpointer user_data) {
  g_return_val_if_fail(com && emission && user_data, FALSE);
  TraceLog(LOG_INFO,
           "Business 0 triggered by com1 clicked at %f with %s via %s",
           com_rec(com)->y,
           emission,
           (char *)user_data);
  return FALSE;
}

static gboolean on_com1_clicked_1(Com *com, gchar const *emission, gpointer user_data) {
  g_return_val_if_fail(com && emission && user_data, FALSE);
  TraceLog(LOG_INFO,
           "Business 1 triggered by com1 clicked at %f with %s via %s",
           com_rec(com)->y,
           emission,
           (char *)user_data);
  return FALSE;
}

static gboolean on_com2_clicked(Com *com, gchar const *emission, gpointer user_data) {
  g_return_val_if_fail(com && emission, FALSE);
  TraceLog(LOG_INFO, "Business triggered by com2 clicked at %f with %s", com_rec(com)->y, emission);
  return FALSE;
}

int main(int argc, char *argv[]) {
  Win *win = win_new("Components", &(Vector2){WIDTH + MARGIN * 2, HEIGHT * 2 + MARGIN * 3});
  Com *com1 = com_new("Component 1", FONT_SIZE, &(Rectangle){MARGIN, MARGIN, WIDTH, HEIGHT}, win);
  Com *com2 = com_new(
      "Component 2", FONT_SIZE, &(Rectangle){MARGIN, HEIGHT + MARGIN * 2, WIDTH, HEIGHT}, win);

  g_signal_connect(com1, ON_CLICKED, G_CALLBACK(on_com1_clicked_0), (gpointer) "connection a");
  g_signal_connect(com1, ON_CLICKED, G_CALLBACK(on_com1_clicked_1), (gpointer) "connection b");
  g_signal_connect(com2, ON_CLICKED, G_CALLBACK(on_com2_clicked), NULL);

  win_run(win);

  g_object_unref(win);
  return 0;
}
