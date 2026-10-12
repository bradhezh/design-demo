#ifndef COMPONENT_H
#define COMPONENT_H

//#include <raylib.h>

void *ComNew(char const *text, int fontSize, int x, int y, int width, int height);
void ComDelete(void *com);

// Rectangle *ComRec(void *com);

void ComRender(void *com);

#endif // COMPONENT_H
