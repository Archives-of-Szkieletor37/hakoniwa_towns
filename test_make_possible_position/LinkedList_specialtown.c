#include <stdlib.h>
#include <stdio.h>
#include "specialtown.h"
#include "LinkedList_specialtown.h"


extern LinkedList_SpecialTown *make_LinkedList_specialtown(SpecialTown st, LinkedList_SpecialTown *llst) {

	LinkedList_SpecialTown *new_llst = malloc(sizeof(LinkedList_SpecialTown));
	if(new_llst != NULL) {
		new_llst->st = st;
		
		new_llst->next_llst = llst;
	}

	return new_llst;
}


extern LinkedList_SpecialTown *nth_LinkedList_specialtown(LinkedList_SpecialTown *llst, int n) {
	
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

int insert_nth_LinkedList_specialtown(LinkedList_SpecialTown **llst_ptr, SpecialTown st, int n) {

	//int i;
	LinkedList_SpecialTown *llst_temp;

	if (n<0) {
		return 0;
	}
	llst_temp = nth_LinkedList_specialtown(*llst_ptr, n-1);
	llst_ptr = &(llst_temp);	
	(*llst_ptr)->next_llst = make_LinkedList_specialtown(st, llst_temp->next_llst);

	return 1;


	/*int i;
	LinkedList_SpecialTown *st_temp;

	if (n<0) {
		return 0;
	}

	for (i=-1; i<n && *llst_ptr !=NULL; i++) {
		llst_ptr = &((*llst_ptr)->next_llst);
	}

	if(i<n) {
		return 0;
	}
	st_temp = make_LinkedList_specialtown(st, *llst_ptr);
	if(st_temp == NULL) {
		return 0;
		}}
	*llst_ptr = st_temp;*/
	/*LinkedList_SpecialTown *nth_llst = nth_LinkedList_specialtown(*llst_ptr, n);
	 *
	if(nth_llst == NULL) {
		return 0;
	}
	llst_ptr = &(nth_llst);	
	LinkedList_SpecialTown *insert_target_llst = make_LinkedList_specialtown(st, *llst_ptr);
	*llst_ptr = insert_target_llst;
*/	
	return 1;

}

int push_LinkedList_specialtown(LinkedList_SpecialTown **llst_ptr, SpecialTown st) {

	printf("専門街%sがpushされたよ\n", st.ST_name);

	int i;
	i = insert_nth_LinkedList_specialtown(llst_ptr, st, 0);

	printf("確認:%s\n", nth_LinkedList_specialtown(*llst_ptr, 0)->st.ST_name);
	return i;

}

void delete_LinkedList_specialtown(LinkedList_SpecialTown **llst_ptr) {
	LinkedList_SpecialTown **temp;
	while(*llst_ptr != NULL) {
		temp = &((*llst_ptr)->next_llst);
		free(*llst_ptr);
		llst_ptr = temp;
	}
}
		
