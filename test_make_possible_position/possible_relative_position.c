#include <stdio.h>
#include "possible_relative_position.h"
#include "possible_point.h"

/*extern LinkedList_Possible_Relative_Position possible_relative_position_null(void) {

	LinkedList_Possible_Relative_Position prp;
	prp.specialtown = dictionary_specialtown_null();
	prp.possible_point = point_null();
	prp.cnt_dominated_mainbs_adjscent_square = -1;
	prp.next_prp =NULL;

	return prp;
}
*/
Possible_Relative_Position *make_possible_relative_position(SpecialTown *specialtown, Point *point_e1, Point *point_e2, int cnt_dominated_mainbs_adjacent_square) {

	Possible_Relative_Position *prp = malloc(sizeof(Possible_Relative_Position));

	if (prp != NULL) {

		prp->specialtown = make_specialtown;
		prp->point_e1 = make_point(NULL, NULL, &flag_f);
		prp->point_e2 = make_point(NULL, NULL, &flag_f);
		prp->cnt_dominated_mainbs_adjacent_square = cnt_dominated_mainbs_adjacent_square;
		
		if(specialtown == NULL || possible_point_x1 == NULL || possible_point_x2 == NULL) {
			free(prp);	
			return NULL;
		}
	}

	return prp;
}

extern void free_possible_relative_position(Possible_Relative_Position *prp) {

	free_specialtown(prp->specialtown);
	free(prp->point_e1);
	free(prp->point_e2);

	free(prp);
}



extern LinkedList_Possible_Relative_Position possible_relative_position_init(SpecialTown* LinkedList_specialtown_regards_mainb, Point possible_point) {

	LinkedList_Possible_Relative_Position prp;
	prp.specialtown = *LinkedList_specialtown_regards_mainb;
	prp.possible_point = possible_point;
	prp.cnt_dominated_mainbs_adjacent_square = -1;
	prp.next_prp = NULL;
	return prp;

}


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

	for(i=(B_target->left_bottom_point.x + 1 - B_object->B_width); i < (B_target->left_bottom_point.x + B_target->B_width); i++) {
		B_object.left_bottom_point.x = i;
		B_object.left_bottom_point.y = B_target->left_bottom_point.y + B_target->B_length;
	}


}

*/



bool is_adjacent(Building *B_target, Building *B_object) {

	if (*B_object == building_null()) {
		return 0; //存在しなければそもそも隣接してない
	}
	else {
		int x_target = B_target->left_bottom_point.x, y_target = B_target->left_bottom_point.y;
		int l_target = B_target->B_length, w_target = B_target->B_width;
		int x_object = B_object->left_bottom_point.x, y_object = B_object->left_bottom_point.y;
		int l_object = B_object->B_length, w_object = B_object->B_width;

		if (x_target - w_object == x_object || y_target - l_object == y_object || x_target + w_target == x_object || y_target + l_target == y_object) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int check_unoverlap(Point* possible_point, int length_object, int width_object, Building *B_element_2) {

	int x_o = possible_point->x, y_o = possible_point->y;
	int l_o = length_object, w_o = width_object;
	int x_e2 = B_element_2->left_bottom_point->x;
	int y_e2 = B_element_2->left_bottom_point->y;
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

int main_cnt_shared_part_of_side (Building *B_mainb, Building *B_element_1, Building *B_element_2) {

	int cnt_e1 = 0, cnt_e2 = 0;
	int cnt = 0;

	cnt_e1 = cnt_shared_part_of_side(B_mainb, B_element_1);
	cnt_e2 = cnt_shared_part_of_side(B_mainb, B_element_2);

	cnt = cnt_e1 + cnt_e2;

	return cnt;
}

// 辺のうち何マスが埋まっているか計算する関数 
int cnt_shared_part_of_side (Building *B_mainb, Building *B_element_1) {

	// int id = -1; // -1 -> none 0->top or bottom 1->left or right
	
	int coordinate = 0, cnt_share = 0;

	int mainb_x = B_mainb->left_bottom_point.x, mainb_y = B_mainb->left_bottom_point.y;
	int e1_x = B_element_1->left_bottom_point.x, e1_y = B_element_1->left_bottom_point.y;
	int mainb_length = B_mainb->B_length, mainb_width = B_mainb->B_width;
	int e1_length = B_element_1->B_length, e1_width = B_element_1->B_width;

	if(mainb_y + mainb_length == e1_y || mainb_y - e1_length == e1_y) {
	

		coordinate = (mainb_x < e1_x) ? mainb_x : e1_x;
		
		
		while(1) {
			if (coordinate < mainb_x || coordinate < e1_x) {
				coordinate++;
			}

			if (mainb_x <= coordinate && coordinate <= mainb_x + mainb_width && e1_x <= coordinate && coordinate <= e1_x + e1_width) {
				cnt_share++;
				coordinate++;
			}

			if (coordinate > mainb_x + mainb_width || coordinate > e1_x + e1_length) {
				break;
			}
		}
				

		return cnt_share;
	}
		
	if(mainb_x - e1_width == e1_x || mainb_x + mainb_length == e1_x) {
		
		coordinate = (mainb_y < e1_y) ? mainb_y : e1_y;

		while(1) {
			if (coordinate < mainb_y || coordinate < e1_Y) {
				coordinate++;
			}

			if (mainb_y <= coordinate && coordinate <= mainb_y + mainb_length && e1_y <= coordinate && coordinate <= e1_y + e1_length) {
				cnt_share++;
				coordinate++;
			}

			if (coordinate > mainb_y + mainb_length || coordinate > e1_y + e1_length) {
				break;
			}
		}
		
		return cnt_share;
	}

}


// map上に存在するtargetとobjectを隣接させたい時、objectの可能な座標を教えてくれる関数。
void store_possible_point(Building *B_target, Building *B_object, Building *B_element_2, LinkedList_Possible_Point *LinkedList_object_possible_point) {
	
	int cnt_object_possible_point = 0;

	// 上隣接
	for(i=(B_target->left_bottom_point.x + 1 - B_object->B_width); i < (B_target->left_bottom_point.x + B_target->B_width); i++) {
		Point *p = point_init(i, B_target->left_bottom_point.y + B_target->B_length);

		if (check_unoverlap(p, *(B_object->B_length), *(B_object->B_width), B_element_2) == 1 && is_adjacent(B_object, B_element_2) == 0) {

			push_LinkedList_possible_point(LinkedList_object_possible_point, p);
	
			cnt_object_possible_point++;
		}

	}

	//　下隣接
	for(i=(B_target->left_bottom_point.x + 1 - B_object->B_width); i < (B_target->left_bottom_point.x + B_target->B_width); i++) {

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

// 物件mainbと専門街Sを受け取り、可能な配置をLinkedList_possible_relative_position配列に入れて、要素数を返す関数

extern int generate_list_possible_relative_position(Building *B_mainb, LinkedList_SpecialTown *LinkedList_specialtown_regards_mainb, LinkedList_Possible_Relative_Position *LinkedList_possible_relative_position) {


	Building B_null = building_null(), *B_element_1, *B_element_2;
	B_element_1 = &B_null;
	B_element_2 = &B_null;

	// element_1 & element_2 にBuilding情報を格納したい

	int i,j,k,l;
	int isnum_mainb = -1; // mainb が専門街の何番目の要素か
//	int cnt_LinkedList_possible_relative_position = 0;

	for (i=0; i<3; i++) {

		if (B_mainb == LinkedList_specialtown_regards_mainb->trio_building_compose_specialtown[i]);
		isnum_mainb = i;
		break;
	} // mainbを各専門街から検索

	if(isnum_mainb == -1) {
		printf("Error, mainb is not found from st_regards_mainb");
	}

	switch (isnum_mainb) {
		case 0 : B_element_1 = LinkedList_specialtown_regards_mainb->trio_building_compose_specialtown[1]; B_element_2 = LinkedList_specialtown_regards_mainb->trio_building_compose_specialtown[2]; break;
		case 1 : B_element_1 = LinkedList_specialtown_regards_mainb->trio_building_compose_specialtown[0]; B_element_2 = LinkedList_specialtown_regards_mainb->trio_building_compose_specialtown[2]; break;
		case 2 : B_element_1 = LinkedList_specialtown_regards_mainb->trio_building_compose_specialtown[0]; B_element_2 = LinkedList_specialtown_regards_mainb->trio_building_compose_specialtown[1]; break;
		case default : break;
	}

	// mainbの位置によって、element1,2にどれを入れればいいか指定している。
	//
	// まず、pattern_a -> mainb|e_a, e_a|e_bの場合を考える。
	
	for(l=0; l<2; l++) {

		// まず、e1の可能な配置の左下座標を求めたい。
		LinkedList_Possible_Point *LinkedList_e1_possible_point = make_LinkedList_possible_point;

		int cnt_e1_possible_point = store_possible_point(B_mainb, B_element_1, &(building_null()), LinkedList_e1_possible_point);

		for (i=0; i<cnt_e1_possible_point; i++) {

			LinkedList_Possible_Point *LinkedList_e2_possible_point = make_LinkedList_possible_point;

			int cnt_e2_possible_point = store_possible_point(B_element_1, B_element_2, B_mainb, LinkedList_e2_possible_point);

			for(k=0; k<cnt_e2_possible_point; k++) {

				push_LinkedList_possible_relative_position(llprp, prp); 
				/*LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].specialtown = *LinkedList_specialtown_regards_mainb; 
				LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].possible_point_x1 = *(LinkedList_e1_possible_point + i);
				LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].possible_point_x2 = *(LinkedList_e2_possible_point + k);
				LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].cnt_dominated_mainbs_adjacent_square = main_cnt_shared_part_of_side(B_mainb, B_element_1, B_element_2);// 辺の専有数を計算しないといけない
		*/		cnt_LinkedList_possible_relative_position++;
			}

			free(LinkedList_e2_possible_point)
		}

		free(LinkedList_e1_possible_point);

		if (i==0) { 
			Building B_temp;
			B_temp = *B_element_1;
			*B_element_1 = *B_element_2;
			*B_element_2 = B_temp;
		}

		// これでelement_1とelement_2が入れ替わったはず

	}


	// 最後にmainb|e1, mainb|e2のパターンをやる
	

	Point *LinkedList_e1_possible_point;
	LinkedList_e1_possible_point = malloc(sizeof(Point) * 100);

	for(i=0; i<100; i++) {
		*(LinkedList_e1_possible_point + i) = point_init(-1,-1);
	} //初期化ここまで


	// LinkedList_possible_relative_position のサイズをどうするか？
	int cnt_e1_possible_point = store_possible_point(B_mainb, B_element_1, building_null(), LinkedList_e1_possible_point);

	for (i=0; i<cnt_e1_possible_point; i++) {

		Point *LinkedList_e2_possible_point;
		LinkedList_e2_possible_point = malloc(sizeof(Point) * 1000);

		for (j=0; j<1000; j++) {
			*(LinkedList_e2_possible_point + j) = point_init(-1, -1);
		}

		int cnt_e2_possible_point = store_possible_point(B_mainb, B_element_2, B_element1, LinkedList_e2_possible_point);

		for(k=0; k<cnt_e2_possible_point; k++) {
			LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].specialtown = *LinkedList_specialtown_regards_mainb; 
			LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].possible_point_x1 = *(LinkedList_e1_possible_point + i);
			LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].possible_point_x2 = *(LinkedList_e2_possible_point + k);
			LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].cnt_dominated_mainbs_adjacent_square = main_cnt_shared_part_of_side(B_mainb, B_element_1, B_element_2);// 辺の専有数を計算しないといけない
			cnt_LinkedList_possible_relative_position++;
		}

		free(LinkedList_e2_possible_point)
	}

	free(LinkedList_e1_possible_point);


	return cnt_LinkedList_possible_relative_position;
}


/*	for(i=(B_mainb->left_bottom_point.x + 1 - B_element_1->B_width); i < (B_mainb->left_bottom_point.x + B_mainb->B_width); i++) {
		B_element_1.left_bottom_point.x = i;
		B_element_1.left_bottom_point.y = B_mainb->left_bottom_point.y + B_mainb->B_length;

		
	}


	// ここから隣接のしかたによって3つのパターンに分岐したい
*	
	cnt_LinkedList_possible_relative_position[0] = adjacent_pattern_a(B_mainb, B_element_1, B_element_2, p_possible_relative_position);

	cnt_LinkedList_possible_relative_position[1] = adjacent_pattern_b(B_mainb, B_element_1, B_element_2, p_possible_relative_position, cnt_LinkedList_possible_relative_position[0]);

	cnt_LinkedList_possible_relative_position[2] = adjacent_pattern_c(B_mainb, B_element_1, B_element_2, p_possible_relative_position, cnt_LinkedList_possible_relative_position[1]);
	// pattern A が終わったら、要素への格納を次の位置から始めたい

	//可能なxs1,xs2の相対座標はリストに入り、かつその個数はcnt_LinkedList_possible_relative_position[2]に入っている。
	
*/
