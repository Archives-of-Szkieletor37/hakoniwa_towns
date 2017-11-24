// possible_point.h
//
#ifndef _LINKEDLIST_POSSIBLE_POINT_H_
#define _LINKEDLIST_POSSIBLE_POINT_H_

#include <stdio.h>
#include "point.h"
#include "building.h"
#include "dictionary_specialtown.h"

typedef struct LLpp{

	Point p;
	struct LLpp *next_llpp;
} LinkedList_Possible_Point;


extern LinkedList_Possible_Point *make_LinkedList_possible_point(Point p, LinkedList_Possible_Point *llpp);

extern void delete_LinkedList_possible_point(LinkedList_Possible_Point **llpp_ptr);

extern LinkedList_Possible_Point *nth_LinkedList_possible_point(LinkedList_Possible_Point *llpp, int n);

extern int insert_nth_LinkedList_possible_point(LinkedList_Possible_Point **llpp_ptr, int n, Point p);

extern int push_LinkedList_possible_point(LinkedList_Possible_Point **llpp_ptr, Point p);

extern int  store_possible_point(Building *B_target, Building *B_object, Building *B_element_2, LinkedList_Possible_Point **llpp_ptr_object); 

#endif // _LINKEDLIST_POSSIBLE_POINT_H_
