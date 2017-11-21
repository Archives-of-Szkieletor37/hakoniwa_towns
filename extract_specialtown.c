//extract_specialtown.c

#include <stdio.h>
#include "extract_specialtown.h"

int cnt_specialtown_regards_mainb = 0;

int extract_specialtown(Dictionary_SpecialTown DS_list_dictionary_specialtown[], Building *B_mainb, Dictionary_SpecialTown *p_DS_list_specialtown_regards_mainb) {

//	int cnt_specialtown_regards_mainb = 0;

	int i,j;

	for(i=0; i<3; i++) {
		for(j=0; j<SPECIALTOWN_COUNT; j++) {
			if (strcmp(DS_list_dictionary_specialtown[j].trio_building_compose_specialtown[i], B_mainb->B_name) == 0) {
				*(p_DS_list_specialtown_regards_mainb + cnt_specialtown_regards_mainb) = DS_list_dictionary_specialtown[i];
				cnt_DS_list_specialtown_regards_mainb++;
			}
		}
	}
	// return cnt_specialtown_regards_mainb;
}



