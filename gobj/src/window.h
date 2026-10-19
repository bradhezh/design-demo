#ifndef WINDOW_H
#define WINDOW_H

#include <glib-object.h>
#include <raylib.h>

typedef struct _Com Com;

G_DECLARE_FINAL_TYPE(Win, win, WIN, OBJ, GObject)
#define WIN_TYPE (win_get_type())

Win *win_new(char const *title, Vector2 const *vec2);
void win_add_com(Win *win, Com *com);
void win_run(Win const *win);

#endif // WINDOW_H
