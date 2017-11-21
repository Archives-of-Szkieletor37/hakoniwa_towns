#include <stdio.h>
#include "point.h"



Point point_init(int s, int t) {
	
	Point hoge, *p;
	p = &hoge;
	((*p).x) = &s;
	//p.y = &t;
	//int i = 1;
	//p.flag = &i;
	
	return *p;
}
