#include <stdio.h>
#include <stdlib.h>
#include "dictionary_specialtown.h"
#include "dictionary_building.h"

int main(int argc, char *argv[]) {

	put_data_of_building_to_dictionary();
	
	put_data_of_specialtown_to_dictionary();

	// まず、第一引数の名前でDBを検索する。	 
	
	Building *mainb = search_building_from_dictionary(argv[1]);
	
	if (mainb == NULL) {
		printf("中心にする建物を読み込めませんでした。\n");
		exit(1);// エラー
	}

	SpecialTown empty_st, *p_empty_st;
	p_empty_st = &empty_st;
	*p_empty_st = make_empty_specialtown();

	LinkedList_SpecialTown *LinkedList_specialtown_regards_mainb = make_LinkedList_specialtown(p_empty_st, NULL); // 中心になる建物に関わる専門街を連結リストに格納, 連結リストは空ヘッダをいれておく
	
	search_specialtown_from_dictionary(LinkedList_specialtown_regards_mainb, mainb);

	if (LinkedList_specialtown_regards_mainb == NULL) {
		// エラー
	}

	
	printf("%d\n", cnt_specialtown_regards_mainb);

	while(LinkedList_specialtown_regards_mainb != NULL) {
		if(LinkedList_specialtown_regards_mainb->st == p_empty_st) {
			LinkedList_specialtown_regards_mainb = LinkedList_specialtown_regards_mainb->next_llst;
		}
		printf("%s\n", LinkedList_specialtown_regards_mainb->st->ST_name);
		LinkedList_specialtown_regards_mainb = LinkedList_specialtown_regards_mainb->next_llst;
	}

	LinkedList_Possible_Relative_Position *LinkedList_possible_relative_position[cnt_specialtown_regards_mainb]; //専門街ごとに可能な配置を格納する連結リストを用意する。
	
	// mainbが関係するすべての専門街について、可能な置き方の格納を行う
	for(i=0; i<cnt_specialtown_regards_mainb; i++) {

		*LinkedList_possible_relative_position[i] = make_LinkedList_possible_relative_position();

		generate_list_possible_relative_position(mainb, LinkedList_specialtown, LinkedList_possible_relative_position[i]);

	}



	return 0;

}


