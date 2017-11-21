#include "possible_point.h"
#include <stdio.h>


/* Point *make_point(int *x, int *y, int *flag) {

	Point *newpoint = malloc(sizeof(Point));

	if (newpoint != NULL) {
		newpoint->x = x;
		newpoint->y = y;
		newpoint->flag = flag;
	}
	return newpoint;
}

*/


LinkedList_Possible_Point *make_LinkedList_possible_point(void) {

	LinkedList_Possible_Point *llpp = malloc(sizeof(LinkedList_Possible_Point));
	if (llpp != NULL) {
		llpp->p = point_init(NULL,NULL,&flag_f); //false だけ格納
		llpp->next_LL_possible_point = NULL;
	} // ヘッダポイントをセット

	if (llpp->p == NULL) {
		free(llpp);
		return NULL;
	}
	
	return llpp;

}

void delete_LinkedList_possible_point(LinkedList_Possible_Point *llpp){
	LinkedList_Possible_Point *temp = NULL;

	while(llpp != NULL) {
		temp = llpp->next_LL_possible_point;	
		free(llpp->p);
		free(llpp);
		llpp = temp;
	}

} // 先頭から順番に削除してる

LinkedList_Possible_Point *nth_LinkedList_possible_point(LinkedList_Possible_Point *llpp, int n) {

	int cnt = -1;
	
	while (cnt < n) {
		
		if (llpp->next_LL_possible_point == NULL) {
			return NULL;
		}
		else {
			llpp = llpp->next_LL_possible_point; 
			cnt++;
		}
	}

	return llpp;

} // ヘッダポイントは-1番目、先頭は0番目

int insert_nth_LinkedList_possible_point(LinkedList_Possible_Point *llpp, int n, Point *p) {

	LinkedList_Possible_Point *front_llpp = nth_LinkedList_possible_point(llpp, n-1); // n = 0 ならヘッダポイントが入る

	if (front_llpp == NULL) { // nが要素数を超えていた場合
		return 0; // false
	}

	LinkedList_Possible_Point *insert_target_llpp = make_LinkedList_possible_point();
	
	if (insert_target_llpp == NULL) { // 確保できなかった場合
		return 0; //false
	}
	else {
		insert_target_llpp->p = p;
		insert_target_llpp->next_LL_possible_point = front_llpp->next_LL_possible_point;
		front_llpp->next_LL_possible_point = insert_target_llpp;

		return 1; // true
	}
}


