#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void slide_left(int *line, size_t size);

#endif /* SLIDE_LINE_H */
