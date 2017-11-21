// dictionary_building.h
#ifndef _DICTIONARY_BUILDING_H_
#define _DICTIONARY_BUILDING_H_

#define NUMBUILDING 167

#include "building.h"

extern Building *dictionary_building[NUMBUILDING];

extern void put_data_of_building_to_dictionary(void);

extern Building *search_building_from_dictionary(char B_name[]);

#endif // _DICTIONARY_BUILDING_H_
