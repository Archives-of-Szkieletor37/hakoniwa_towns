#include <stdio.h>
#include <stdlib.h>
#define MAXSPECIALTOWN 187 



typedef struct {
		
		char DS_name[100];
		char trio_building_compose_specialtown[3][100]; // {index, 要素A,要素B}
		double landprice_bonus_rate;

} Dictionary_SpecialTown;


int main(int argc, char *argv[]) {
	
	int i;
	FILE *fp;

	Dictionary_SpecialTown DS_buffer[MAXSPECIALTOWN];
	char *fname = "dictionary_specialtown.csv";
	//int ret;
	//char buf_string[200][20];
	//double buf_double [200];
	//double data[3];

	fp = fopen(fname, "r");
	if (fp == NULL) {
		printf("%sファイルが開けません\n", fname);
		return -1;
	}

	printf("\n");

	for(i=0; i<MAXSPECIALTOWN; i++) {

		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%lf\n", DS_buffer[i].DS_name, DS_buffer[i].trio_building_compose_specialtown[0], DS_buffer[i].trio_building_compose_specialtown[1], DS_buffer[i].trio_building_compose_specialtown[2], &DS_buffer[i].landprice_bonus_rate);
		//fgetc(fp);
	}
	printf("dictionary_specialtown[187] = { \n\n");

	for(i=0; i<MAXSPECIALTOWN; i++) {

		printf("{%s, {%s, %s, %s}, %lf}\n", DS_buffer[i].DS_name, DS_buffer[i].trio_building_compose_specialtown[0], DS_buffer[i].trio_building_compose_specialtown[1], DS_buffer[i].trio_building_compose_specialtown[2], DS_buffer[i].landprice_bonus_rate);

	}

	printf("\n} \n");

	/*while( (ret=fscanf(fp, "%lf,%lf,%lf", &data[0], &data[1], &data[2])) != EOF) {
		printf("%lf %lf %lf\n", data[0], data[1], data[2]);
	}

	printf("\n");*/
	fclose(fp);

	return 0;
}
