#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main() {

	int s = -73, t = 17; //u = 89;

//	Point p = point_init(s,t);
//	Point *pp = &p;
	//pp= &p;
	Point *pp = point_init(s,t);

	printf("%d\n", *(pp->x));

	free(pp);

	return 0;
}


