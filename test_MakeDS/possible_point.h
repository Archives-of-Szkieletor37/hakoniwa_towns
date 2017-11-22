// possible_point.h
//
#ifndef _POSSIBLE_POINT_H_
#define _POSSIBLE_POINT_H_

#include <stdio.h>
#include "point.h"

typedef struct LLpp{

	Point *p;
	struct LLpp *next_LL_possible_point;
} LinkedList_Possible_Point;


extern LinkedList_Possible_Point *make_LinkedList_possible_point(void);
extern void delete_LinkedList_possible_point(LinkedList_Possible_Point *llpp);
extern LinkedList_Possible_Point *nth_LinkedList_possible_point(LinkedList_Possible_Point *llpp, int n);
extern int insert_nth_LinkedList_possible_point(LinkedList_Possible_Point *llpp, int n, Point *p);
#endif // _POSSIBLE_POINT_H_
