#include "LinkedList_possible_point.h"
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


LinkedList_Possible_Point *make_LinkedList_possible_point(Point *p, LinkedList_Possible_Point *llpp) {

	LinkedList_Possible_Point *new_llpp = malloc(sizeof(LinkedList_Possible_Point));
	if (new_llpp == NULL) {
		free(new_llpp);
		return NULL;
	}
	new_llpp->p = p; //false だけ格納
	new_llpp->next_llpp = llpp;
	// ヘッダポイントをセット

	return new_llpp;

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

	LinkedList_Possible_Point *insert_target_llpp = make_LinkedList_possible_point(p, front_llpp->next_llpp);
	
	if (insert_target_llpp == NULL) { // 確保できなかった場合
		return 0; //false
	}
	else {
		front_llpp->next_llpp = insert_target_llpp;

		return 1; // true
	}
}

int push_LinkedList_possible_point(LinkedList_Possible_Point *llpp, Point *p) {
	
	int i = insert_nth_LinkedList_possible_point(llpp, 0, p);
	if(i) {
		return 1;
	}
	else {
		return 0;
	}
}

int help_store_possible_point(int min_coordinate, int max_coordinate, int flag, int z, Building *B_object, Building *B_e2, LinkedList_Possible_Point *llpp_object) {

	int cnt_object_possible_point = 0;

	for(i=min_coordinate; i<max_coordinate; i++) {

		if(flag == 0) {
			Point *p = point_init(i, z);
		}
		else {
			Point *p = point_init(z, i);
		}

		if(check_unoverlap(p, *(B_object->B_length), *(B_object->B_width), B_e2) == 1 && is_adjacent(B_object, B_e2) == 0) {

			push_LinkedList_possible_point(llpp_object, p);
			cnt_object_possible_point++;
		}
	}

	return cnt_object_possible_point;
}


// map上に存在するtargetとobjectを隣接させたい時、objectの可能な座標を教えてくれる関数。
int store_possible_point(Building *B_target, Building *B_object, Building *B_element_2, LinkedList_Possible_Point *llpp_object) {
	
	int sum_cnt_object_possible_point = 0;

	int min_coordinate, max_coordinate, z;


	// 上隣接
	min_coordinate = (B_target->left_bottom_point.x + 1 - B_object->B_width);
	max_coordinate = (B_target->left_bottom_point.x + B_target->B_width);
	z =B_target->left_bottom_point.y + B_target->B_length;

	help_store_possible_point(min_coordinate, max_coordinate, 0,z); 



		Point *p = point_init(i, B_target->left_bottom_point.y + B_target->B_length);

		if (check_unoverlap(p, *(B_object->B_length), *(B_object->B_width), B_element_2) == 1 && is_adjacent(B_object, B_element_2) == 0) {

			push_LinkedList_possible_point(LinkedList_object_possible_point, p);
	
			cnt_object_possible_point++;
		}

	}

	//　下隣接
	
	help_store_possible_point((B_target->left_bottom_point.y + 1 - B_object->B_width), (B_target->left_bottom_point.x + B_target->B_width), 0, B_target->left_bottom_point.y + B_target->B_length) {for(i=(B_target->left_bottom_point.x + 1 - B_object->B_width); i < (B_target->left_bottom_point.x + B_target->B_width); i++) {

		Point *p = point_init(i, B_target->left_bottom_point.y - B_object->B_length);

		if (check_unoverlap(p, B_object->B_length, B_object->B_width, B_element_2) == 1 && is_adjacent(B_object, B_element_2) == 0) {

			push_LinkedList_possible_point(LinkedList_object_possible_point, p);
			cnt_object_possible_point++;

		}
	}
	
	// 左隣接
	for(i=(B_target->left_bottom_point.y + 1 - B_object->B_length); i < (B_target->left_bottom_point.y + B_target->B_width); i++) {

		Point *p = point_init(B_target->left_bottom_point.x - B_object->B_width, i);

		if (check_unoverlap(p, B_object->B_length, B_object->B_width, B_element_2) == 1 && is_adjacent(B_object, B_element_2) == 0) {
			push_LinkedList_possible_point(LinkedList_object_possible_point, p);
			cnt_object_possible_point++;
		}
	}

	// 右隣接
	for(i=(B_target->left_bottom_point.y + 1 - B_object->B_length); i < (B_target->left_bottom_point.x + B_target->B_width); i++) {
		Point *p = point_init(B_target->left_bottom_point.x + B_target->B_width, i);

		if (check_unoverlap(p, B_object->B_length, B_object->B_width, B_element_2) == 1 && is_adjacent(B_object, B_element_2) == 0) {
			push_LinkedList_possible_point(LinkedList_object_possible_point, p);
			cnt_object_possible_point++;
		}
	}

	// LinkedList_e1_possible_point に全パターンが入った。

	return cnt_object_possible_point;

}


	
