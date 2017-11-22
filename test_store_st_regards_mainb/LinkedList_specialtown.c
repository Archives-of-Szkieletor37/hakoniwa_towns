#include <stdlib.h>
#include "specialtown.h"
#include "LinkedList_specialtown.h"


extern LinkedList_SpecialTown *make_LinkedList_specialtown(SpecialTown *st, LinkedList_SpecialTown *llst) {

	LinkedList_SpecialTown *new_llst = malloc(sizeof(LinkedList_SpecialTown));
	if(new_llst != NULL) {
		new_llst->st = st;
		
		new_llst->next_llst = llst;
	}

	return new_llst;
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
	
	LinkedList_SpecialTown *insert_target_llst = make_LinkedList_specialtown(st, front_llst->next_llst);
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
		
