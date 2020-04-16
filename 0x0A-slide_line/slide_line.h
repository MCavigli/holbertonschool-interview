#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2
#include <stdlib.h>

void print_array(int const *array, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
