// building.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "building.h"

int list_B_length[11] = {0,1,2,3,4,5,6,7,8,9,10};

//Building building_null = {"null", point_zero, NULL, NULL, NULL};

Building building_init(char* name, Point point, int length, int width) {

	Building B_object;

	strcpy(B_object.B_name, name);
	B_object.B_left_bottom_point = point;
	B_object.B_length = length;
	B_object.B_width = width;

	if ((B_object.B_length) != (B_object.B_width)) {
		B_object.B_rotate = &flag_t;
	}
	else {
		B_object.B_rotate = &flag_f;
	}

	return B_object;

}

Building building_null(void) {
	Building b;
	strcpy(b.B_name, "init");
	b.id = -1;
	b.B_left_bottom_point = point_init(0,0,0);
	b.B_length = -1;
	b.B_width = -1;
	b.B_rotate = NULL;

	return b;
}
/*
int *return_pointer_to_length(int B_length) {
	
	int *p = NULL;

	switch(B_length) {
		case 1 : p = list_B_length + 1; break;
		case 2 : p = list_B_length + 2; break;
		case 4 : p = list_B_length + 4; break;
		case 6 : p = list_B_length + 6; break;
		case 8 : p = list_B_length + 8; break;
		case 10 : p = list_B_length + 10; break;
		default : break;
	}

	return p;
}
*/
void free_building(Building *b) {

	//free(b->B_left_bottom_point);
	free(b);

}

