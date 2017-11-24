#include "dictionary_specialtown.h"
#include "dictionary_building.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
SpecialTown *dictionary_specialtown[NUMSPECIALTOWN];
/*
void dictionary_specialtown_init(SpecialTown **dictionary_specialtown) {

	int i;

	dictionary_specialtown =  malloc(sizeof(SpecialTown) * NUMSPECIALTOWN);

	for(i=0; i<NUMSPECIALTOWN; i++) {

		dictionary_specialtown[i] = make_empty_specialtown();
		// 配列の各要素のメモリが確保された
			}
}
*/

int mystrcmp(char* s1, char* s2) {

	int i = 0;

	while(((s1[i]=='\0') && (s2[i]=='\0')) || ((s1[i] != '\0') && (s2[i] != '\0'))) {
		if (s1[i] != s2[i]) {
			break;
		}
		else {
			if (s1[i] == '\0' && s2[i] == '\0') {
				return 0;
			}
			i++;
		}

	}
		return -1;
}


void delete_dictionary_specialtown(SpecialTown **dictionary_specialtown) {

	int i;

	for(i=0; i<NUMSPECIALTOWN; i++) {
		free_specialtown(dictionary_specialtown[i]);
	}

}

void put_data_of_specialtown_to_dictionary(void) {
	
	int i,j;
	FILE *fp;

	for(i=0; i<NUMSPECIALTOWN; i++) {

		dictionary_specialtown[i] = malloc(sizeof(SpecialTown));
		if(dictionary_specialtown[i] == NULL) {
			printf("error, malloc, ds");
		}
		*(dictionary_specialtown[i]) = make_empty_specialtown();
	}


	char *fname = "data_specialtown.csv";
	fp = fopen(fname, "r");
	if (fp == NULL) {
		printf("%sファイルが開けません\n", fname);
		}

	printf("\n");

	char building_name_buffer[3][100] = {"null", "null", "null"};
	
	for(i=0; i<NUMSPECIALTOWN; i++) {

		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%d\n", dictionary_specialtown[i]->ST_name, building_name_buffer[0], building_name_buffer[1], building_name_buffer[2], &dictionary_specialtown[i]->landprice_bonus_rate);
	

		for(j=0; j<3; j++) {
			dictionary_specialtown[i]->trio_building_compose_specialtown[j] = search_building_from_dictionary(building_name_buffer[j]);
		}
	}
	printf("dictionary_specialtown[%d] = { \n\n", NUMSPECIALTOWN);

	for(i=0; i<NUMSPECIALTOWN; i++) {

		printf("{%s, {", dictionary_specialtown[i]->ST_name);

		for(j=0; j<3; j++) {
			printf("%s,", dictionary_specialtown[i]->trio_building_compose_specialtown[j]->B_name);
	}

	printf("}, %d}\n", dictionary_specialtown[i]->landprice_bonus_rate);

	}
	
	printf("\n終わり\n");

	fclose(fp);
	
}

 
void search_specialtown_from_dictionary(LinkedList_SpecialTown **LinkedList_specialtown_regards_mainb_ptr, Building *mainb) {

	//printf("debug:: searchは呼び出されている\n");
	int i=0, j=0;

	for(i=0; i<NUMSPECIALTOWN; i++) {

		for(j=0; j<3; j++) {

			if(mystrcmp((dictionary_specialtown[i]->trio_building_compose_specialtown[j]->B_name), mainb->B_name) == 0) {
			
				push_LinkedList_specialtown(LinkedList_specialtown_regards_mainb_ptr, *(dictionary_specialtown[i]));// 連結リストに追加
				cnt_specialtown_regards_mainb++;
				break;
			}
		}
	}

}



