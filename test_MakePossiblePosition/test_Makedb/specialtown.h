// specialtown.h
//
#ifndef _SPECIALTOWN_H_
#define _SPECIALTOWN_H_
#include "building.h"
#include <stdlib.h>
#include <string.h>



typedef struct { 
		char ST_name[100];
		Building* trio_building_compose_specialtown[3];
		int landprice_bonus_rate;

} SpecialTown;

extern int cnt_specialtown_regards_mainb;

extern SpecialTown *make_empty_specialtown(void);

extern void free_specialtown(SpecialTown *st);

#endif // _SPECIALTOWN_H_
