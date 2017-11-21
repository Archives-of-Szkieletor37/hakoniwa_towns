#include "dictionary_building.h"
#include "dictionary_specialtown.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dictionary_Building dictionary_building[NUMBUILDING];

Building *dictionary_building[NUMBUILDING];

void put_data_of_building_to_dictionary(void) {
	
	int i;
	FILE *fp;

	//dictionary_building = malloc(sizeof(Building)*NUMBUILDING);
	for(i=0; i<NUMBUILDING; i++) {
		dictionary_building[i] = malloc(sizeof(Building));
		if(dictionary_building[i] == NULL) {
			printf("error_db_%d", i);
		}

		*(dictionary_building[i]) = building_null();
	}

	
	char *fname = "data_building.csv";

	fp = fopen(fname, "r");
	if (fp == NULL) {
		printf("%sファイルが開けません\n", fname);
	}
	
	printf("\n");
	
	int building_length_buffer[2] = {0,0};
	
	for(i=0; i<NUMBUILDING; i++) {

		fscanf(fp, "%[^,],%d,%d\n", dictionary_building[i]->B_name, &building_length_buffer[0], &building_length_buffer[1]);
		
		dictionary_building[i]->B_length = return_pointer_to_length(building_length_buffer[0]);
		dictionary_building[i]->B_width = return_pointer_to_length(building_length_buffer[1]);
	
	}
	/*printf("dictionary_building[%d] = { \n\n", NUMBUILDING);

	for(i=0; i<NUMBUILDING; i++) {

		printf("{%s, %d, %d}\n", dictionary_building[i]->B_name, *(dictionary_building[i]->B_length), *(dictionary_building[i]->B_width));
	}
*/
	printf("\n} \n");

	/*while( (ret=fscanf(fp, "%lf,%lf,%lf", &data[0], &data[1], &data[2])) != EOF) {
		printf("%lf %lf %lf\n", data[0], data[1], data[2]);
	}

	printf("\n");*/
	fclose(fp);

}

Building *search_building_from_dictionary(char B_name[]) {
	
	
	int i=0;	
	while(1) {
		
		if(i == NUMBUILDING) {
			return NULL;
		}

		if(mystrcmp(B_name, dictionary_building[i]->B_name) == 0) {
			break;
		}

		i++;
	}
	
	Building *b = dictionary_building[i];//building_init(B_name, point_init_zero(), dictionary_building[i].DB_length, dictionary_building[i].DB_width);

	return b;
}

