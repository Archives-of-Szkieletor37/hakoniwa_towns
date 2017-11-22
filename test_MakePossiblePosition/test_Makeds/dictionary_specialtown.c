#include "dictionary_specialtown.h"
#include "dictionary_building.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

SpecialTown *dictionary_specialtown[NUMSPECIALTOWN];

void dictionary_specialtown_init(SpecialTown **dictionary_specialtown) {

	int i;

	dictionary_specialtown =  malloc(sizeof(SpecialTown) * NUMSPECIALTOWN);
	
	SpecialTown st = make_empty_specialtown();

	for(i=0; i<NUMSPECIALTOWN; i++) {

		dictionary_specialtown[i] = &st;
		// 配列の各要素のメモリが確保された
			}
}

void delete_dictionary_specialtown(SpecialTown **dictionary_specialtown) {

	int i;

	for(i=0; i<NUMSPECIALTOWN; i++) {
		free_specialtown(dictionary_specialtown[i]);
	}

}

void put_data_of_specialtown_to_dictionary() {
	
	int i,j;
	FILE *fp;

	char *fname = "data_specialtown.csv";
	fp = fopen(fname, "r");
	if (fp == NULL) {
		printf("%sファイルが開けません\n", fname);
		}

	printf("\n");

	char building_name_buffer[3][100] = {"null", "null", "null"};

	dictionary_specialtown_init(dictionary_specialtown);

	for(i=0; i<NUMSPECIALTOWN; i++) {

		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%d\n", dictionary_specialtown[i]->ST_name, building_name_buffer[0], building_name_buffer[1], building_name_buffer[2], &dictionary_specialtown[i]->landprice_bonus_rate);

		for(j=0; j<3; j++) {
			dictionary_specialtown[i]->trio_building_compose_specialtown[j] = search_building_from_dictionary(building_name_buffer[j]);
		}
	}
	printf("dictionary_specialtown[%d] = { \n\n", NUMSPECIALTOWN);

	for(i=0; i<NUMSPECIALTOWN; i++) {

		printf("{%s, \n{", dictionary_specialtown[i]->ST_name);

		for(j=0; j<3; j++) {
			printf(" %s,", dictionary_specialtown[i]->trio_building_compose_specialtown[j]->B_name);
	}

	printf("}, \n%d", dictionary_specialtown[i]->landprice_bonus_rate);

	}
	fclose(fp);
	
}

 
void search_specialtown_from_dictionary(LinkedList_SpecialTown *LinkedList_specialtown_regards_mainb, Building *mainb) {
	int i=0, j=0;

	for(i=0; i<NUMSPECIALTOWN; i++) {

		for(j=0; j<3; j++) {

			if(strcmp((dictionary_specialtown[i]->trio_building_compose_specialtown[j]->B_name), mainb->B_name) == 0) {
			
				push_LinkedList_specialtown(LinkedList_specialtown_regards_mainb, dictionary_specialtown[i]);// 連結リストに追加
				cnt_specialtown_regards_mainb++;
				break;
			}
		}
	}

}



