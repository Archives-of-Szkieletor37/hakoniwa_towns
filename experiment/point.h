// point.h
//

#ifndef _POINT_H_
#define _POINT_H_

typedef struct {
	int *x;
	int *y;
	int *flag;
} Point;

extern Point point_init(int s, int t);

#endif // _POINT_H_
