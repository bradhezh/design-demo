#ifndef COMPONENT_H
#define COMPONENT_H

#include <raylib.h>

typedef struct _Com Com;

Com *com_new(char const *text, int font_size, Rectangle const *rec);
void com_del(Com *self);
// Rectangle const *com_rec(Com const *self);
void com_render(Com const *self);

#endif // COMPONENT_H
