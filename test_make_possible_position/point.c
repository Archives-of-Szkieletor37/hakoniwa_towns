#include <stdio.h>
#include "point.h"
#include <stdlib.h>

int x = 0, y = 0;
int zero = 0;
int flag_f = 0;
int flag_t = 1;

//Point point_zero = {&x, &y};
//Point *p_point_zero = &point_zero;
//Point point_null = {NULL, NULL};
//Point *p_point_null = &point_null;

//static int point_reference[150] = {-74 ,-73 ,-72 ,-71 ,-70 ,-69 ,-68 ,-67 ,-66 ,-65 ,-64 ,-63 ,-62 ,-61 ,-60 ,-59 ,-58 ,-57 ,-56 ,-55 ,-54 ,-53 ,-52 ,-51 ,-50 ,-49 ,-48 ,-47 ,-46 ,-45 ,-44 ,-43 ,-42 ,-41 ,-40 ,-39 ,-38 ,-37 ,-36 ,-35 ,-34 ,-33 ,-32 ,-31 ,-30 ,-29 ,-28 ,-27 ,-26 ,-25 ,-24 ,-23 ,-22 ,-21 ,-20 ,-19 ,-18 ,-17 ,-16 ,-15 ,-14 ,-13 ,-12 ,-11 ,-10 ,-9 ,-8 ,-7 ,-6 ,-5 ,-4 ,-3 ,-2 ,-1 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 ,11 ,12 ,13 ,14 ,15 ,16 ,17 ,18 ,19 ,20 ,21 ,22 ,23 ,24 ,25 ,26 ,27 ,28 ,29 ,30 ,31 ,32 ,33 ,34 ,35 ,36 ,37 ,38 ,39 ,40 ,41 ,42 ,43 ,44 ,45 ,46 ,47 ,48 ,49 ,50 ,51 ,52 ,53 ,54 ,55 ,56 ,57 ,58 ,59 ,60 ,61 ,62 ,63 ,64 ,65 ,66 ,67 ,68 ,69 ,70 ,71 ,72 ,73 ,74 ,75};

/*void point_reference_init(void) {

	int i; 

	for(i=0; i<150, i++) {
		point_refernce[i] = i - 74;
	}

}*/

Point point_init(int s, int t, int flag) {

	//Point p; //= malloc(sizeof(Point));

	Point p; //= malloc(sizeof(Point));

	if(s < -74 || t < -74 || s > 75 || t > 75) {
		//pp->x = NULL;
		//pp->y = NULL;
		//pp->flag = &flag_f;
		p.x = 0;
		p.y = 0;
		p.flag = 0;
	}

	else {
		p.x = s;
		p.y = t;
		p.flag = flag;
		//pp->x = (point_reference + (s+74));
		//pp->y = (point_reference + (t+74));
		//pp->flag = &flag_t;
	}

	return p;

}
/*
Point *point_init(int s, int t) {

	Point p; //= malloc(sizeof(Point));

	Point *pp = &p;

	if(s < -74 || t < -74 || s > 75 || t > 75) {
		p.x = NULL;
		p.y = NULL;
		p.flag = &flag_f;
	}

	else {
		p.x = (point_reference + (s+74));
		p.y = (point_reference + (t+74));
		p.flag = &flag_t;
	}

	return pp;

}
*/
/*
Point *point_init_null(void) {

	Point *p = malloc(sizeof(Point));
	if (p == NULL) {
		printf("error, malloc, point_init");
	}
	p->x = NULL;
	p->y = NULL;
	p->flag = &flag_f;
	
	return p;
}


Point point_init_zero() {
	Point p;
*	if(p==NULL) {
		printf("error, malloc, point_init_zero");
	}
*
	p.x = &x;
	p.y = &y;
	p.flag = &flag_t;

	return p;
}


*/
