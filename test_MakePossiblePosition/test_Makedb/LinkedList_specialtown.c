#include <stdlib.h>
#include "specialtown.h"
#include "LinkedList_specialtown.h"

// int cnt_specialtown_regards_mainb = 0;

/* 
void search_specialtown_from_dictionary(LinkedList_SpecialTown *LinkedList_specialtown_regards_mainb, Building *mainb) {
	int i=0, j=0;

	for(i=0; i<NUMSPECIALTOWN; i++) {

		for(j=0; j<3; j++) {

			if(strcmp((dictionary_specialtown[i].trio_building_compose_specialtown[j]->B_name), mainb->B_name) == 0) {
			
				push_LinkedList_specialtown(LinkedList_specialtown_regards_mainb, dictionary_specialtown[i];// 連結リストに追加
				cnt_specialtown_regards_mainb++;
				break;
			}
		}
	}

}
*/
extern LinkedList_SpecialTown *make_LinkedList_specialtown(SpecialTown *st) {

	LinkedList_SpecialTown *llst = malloc(sizeof(LinkedList_SpecialTown));
	if(llst != NULL) {
		llst->st = st;
		
		llst->next_llst = NULL;
	}

	return llst;
}


extern LinkedList_SpecialTown *nth_specialtown(LinkedList_SpecialTown *llst, int n) {
	
	int cnt = -1;

	while(cnt < n) {
		if (llst == NULL) {
			return NULL;
		}
		llst = llst->next_llst;
		cnt++;
	}

	return llst;

}

int insert_nth_LinkedList_specialtown(LinkedList_SpecialTown *llst, SpecialTown *st, int n) {

	LinkedList_SpecialTown *front_llst = nth_specialtown(llst, n-1);
	if(front_llst == NULL) {
		return 0;
	}
	
	LinkedList_SpecialTown *insert_target_llst = make_LinkedList_specialtown(st);
	insert_target_llst->next_llst = llst;
	insert_target_llst->st = st;
	front_llst->next_llst = insert_target_llst;
	
	return 1;

}

int push_LinkedList_specialtown(LinkedList_SpecialTown *llst, SpecialTown *st) {

	int i;
	i = insert_nth_LinkedList_specialtown(llst, st, 0);
	return i;

}

void delete_LinkedList_specialtown(LinkedList_SpecialTown *llst) {
	LinkedList_SpecialTown *temp;
	while(llst != NULL) {
		temp = llst->next_llst;
		free_specialtown(llst->st);
		free(llst);
		llst = temp;
	}
}
		
