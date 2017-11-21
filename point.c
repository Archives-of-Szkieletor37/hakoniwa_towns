#include <stdio.h>
#include "point.h"
#include <stdlib.h>

int x = 0, y = 0;
int zero = 0;
int flag_f = 0;
int flag_t = 1;


Point *point_init(int* s, int* t, int* flag) {
	Point *p = malloc(sizeof(Point));
	if (p == NULL) {
		printf("error, malloc, point_init");
	}
	p->x = s;
	p->y = t;
	p->flag = flag;
	
	return p;
}


Point *point_init_zero() {
	Point *p = malloc(sizeof(Point));
	if(p==NULL) {
		printf("error, malloc, point_init_zero");
	}

	p->x = &x;
	p->y = &y;
	p->flag = &flag_t;

	return p;
}



