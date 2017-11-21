// possible_relative_position.h
//

#ifndef _POSSIBLE_RELATIVE_POSITION_H_
#define _POSSIBLE_RELATIVE_POSITION_H_

#include <stdio.h>
#include "possible_relative_position.h"

typedef struct LLver_prp{
	
	Possible_Relative_Position *prp;
	struct LLver_prp *next_llprp;

} LinkedList_Possible_Relative_Position;
/*
extern Possible_Relative_Position possible_relative_position_null(void);
*/
extern LinkedList_Possible_Relative_Position *make_LinkedList_possible_relative_position(void);

extern void delete_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp); 

extern LinkedList_Possible_Relative_Position *nth_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp, int n); 

extern int insert_nth_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp, Possible_Relative_Position *prp, int n); 
	
// ここまで連接リストの操作


extern LinkedList_Possible_Relative_Position possible_relative_position_init(SpecialTown *specialtown, Point *possible_point_x1, Point *possible_point_x2, int cnt_dominated_mainbs_adjacent_square);

extern int generate_list_possible_relative_position(Building *B_mainb, Dictionary_Specialtown *DS_specialtown, LinkedList_Possible_Relative_Position *list_possible_relative_position);

#endif // _POSSIBLE_RELATIVE_POSITION_H_

