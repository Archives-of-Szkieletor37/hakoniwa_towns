#include "possible_relative_position.h"
#include "print_prp.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

int min(int x, int y, int z) {

	int piyo;

	piyo = x < y ? x : y;
	piyo = piyo < z ? piyo : z;

	return piyo;

}

int max(int x, int y, int z) {

	int hoge;

	hoge = x > y ? x : y;
	hoge = hoge > z ? hoge : z;

	return hoge;

}
void print_prp(Building* B_mainb, Possible_Relative_Position prp) {

	int x_mainb = B_mainb->B_left_bottom_point.x, y_mainb = B_mainb->B_left_bottom_point.y;
	int x_e1 = prp.b_e1->B_left_bottom_point.x, y_e1 = prp.b_e1->B_left_bottom_point.y;
	int x_e2 = prp.b_e2->B_left_bottom_point.x, y_e2 = prp.b_e2->B_left_bottom_point.y;
	int l_mainb = B_mainb->B_length, w_mainb = B_mainb->B_width;
	int l_e1 = prp.b_e1->B_length, w_e1 = prp.b_e1->B_width;
	int l_e2 = prp.b_e2->B_length, w_e2 = prp.b_e2->B_width;

	int min_coordinate_x = min(x_mainb, x_e1, x_e2);
	int max_coordinate_x = max(x_mainb+w_mainb, x_e1+w_e1, x_e2+w_e2);

	int min_coordinate_y = min(y_mainb, y_e1, y_e2);
	int max_coordinate_y = max(y_mainb+l_mainb, y_e1+l_e1, y_e2+l_e2);

	int w_area = (max_coordinate_x - min_coordinate_x)+10;
	int l_area = (max_coordinate_y - min_coordinate_y)+10;

	//char ***area = malloc(sizeof(char**[50])* w_area);

	int i,j;
	
	char (***area) = (char***)malloc(sizeof(char**) * l_area);

	for(i=0; i<l_area; i++) {
		area[i] = (char**)malloc(sizeof(char*) * w_area);
	}

	for(i=0; i<l_area; i++) {
		for(j=0; j<w_area; j++) {
			area[i][j] = (char*) malloc(sizeof(char) * 50);
			strcpy(area[i][j], "null");
		}
	}
	
	/*for (i=0; i<w_area; i++) {
		text[i] = malloc(sizeof(char) * 50);
	}
	char (*column)[50] = malloc(sizeof(char) * 50 * w_area);

	char (**area)[50]  = malloc(sizeof(column) * l_area);
	 */
	/*for(i=0; i<w_ar<F10>ea; i++) {
		area[i] = malloc(sizeof((char*[50]) * l_area);
	}
	for(i=0; i<w_area; i++) {
		for(j=0; j<l_area; j++) {
			area[i][j] = malloc(50);
			strcpy(area[i][j], "null");
		}
	}*/


	for(i = x_mainb - min_coordinate_x; i < x_mainb - min_coordinate_x  + w_mainb; i++) {
		for(j = y_mainb - min_coordinate_y; j < y_mainb - min_coordinate_y + l_mainb; j++) {
			
			strcpy(area[i][j], B_mainb->B_name);

		}
	}

	for(i = x_e1 - min_coordinate_x; i < x_e1 - min_coordinate_x + w_e1; i++) {
		for(j = y_e1 - min_coordinate_y; j < y_e1 - min_coordinate_y + l_e1; j++) {
			
			strcpy(area[i][j], prp.b_e1->B_name);

		}
	}

	for(i = x_e2 - min_coordinate_x; i < x_e2 - min_coordinate_x + w_e2; i++) {
		for(j = y_e2 - min_coordinate_y; j < y_e2 - min_coordinate_y + l_e2; j++) {
			
			strcpy(area[i][j], prp.b_e2->B_name);

		}
	}


	for(i=0; i < l_area; i++) {
		
		for(j=0; j<w_area; j++) {
			if (j == w_area-1) {
				printf("%s", area[i][j]);
			}
			else {
				printf("%s,", area[i][j]);
			}
		}
		printf("\n");
	}


}

