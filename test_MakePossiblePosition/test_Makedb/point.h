// point.h
//

#ifndef _POINT_H_
#define _POINT_H_

typedef struct {
	int *x;
	int *y;
	int *flag; // 0ならfalse,1ならtrue これいらないかも
} Point;

extern Point point_zero;
extern Point point_null;

extern int flag_f, flag_t, zero;
extern Point *point_init(int s, int t);
//extern Point *point_init_null(void);
//extern Point point_init_zero(void);
#endif // _POINT_H_
