// specialtown.h
//
#ifndef _LINKEDLIST_SPECIALTOWN_H_
#define _LINKEDLIST_SPECIALTOWN_H_
#include "building.h"
#include "specialtown.h"

typedef struct LL_specialtown {
	SpecialTown *st;
	struct LL_specialtown *next_llst;
}LinkedList_SpecialTown;
/*
extern void search_specialtown_from_dictionary(LinkedList_SpecialTown *LinkedList_specialtown_regards_mainb, Building *mainb);
*/
extern LinkedList_SpecialTown *make_LinkedList_specialtown(SpecialTown *st, LinkedList_SpecialTown *llst);

extern void delete_LinkedList_specialtown(LinkedList_SpecialTown *llst);

extern LinkedList_SpecialTown *nth_specialtown(LinkedList_SpecialTown *llst, int n);

extern int insert_nth_specialtown(LinkedList_SpecialTown *llst, SpecialTown *st, int n);

extern int push_LinkedList_specialtown(LinkedList_SpecialTown *llst, SpecialTown *st);

#endif // _LINKEDLIST_SPECIALTOWN_H_
