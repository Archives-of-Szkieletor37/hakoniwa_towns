// building.h

#ifndef _BUILDING_H_
#define _BUILDING_H_
#include "point.h"

typedef struct {
	
	int id;
	char B_name[100];
	Point B_left_bottom_point;
	int B_length;
	int B_width;	
	int* B_rotate;

} Building;

//extern Building building_null;

extern Building building_init(char* name, Point point, int length, int width);
extern Building building_null(void);

//extern int *return_pointer_to_length(int B_length);
extern void free_building(Building *b);
#endif // _BUILDING_H_
