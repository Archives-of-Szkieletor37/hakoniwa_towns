#include <stdio.h>
#include "possible_relative_position.h"
#include "LinkedList_possible_point.h"

/*extern LinkedList_Possible_Relative_Position possible_relative_position_null(void) {

	LinkedList_Possible_Relative_Position prp;
	prp.specialtown = dictionary_specialtown_null();
	prp.possible_point = point_null();
	prp.cnt_dominated_mainbs_adjscent_square = -1;
	prp->next_prp =NULL;

	return prp;
}
*/
Possible_Relative_Position make_possible_relative_position(SpecialTown *specialtown, Building *b_e1, Building *b_e2, int cnt_dominated_mainbs_adjacent_square) {

	Possible_Relative_Position prp;
	
	prp.specialtown = specialtown;
	prp.b_e1 = b_e1;
	prp.b_e2 = b_e2;
	prp.cnt_dominated_mainbs_adjacent_square = cnt_dominated_mainbs_adjacent_square;

	return prp;
}

extern void free_possible_relative_position(Possible_Relative_Position *prp) {

	free_specialtown(prp->specialtown);
	free(prp->b_e1);
	free(prp->b_e2);

	free(prp);
}

/*

extern LinkedList_Possible_Relative_Position possible_relative_position_init(SpecialTown* LinkedList_specialtown_regards_mainb, Point possible_point) {

	LinkedList_Possible_Relative_Position prp;
	prp->specialtown = *LinkedList_specialtown_regards_mainb;
	prp->possible_point = possible_point;
	prp->cnt_dominated_mainbs_adjacent_square = -1;
	prp->next_prp = NULL;
	return prp;

}
*/

/*adjacent_pattern_a(Building *B_mainb, Building *B_element_1, Building *B_element_2, LinkedList_Possible_Relative_Position *p_possible_relative_position) {

	// mainb | e_a && mainb | e_b 
	


adjacent_pattern_b(Building *B_mainb, Building *B_element_1, Building *B_element_2, LinkedList_Possible_Relative_Position *p_possible_relative_position, start_num_to_store_p_list_prp);

adjacent_pattern_c(Building *B_mainb, Building *B_element_1, Building *B_element_2, LinkedList_Possible_Relative_Position *p_possible_relative_position, start_num_to_store_p_list_prp);

*/

// int cnt_LinkedList_possible_relative_position = 0;

/*
 * int put_2nd_building_adjacently_on_top(Building *B_object, Building *B_target, SpecialTown *LinkedList_specialtown_regards_mainb, LinkedList_Possible_Relative_Position *LinkedList_possible_relative_position) {

	// objectが置くもの、targetが隣接させたい目標
	LinkedList_Possible_Relative_Position prp_x1;
	//prp_x1.specialtown = *LinkedList_specialtown_regards_mainb;
	
	int i;

	for(i=(B_target->B_left_bottom_point->x + 1 - B_object->B_width); i < (B_target->B_left_bottom_point->x + B_target->B_width); i++) {
		B_object.B_left_bottom_point->x = i;
		B_object.B_left_bottom_point->y = B_target->B_left_bottom_point->y + B_target->B_length;
	}


}

*/


/*
bool is_adjacent(Building *B_target, Building *B_object) {

	if (*B_object == building_null()) {
		return 0; //存在しなければそもそも隣接してない
	}
	else {
		int x_target = B_target->B_left_bottom_point->x, y_target = B_target->B_left_bottom_point->y;
		int l_target = B_target->B_length, w_target = B_target->B_width;
		int x_object = B_object->B_left_bottom_point->x, y_object = B_object->B_left_bottom_point->y;
		int l_object = B_object->B_length, w_object = B_object->B_width;

		if (x_target - w_object == x_object || y_target - l_object == y_object || x_target + w_target == x_object || y_target + l_target == y_object) {
			return 1;
		}
		else {
			return 0;
		}
	l
}

int check_unoverlap(Point* possible_point, int length_object, int width_object, Building *B_element_2) {

	int x_o = possible_point->x, y_o = possible_point->y;
	int l_o = length_object, w_o = width_object;
	int x_e2 = B_element_2->B_left_bottom_point->x;
	int y_e2 = B_element_2->B_left_bottom_point->y;
	int l_e2 = B_element_2->B_length;
	int w_e2 = B_element_2->B_width;

	if (B_element_2 == building_null()) {
		return 1; //存在していなければoverlapしない
	}

	else if(x_o + w_o > x_e2 || y_o + l_o > y_e2 || x_o - w_e2 < x_e2 || y_o - l_e2 < y_e2) {
		return 0;
	}
	else {
		return 1;
	}
}
*/
// 辺のうち何マスが埋まっているか計算する関数 
int cnt_shared_part_of_side (Building *B_mainb, Building *B_element_1) {

	// int id = -1; // -1 -> none 0->top or bottom 1->left or right
	
	int coordinate = 0, cnt_share = 0;

	int mainb_x = B_mainb->B_left_bottom_point.x, mainb_y = B_mainb->B_left_bottom_point.y;
	int e1_x = B_element_1->B_left_bottom_point.x, e1_y = B_element_1->B_left_bottom_point.y;
	int mainb_length = (B_mainb->B_length), mainb_width = (B_mainb->B_width);
	int e1_length = (B_element_1->B_length), e1_width = (B_element_1->B_width);

	if((mainb_y + mainb_length == e1_y || mainb_y - e1_length == e1_y) && (mainb_x > e1_x + e1_width || mainb_x < e1_x - mainb_width)) { 
	

		coordinate = (mainb_x < e1_x) ? mainb_x : e1_x;
		
		
		while(coordinate <= mainb_x+mainb_width && coordinate <=e1_x+e1_length) {
			if (coordinate < mainb_x || coordinate < e1_x) {
				coordinate++;
			}

			if (mainb_x <= coordinate && coordinate <= mainb_x + mainb_width && e1_x <= coordinate && coordinate <= e1_x + e1_width) {
				cnt_share++;
				coordinate++;
			}
/*
			if (coordinate > mainb_x + mainb_width || coordinate > e1_x + e1_length) {
				break;
			}
*/		}
				

		return cnt_share;
	}
		
	else if((mainb_x - e1_width == e1_x || mainb_x + mainb_length == e1_x) && (mainb_y > e1_y + e1_length || mainb_y < e1_y - mainb_length)) {
		
		coordinate = (mainb_y < e1_y) ? mainb_y : e1_y;

		while(coordinate <= mainb_y + mainb_length && coordinate <= e1_y + e1_length) {
			if (coordinate < mainb_y || coordinate < e1_y) {
				coordinate++;
			}

			if (mainb_y <= coordinate && coordinate <= mainb_y + mainb_length && e1_y <= coordinate && coordinate <= e1_y + e1_length) {
				cnt_share++;
				coordinate++;
			}
/*
			if (coordinate > mainb_y + mainb_length || coordinate > e1_y + e1_length) {
				break;
			}
*/		}
		
		return cnt_share;
	}

}

/*int main_cnt_shared_part_of_side (Building *B_mainb, Building *B_element_1, Building *B_element_2) {

	int cnt_e1 = 0, cnt_e2 = 0;
	int cnt = 0;

	cnt_e1 = cnt_shared_part_of_side(B_mainb, B_element_1);
	cnt_e2 = cnt_shared_part_of_side(B_mainb, B_element_2);

	cnt = cnt_e1 + cnt_e2;

	return cnt;
}
*/

/*
// map上に存在するtargetとobjectを隣接させたい時、objectの可能な座標を教えてくれる関数。
void store_possible_point(Building *B_target, Building *B_object, Building *B_element_2, LinkedList_Possible_Point *LinkedList_object_possible_point) {
	
	int cnt_object_possible_point = 0;

	// 上隣接
	for(i=(B_target->B_left_bottom_point->x + 1 - B_object->B_width); i < (B_target->B_left_bottom_point->x + B_target->B_width); i++) {
		Point *p = point_init(i, B_target->B_left_bottom_point->y + B_target->B_length);

		if (check_unoverlap(p, *(B_object->B_length), *(B_object->B_width), B_element_2) == 1 && is_adjacent(B_object, B_element_2) == 0) {

			push_LinkedList_possible_point(LinkedList_object_possible_point, p);
	
			cnt_object_possible_point++;
		}

	}

	//　下隣接
	for(i=(B_target->B_left_bottom_point->x + 1 - B_object->B_width); i < (B_target->B_left_bottom_point->x + B_target->B_width); i++) {

		Point *p = point_init(i, B_target->B_left_bottom_point->y - B_object->B_length);

		if (check_unoverlap(p, B_object->B_length, B_object->B_width, B_element_2) == 1 && is_adjacent(B_object, B_element_2) == 0) {

			push_LinkedList_possible_point(LinkedList_object_possible_point, p);
			cnt_object_possible_point++;

		}
	}
	
	// 左隣接
	for(i=(B_target->B_left_bottom_point->y + 1 - B_object->B_length); i < (B_target->B_left_bottom_point->y + B_target->B_width); i++) {

		Point *p = point_init(B_target->B_left_bottom_point->x - B_object->B_width, i);

		if (check_unoverlap(p, B_object->B_length, B_object->B_width, B_element_2) == 1 && is_adjacent(B_object, B_element_2) == 0) {
			push_LinkedList_possible_point(LinkedList_object_possible_point, p);
			cnt_object_possible_point++;
		}
	}

	// 右隣接
	for(i=(B_target->B_left_bottom_point->y + 1 - B_object->B_length); i < (B_target->B_left_bottom_point->x + B_target->B_width); i++) {
		Point *p = point_init(B_target->B_left_bottom_point->x + B_target->B_width, i);

		if (check_unoverlap(p, B_object->B_length, B_object->B_width, B_element_2) == 1 && is_adjacent(B_object, B_element_2) == 0) {
			push_LinkedList_possible_point(LinkedList_object_possible_point, p);
			cnt_object_possible_point++;
		}
	}

	// LinkedList_e1_possible_point に全パターンが入った。

	return cnt_object_possible_point;

}
*/
// 物件mainbと専門街Sを受け取り、可能な配置をLinkedList_possible_relative_position配列に入れて、要素数を返す関数

/*	for(i=(B_mainb->B_left_bottom_point->x + 1 - B_element_1->B_width); i < (B_mainb->B_left_bottom_point->x + B_mainb->B_width); i++) {
		B_element_1.B_left_bottom_point->x = i;
		B_element_1.B_left_bottom_point->y = B_mainb->B_left_bottom_point->y + B_mainb->B_length;

		
	}


	// ここから隣接のしかたによって3つのパターンに分岐したい
*	
	cnt_LinkedList_possible_relative_position[0] = adjacent_pattern_a(B_mainb, B_element_1, B_element_2, p_possible_relative_position);

	cnt_LinkedList_possible_relative_position[1] = adjacent_pattern_b(B_mainb, B_element_1, B_element_2, p_possible_relative_position, cnt_LinkedList_possible_relative_position[0]);

	cnt_LinkedList_possible_relative_position[2] = adjacent_pattern_c(B_mainb, B_element_1, B_element_2, p_possible_relative_position, cnt_LinkedList_possible_relative_position[1]);
	// pattern A が終わったら、要素への格納を次の位置から始めたい

	//可能なxs1,xs2の相対座標はリストに入り、かつその個数はcnt_LinkedList_possible_relative_position[2]に入っている。
	
*/
