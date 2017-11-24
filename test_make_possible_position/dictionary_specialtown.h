// dictionary_specialtown.h
#ifndef _DICTIONARY_SPECIALTOWN_H_
#define _DICTIONARY_SPECIALTOWN_H_
#include "specialtown.h"
#include "LinkedList_specialtown.h"
#define NUMSPECIALTOWN 187 

extern SpecialTown *dictionary_specialtown[NUMSPECIALTOWN];

extern int mystrcmp(char *s1, char *s2);
//extern void dictionary_specialtown_init(SpecialTown **dictionary_specialtown);

//extern void delete_dictionary_specialtown(SpecialTown **dictionary_specialtown);

extern void put_data_of_specialtown_to_dictionary(void);


extern void search_specialtown_from_dictionary(LinkedList_SpecialTown **LinkedList_specialtown_regards_mainb_ptr, Building *mainb);

#endif // _DICTIONARY_SPECIALTOWN_H_
