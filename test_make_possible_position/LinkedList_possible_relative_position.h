// possible_relative_position.h
//

#ifndef _LINKEDLIST_POSSIBLE_RELATIVE_POSITION_H_
#define _LINKEDLIST_POSSIBLE_RELATIVE_POSITION_H_

#include <stdio.h>
#include "possible_relative_position.h"
#include "LinkedList_possible_point.h"
#include "LinkedList_specialtown.h"

typedef struct LLver_prp{
	
	Possible_Relative_Position prp;
	struct LLver_prp *next_llprp;

} LinkedList_Possible_Relative_Position;

extern int cnt_llprp_element;
/*
extern Possible_Relative_Position possible_relative_position_null(void);
*/
extern LinkedList_Possible_Relative_Position *make_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp, Possible_Relative_Position prp);

extern void delete_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position **llprp_ptr); 

extern LinkedList_Possible_Relative_Position *nth_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp, int n); 

extern int insert_nth_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position **llprp_ptr, Possible_Relative_Position prp, int n); 

extern int push_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position **llprp_ptr, Possible_Relative_Position prp);


// ここまで連接リストの操作

extern void store_prp_to_LinkedList(SpecialTown *specialtown, Building *B_mainb, Building *B_element_1, Building *B_element_2, int flag, LinkedList_Possible_Relative_Position **llprp_ptr);

extern int generate_LinkedList_of_prp(Building *B_mainb, SpecialTown *specialtown_regards_mainb, LinkedList_Possible_Relative_Position **llprp_ptr);

#endif // _LINKEDLIST_POSSIBLE_RELATIVE_POSITION_H_

