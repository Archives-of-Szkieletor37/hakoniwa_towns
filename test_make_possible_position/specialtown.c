#include "specialtown.h"

//SpecialTown empty_st = make_empty_specialtown();
//SpecialTown *p_empty_st = &empty_st;

int cnt_specialtown_regards_mainb = 0;

SpecialTown make_empty_specialtown(void) {

	SpecialTown empty_st;

	strcpy(empty_st.ST_name, "null");
	
	int i = 0;
	
	Building b, *p_b = &b;
	b = building_null();

	for(i=0; i<3; i++) {	

		empty_st.trio_building_compose_specialtown[i] = p_b;
	}

	empty_st.landprice_bonus_rate = -1;

	return empty_st;

}


void free_specialtown(SpecialTown *st) {

	int i;

	for(i=0; i<3; i++) {
		free_building(st->trio_building_compose_specialtown[i]);
	}

	free(st);
}

