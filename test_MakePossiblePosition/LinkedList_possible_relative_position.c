// LinkedList_possible_relative_position.c
//


#include <stdio.h>
#include "LinkedList_possible_relative_position.h"
#include "possible_point.h"
#include <stdlib.h>
/*extern LinkedList_Possible_Relative_Position possible_relative_position_null(void) {

	LinkedList_Possible_Relative_Position prp;
	prp.DS_specialtown = dictionary_specialtown_null();
	prp.possible_point = point_null();
	prp.cnt_dominated_mainbs_adjscent_square = -1;
	prp.next_prp =NULL;

	return prp;
}
*/
/*extern LinkedList_Possible_Relative_Position possible_relative_position_init(Dictionary_SpecialTown* p_DS_specialtown, Point possible_point) {

	LinkedList_Possible_Relative_Position prp;
	prp.DS_specialtown = *p_DS_specialtown;
	prp.possible_point = possible_point;
	prp.cnt_dominated_mainbs_adjacent_square = -1;
	prp.next_prp = NULL;
	return prp;

}
*/
extern LinkedList_Possible_Relative_Position *make_LinkedList_possible_relative_position(void) {

	LinkedList_Possible_Relative_Position *llprp = malloc(sizeof(LinkedList_Possible_Relative_Position));

	if (llprp != NULL) {
		llprp->prp = make_possible_relative_position();
		llprp->next_llprp = NULL;

		if(llprp->prp == NULL) {
			free_possible_relative_position(llprp->prp);
			free(llprp); // 入れ子構造体の子のmallocって別々にfree()しなくていいのだろうか
		}
			
		return llprp;
	}
}


extern void delete_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp) {

	
	LinkedList_Possible_Relative_Position *temp;
	while(llprp != NULL) {
		temp = llprp->next_llprp;
		free_possible_relative_position(llprp->prp);
		free(llprp);
		llprp = temp;
	}
}

extern LinkedList_Possible_Relative_Position *nth_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp, int n) {

	int cnt = -1;

	while (cnt < n) {
		if(llprp->next_llprp == NULL) {
			return NULL;
		}
		else {
			llprp = llprp->next_llprp;
			cnt++;
		}
	}

	return llprp;

}

extern int insert_nth_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp, Possible_Relative_Position *prp, int n) {
	LinkedList_Possible_Relative_Position *front_llprp = nth_LinkedList_possible_relative_position(llprp, n-1);

	if (front_llprp == NULL) {
		return 0;
	}

	LinkedList_Possible_Relative_Position *insert_target_llprp = make_LinkedList_possible_relative_position();

	if(insert_target_llprp == NULL) {
		return 0;
	}

	insert_target_llprp->next_llprp = front_llprp->next_llprp;
	front_llprp->next_llprp = insert_target_llprp;

	insert_target_llprp->prp = prp;// 引数のものを入れた

	return 1;
}

/*adjacent_pattern_a(Building *p_B_mainb, Building *p_B_element_1, Building *p_B_element_2, LinkedList_Possible_Relative_Position *p_possible_relative_position) {
 * 

	// mainb | e_a && mainb | e_b 
	


adjacent_pattern_b(Building *p_B_mainb, Building *p_B_element_1, Building *p_B_element_2, LinkedList_Possible_Relative_Position *p_possible_relative_position, start_num_to_store_p_list_prp);

adjacent_pattern_c(Building *p_B_mainb, Building *p_B_element_1, Building *p_B_element_2, LinkedList_Possible_Relative_Position *p_possible_relative_position, start_num_to_store_p_list_prp);

*/

// int cnt_LinkedList_possible_relative_position = 0;

/*
 * int put_2nd_building_adjacently_on_top(Building *p_B_object, Building *p_B_target, Dictionary_SpecialTown *p_DS_specialtown, LinkedList_Possible_Relative_Position *p_LinkedList_possible_relative_position) {

	// objectが置くもの、targetが隣接させたい目標
	LinkedList_Possible_Relative_Position prp_x1;
	//prp_x1.DS_specialtown = *p_DS_specialtown;
	
	int i;

	for(i=(p_B_target->left_bottom_point.x + 1 - p_B_object->B_width); i < (p_B_target->left_bottom_point.x + p_B_target->B_width); i++) {
		p_B_object.left_bottom_point.x = i;
		p_B_object.left_bottom_point.y = p_B_target->left_bottom_point.y + p_B_target->B_length;
	}


}

*/



bool is_adjacent(Building *p_B_target, Building *p_B_object) {

	if (*p_B_object == building_null()) {
		return false; //存在しなければそもそも隣接してない
	}
	else {
		int x_target = p_B_target->left_bottom_point.x, y_target = p_B_target->left_bottom_point.y;
		int l_target = p_B_target->B_length, w_target = p_B_target->B_width;
		int x_object = p_B_object->left_bottom_point.x, y_object = p_B_object->left_bottom_point.y;
		int l_object = p_B_object->B_length, w_object = p_B_object->B_width;

		if (x_target - w_object == x_object || y_target - l_object == y_object || x_target + w_target == x_object || y_target + l_target == y_object) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool check_overlap(Point *possible_point, int length_object, int width_object, Building *B_element_2) {

	int x_o = *(possible_point->x), y_o = *(possible_point->y);
	int l_o = length_object, w_o = width_object;
	int x_e2 = B_element_2->left_bottom_point.x;
	int y_e2 = B_element_2->left_bottom_point.y;
	int l_e2 = B_element_2->B_length;
	int w_e2 = B_element_2->B_width;

	if (*B_element_2 == building_null()) {
		return true; //存在していなければoverlapしない
	}

	else if(x_o + w_o > x_e2 || y_o + l_o > y_e2 || x_o - w_e2 < x_e2 || y_o - l_e2 < y_e2) {
		return false;
	}
	else {
		return true;
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
void put_adjacently_pattern_a(Building *p_B_target, Building *p_B_object, Building *p_B_element_2, LinkedList_Possible_Point *p_LL_object_possible_point) {

	int num_object_possible_point = 2 * (p_B_target->left_bottom_point.x + p_B_target->left_bottom_point.y + p_B_object->left_bottom_point.x + p_B_object->left_bottom_point.y) - 4;

	int cnt_object_possible_point = 0;

	/*Point LinkedList_object_possible_point[cnt_object_possible_point], *p_LinkedList_object_possible_point;
	p_LinkedList_object_possible_point = LinkedList_object_possible_point;

	for(i=0; i<cnt_object_possible_point; i++) {
		*(p_LinkedList_object_possible_point + i) = point_init(-1,-1);
	} //初期化ここまで*/

	int x=0,y=0;
	int *p_x = &x, *p_y = &y;
	int flag = 1, *p_flag = &flag;
	// 上隣接
	for(i=(p_B_target->left_bottom_point.x + 1 - p_B_object->B_width); i < (p_B_target->left_bottom_point.x + p_B_target->B_width); i++) {
	
		x = i;
		y = p_B_target->left_bottom_point.y + p_B_target->B_length;
		Point p = point_init(p_x, p_y, flag);
		Point *p_p = &p;

		if (check_overlap(p_p, p_B_object->B_length, p_B_object->B_width, p_B_element_2) == true && is_adjacent(p_B_object, p_B_element_2) == false) {
			insert_nth_LinkedList_possible_point(p_LL_object_possible_point, 0, p_p); 
			//*(p_LinkedList_object_possible_point + cnt_object_possible_point)->p.x = i;
			//*(p_LinkedList_object_possible_point + cnt_object_possible_point)->p.y = p_B_target->left_bottom_point.y + p_B_target->B_length;

			//cnt_object_possible_point++;
		}

	}

	//　下隣接
	for(i=(p_B_target->left_bottom_point.x + 1 - p_B_object->B_width); i < (p_B_target->left_bottom_point.x + p_B_target->B_width); i++) {
		x = i;
		y = p_B_target->left_bottom_point.y + p_B_target->B_length;
		Point p = point_init(p_x, p_y, flag);
		Point *p_p = &p;

		if (check_overlap(p_p, p_B_object->B_length, p_B_object->B_width, p_B_element_2) == true && is_adjacent(p_B_object, p_B_element_2) == false) {
			insert_nth_LinkedList_possible_point(p_LL_object_possible_point, 0, p_p); 
			//*(p_LinkedList_object_possible_point + cnt_object_possible_point).x = i;
			//*(p_LinkedList_object_possible_point + cnt_object_possible_point).y = p_B_target->left_bottom_point.y - p_B_object->B_length;

			//cnt_object_possible_point++;

		}
	}
	
	// 左隣接
	for(i=(p_B_target->left_bottom_point.y + 1 - p_B_object->B_length); i < (p_B_target->left_bottom_point.y + p_B_target->B_width); i++) {
		x = i;
		y = p_B_target->left_bottom_point.y + p_B_target->B_length;
		Point p = point_init(p_x, p_y, flag);
		Point *p_p = &p;

		if (check_overlap(p_p, p_B_object->B_length, p_B_object->B_width, p_B_element_2) == true && is_adjacent(p_B_object, p_B_element_2) == false) {
			insert_nth_LinkedList_possible_point(p_LL_object_possible_point, 0, p_p); 
			//*(p_LinkedList_object_possible_point + cnt_object_possible_point).x = p_B_target->left_bottom_point.x - p_B_object->B_width;
			//*(p_LinkedList_object_possible_point + cnt_object_possible_point).y = i;
			//cnt_object_possible_point++;
		}
	}

	// 右隣接
	for(i=(p_B_target->left_bottom_point.y + 1 - p_B_object->B_length); i < (p_B_target->left_bottom_point.x + p_B_target->B_width); i++) {
		x = i;
		y = p_B_target->left_bottom_point.y + p_B_target->B_length;
		Point p = point_init(p_x, p_y, flag);
		Point *p_p = &p;

		if (check_overlap(p_p, p_B_object->B_length, p_B_object->B_width, p_B_element_2) == true && is_adjacent(p_B_object, p_B_element_2) == false) {
			insert_nth_LinkedList_possible_point(p_LL_object_possible_point, 0, p_p); 
			/**(p_LinkedList_object_possible_point + cnt_object_possible_point).x = p_B_target->left_bottom_point.x + p_B_target->B_width;
			*(p_LinkedList_object_possible_point + cnt_object_possible_point).y = i;
			cnt_object_possible_point++; */
		}
	}

	// p_LL_object_possible_point に全パターンが入った。
	
	//Point *LinkedList = malloc(sizeof(Point) * cnt_object_possible_point);

	return cnt_object_possible_point;

}

// 物件mainbと専門街Sを受け取り、可能な配置をp_LinkedList_possible_relative_position配列に入れて、要素数を返す関数

extern int generate_list_possible_relative_position(Building *p_B_mainb, Dictionary_Specialtown *p_DS_specialtown, LinkedList_Possible_Relative_Position *p_LinkedList_possible_relative_position) {


	Building B_element_1, B_element_2, *p_B_element_1, *p_B_element_2;
	p_B_element_1 = &B_element_1;
	p_B_element_2 = &B_element_2;
	
	*p_B_element_1 = building_null();
	*p_B_element_2 = building_null();
// element_1 & element_2 にBuilding情報を格納したい

	int i,j,k,l;
	int isnum_mainb = -1; // mainb が専門街の何番目の要素か
//	int cnt_LinkedList_possible_relative_position = 0;

	for (i=0; i<3; i++) {

		if (*p_B_mainb == p_DS_specialtown->trio_building_compose_specialtown[i]);
		isnum_mainb = i;
		break;
	}

	switch (isnum_mainb) {
		case 0 : *p_B_element_1 = p_DS_specialtown->trio_building_compose_specialtown[1]; *p_B_element_2 = p_DS_specialtown->trio_building_compose_specialtown[2]; break;
		case 1 : *p_B_element_1 = p_DS_specialtown->trio_building_compose_specialtown[0]; *p_B_element_2 = p_DS_specialtown->trio_building_compose_specialtown[2]; break;
		case 2 : *p_B_element_1 = p_DS_specialtown->trio_building_compose_specialtown[0]; *p_B_element_2 = p_DS_specialtown->trio_building_compose_specialtown[1]; break;
		case default : break;
	}

	// まず、pattern_a -> mainb|e_a, e_a|e_bの場合を考える。
	
	for(l=0; l<2; l++) {

		LinkedList_Possible_Point *p_LinkedList_e1_possible_point = make_LinkedList_possible_point();
		//p_LinkedList_e1_possible_point = &LinkedList_e1_possible_point;
		//*p_LinkedList_e1_possible_point = LinkedList_Possible_Point_init();

		// まず、e1が置ける座標を全部持ってくる。
		// そのあと、それぞれについてe2が置ける座標を全部持ってくる。
		// このときforループはwhileループにして、NULLが来たら終了にすればよい。
		// 要素数のカウントはしなくてもよい？
		
		put_adjacently_pattern_a(p_B_mainb, p_B_element_1, building_null(), p_LinkedList_e1_possible_point);

		while(p_LinkedList_e1_possible_point != NULL) {
			LinkedList_Possible_Point *p_LinkedList_e2_possible_point = make_LinkedList_possible_point();
			put_adjacently_pattern_a(p_B_element_1, p_B_element_2, p_B_mainb, p_LinkedList_e2_possible_point);

			while(p_LinkedList_e2_possible_point != NULL) {
				// 処理を書く
				p_LinkedList_e2_possible_point = p_LinkedList_e2_possible_point->next_LL_possible_point;
			}

			p_LinkedList_e1_possible_point = p_LinkedList_e1_possible_point->next_LL_possible_point;
		}





		for (i=0; i<cnt_e1_possible_point; i++) {

			Point *p_LinkedList_e2_possible_point;
			p_LinkedList_e2_possible_point = malloc(sizeof(Point) * 1000);

			for (j=0; j<1000; j++) {
				*(p_LinkedList_e2_possible_point + j) = point_init(-1, -1);
			}

			int cnt_e2_possible_point = put_adjacently_pattern_a(p_B_element_1, p_B_element_2, p_B_mainb, p_LinkedList_e2_possible_point);

			for(k=0; k<cnt_e2_possible_point; k++) {
				p_LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].DS_specialtown = *p_DS_specialtown; 
				p_LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].possible_point_x1 = *(p_LinkedList_e1_possible_point + i);
				p_LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].possible_point_x2 = *(p_LinkedList_e2_possible_point + k);
				p_LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].cnt_dominated_mainbs_adjacent_square = main_cnt_shared_part_of_side(B_mainb, B_element_1, B_element_2);// 辺の専有数を計算しないといけない
				cnt_LinkedList_possible_relative_position++;
			}

			free(p_LinkedList_e2_possible_point)
		}

		free(p_LinkedList_e1_possible_point);

		if (i==0) { 
			Building B_temp;
			B_temp = *B_element_1;
			*B_element_1 = *B_element_2;
			*B_element_2 = B_temp;
		}

		// これでelement_1とelement_2が入れ替わったはず

	}


	// 最後にmainb|e1, mainb|e2のパターンをやる
	

	Point *p_LinkedList_e1_possible_point;
	p_LinkedList_e1_possible_point = malloc(sizeof(Point) * 100);

	for(i=0; i<100; i++) {
		*(p_LinkedList_e1_possible_point + i) = point_init(-1,-1);
	} //初期化ここまで


	// p_LinkedList_possible_relative_position のサイズをどうするか？
	int cnt_e1_possible_point = put_adjacently_pattern_a(B_mainb, B_element_1, building_null(), p_LinkedList_e1_possible_point);

	for (i=0; i<cnt_e1_possible_point; i++) {

		Point *p_LinkedList_e2_possible_point;
		p_LinkedList_e2_possible_point = malloc(sizeof(Point) * 1000);

		for (j=0; j<1000; j++) {
			*(p_LinkedList_e2_possible_point + j) = point_init(-1, -1);
		}

		int cnt_e2_possible_point = put_adjacently_pattern_a(B_mainb, B_element_2, B_element1, p_LinkedList_e2_possible_point);

		for(k=0; k<cnt_e2_possible_point; k++) {
			p_LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].DS_specialtown = *p_DS_specialtown; 
			p_LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].possible_point_x1 = *(p_LinkedList_e1_possible_point + i);
			p_LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].possible_point_x2 = *(p_LinkedList_e2_possible_point + k);
			p_LinkedList_possible_relative_position[cnt_LinkedList_possible_relative_position].cnt_dominated_mainbs_adjacent_square = main_cnt_shared_part_of_side(B_mainb, B_element_1, B_element_2);// 辺の専有数を計算しないといけない
			cnt_LinkedList_possible_relative_position++;
		}

		free(p_LinkedList_e2_possible_point)
	}

	free(p_LinkedList_e1_possible_point);


	return cnt_LinkedList_possible_relative_position;
}


/*	for(i=(p_B_mainb->left_bottom_point.x + 1 - p_B_element_1->B_width); i < (p_B_mainb->left_bottom_point.x + p_B_mainb->B_width); i++) {
		p_B_element_1.left_bottom_point.x = i;
		p_B_element_1.left_bottom_point.y = p_B_mainb->left_bottom_point.y + p_B_mainb->B_length;

		
	}


	// ここから隣接のしかたによって3つのパターンに分岐したい
*	
	cnt_LinkedList_possible_relative_position[0] = adjacent_pattern_a(p_B_mainb, p_B_element_1, p_B_element_2, p_possible_relative_position);

	cnt_LinkedList_possible_relative_position[1] = adjacent_pattern_b(p_B_mainb, p_B_element_1, p_B_element_2, p_possible_relative_position, cnt_LinkedList_possible_relative_position[0]);

	cnt_LinkedList_possible_relative_position[2] = adjacent_pattern_c(p_B_mainb, p_B_element_1, p_B_element_2, p_possible_relative_position, cnt_LinkedList_possible_relative_position[1]);
	// pattern A が終わったら、要素への格納を次の位置から始めたい

	//可能なxs1,xs2の相対座標はリストに入り、かつその個数はcnt_LinkedList_possible_relative_position[2]に入っている。
	
*/
