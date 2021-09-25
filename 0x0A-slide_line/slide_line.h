#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *, size_t, int);

int slide_line_left(int *, size_t);
int slide_line_right(int *, size_t);

#endif /* _SLIDE_LINE_H_ */
