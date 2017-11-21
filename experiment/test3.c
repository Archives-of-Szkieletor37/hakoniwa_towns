#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main() {

	Point hoge;//, *point;
	//point = &hoge;
	hoge = point_init(0,0);

	printf("%d %d\n", *(hoge.x), *(hoge.y));
	

	return 0;

}
