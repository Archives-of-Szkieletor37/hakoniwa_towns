#include <stdio.h>
#include <stdlib.h>
#include "dictionary_specialtown.h"
#include "dictionary_building.h"
#include "LinkedList_possible_relative_position.h"
#include "LinkedList_specialtown.h"
#include "print_prp.h"

int main(int argc, char *argv[]) {

	put_data_of_building_to_dictionary();
	
	put_data_of_specialtown_to_dictionary();
	
	int i;
	// まず、第一引数の名前でDBを検索する。	 
	
	Building *mainb = search_building_from_dictionary(argv[1]);
	
	mainb->B_left_bottom_point = point_init(0,0,1); 

	if (mainb == NULL) {
		printf("中心にする建物を読み込めませんでした。\n");
		exit(1);// エラー
	}

	SpecialTown empty_st = make_empty_specialtown();

	LinkedList_SpecialTown *LinkedList_specialtown_regards_mainb = make_LinkedList_specialtown(empty_st, NULL); // 中心になる建物に関わる専門街を連結リストに格納, 連結リストは空ヘッダをいれておく

	LinkedList_SpecialTown **llst_ptr = &LinkedList_specialtown_regards_mainb;
	search_specialtown_from_dictionary(llst_ptr, mainb);

	if (LinkedList_specialtown_regards_mainb == NULL) {
		// エラー
	}

	
	printf("%d\n", cnt_specialtown_regards_mainb);

	/*while(LinkedList_specialtown_regards_mainb != NULL) {
		if(LinkedList_specialtown_regards_mainb->st == p_empty_st) {
			LinkedList_specialtown_regards_mainb = LinkedList_specialtown_regards_mainb->next_llst;
		}
		printf("%s\n", LinkedList_specialtown_regards_mainb->st->ST_name);
		LinkedList_specialtown_regards_mainb = LinkedList_specialtown_regards_mainb->next_llst;
	}*/

	LinkedList_Possible_Relative_Position *LinkedList_possible_relative_position[cnt_specialtown_regards_mainb]; //専門街ごとに可能な配置を格納する連結リストを用意する。
	SpecialTown *st_temp = NULL;	

	Possible_Relative_Position prp_null = make_possible_relative_position(NULL, NULL, NULL, -1);
	// mainbが関係するすべての専門街について、可能な置き方の格納を行う
	
	LinkedList_Possible_Relative_Position **llprp_ptr;	

	for(i=0; i<cnt_specialtown_regards_mainb; i++) {

		LinkedList_possible_relative_position[i] = make_LinkedList_possible_relative_position(NULL,prp_null);
		llprp_ptr = &LinkedList_possible_relative_position[i];
		
		st_temp = &(nth_LinkedList_specialtown(LinkedList_specialtown_regards_mainb, i))->st;

		generate_LinkedList_of_prp(mainb, st_temp, llprp_ptr);

	}

/*	for(i=0; i<cnt_specialtown_regards_mainb; i++) {
		int j = 0;
		while(nth_LinkedList_possible_relative_position(LinkedList_possible_relative_position[i],j) == NULL) {
			printf("%d %d\n", LinkedList_possible_relative_position[i]->prp.b_e1->B_left_bottom_point.x, LinkedList_possible_relative_position[i]->prp.b_e1->B_left_bottom_point.y);
			LinkedList_possible_relative_position[i] = LinkedList_possible_relative_position[i]->next_llprp;
			j++;
		}
	}
*/
	printf("%d個の長さ\n", cnt_llprp_element);
	//LinkedList_Possible_Relative_Position *temp = LinkedList_possible_relative_position[0];
	
	Possible_Relative_Position prp_temp;
	for(i=0; i<cnt_llprp_element; i++) {
		
		printf("%s, %d, %d\n", nth_LinkedList_possible_relative_position(LinkedList_possible_relative_position[0], i)->prp.b_e1->B_name,nth_LinkedList_possible_relative_position(LinkedList_possible_relative_position[0], i)->prp.b_e1->B_left_bottom_point.x, nth_LinkedList_possible_relative_position(LinkedList_possible_relative_position[0], i)->prp.b_e1->B_left_bottom_point.y);
		print_prp(mainb, nth_LinkedList_possible_relative_position(LinkedList_possible_relative_position[0], i)->prp);
	}

	return 0;

}


