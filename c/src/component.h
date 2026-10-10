#ifndef COMPONENT_H
#define COMPONENT_H

void *ComNew(char const *text);
void ComDelete(void *com);

void ComRender(void *com, int x, int y);

#endif // COMPONENT_H
