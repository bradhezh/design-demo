#ifndef COMPONENT_H
#define COMPONENT_H

//#include <raylib.h>

void *ComNew(char const *text, int fontSize, int x, int y, int width, int height);
void ComDelete(void *com);

// void ComRec(void *com, Rectangle *rec);

void ComRender(void *com);

#endif // COMPONENT_H
