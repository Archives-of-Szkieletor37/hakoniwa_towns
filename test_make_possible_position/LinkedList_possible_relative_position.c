#include <stdio.h>
#include <stdlib.h>
#include "LinkedList_possible_relative_position.h"


int cnt_llprp_element = 0;

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
extern LinkedList_Possible_Relative_Position *make_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp, Possible_Relative_Position prp) {

	LinkedList_Possible_Relative_Position *new_llprp = malloc(sizeof(LinkedList_Possible_Relative_Position));

	if (new_llprp != NULL) {
		new_llprp->prp = prp;
		new_llprp->next_llprp = llprp;

		/*if(llprp->prp == NULL) {
			free_possible_relative_position(llprp->prp);
			free(llprp); // 入れ子構造体の子のmallocって別々にfree()しなくていいのだろうか
		}*/
			
		return new_llprp;
	}
}


extern void delete_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position **llprp_ptr) {

	
	LinkedList_Possible_Relative_Position **temp;
	while(llprp_ptr != NULL) {
		temp = &((*llprp_ptr)->next_llprp);
		free(*llprp_ptr);
		llprp_ptr = temp;
	}
}

extern LinkedList_Possible_Relative_Position *nth_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position *llprp, int n) {

	int cnt = -1;

	while (cnt < n) {
		if(llprp == NULL) {
			return NULL;
		}
		else {
			llprp = llprp->next_llprp;
			cnt++;
		}
	}

	return llprp;

}

extern int insert_nth_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position **llprp_ptr, Possible_Relative_Position prp, int n) {
	
	//int i;
	LinkedList_Possible_Relative_Position *llprp_temp;

	if (n<0) {
		return 0;
	}
	llprp_temp = nth_LinkedList_possible_relative_position(*llprp_ptr, n-1);
	llprp_ptr = &(llprp_temp);	
	(*llprp_ptr)->next_llprp = make_LinkedList_possible_relative_position(llprp_temp->next_llprp, prp);


	return 1; 
	/*int i;
	LinkedList_Possible_Relative_Position *prp_temp;

	if (n<0) {
		return 0;
	}

	for (i=-1; i<n && *llprp_ptr !=NULL; i++) {
		llprp_ptr = &((*llprp_ptr)->next_llprp);
	}

	if(i<n) {
		return 0;
	}
	prp_temp = make_LinkedList_possible_relative_position(*llprp_ptr, prp);
	if(prp_temp == NULL) {
		return 0;
	}
	*llprp_ptr = prp_temp;*/
/*LinkedList_Possible_Relative_Position *nth_llprp = nth_LinkedList_possible_relative_position(*llprp_ptr, n-1);

	if (nth_llprp == NULL) {
		return 0;
	}
	
	llprp_ptr = &nth_llprp;
	LinkedList_Possible_Relative_Position *insert_target_llprp = make_LinkedList_possible_relative_position(*llprp_ptr, prp);

	if(insert_target_llprp == NULL) {
		return 0;
	}

	*(llprp_ptr) = insert_target_llprp;
*/
	return 1;
}

int push_LinkedList_possible_relative_position(LinkedList_Possible_Relative_Position **llprp_ptr, Possible_Relative_Position prp) {


	return insert_nth_LinkedList_possible_relative_position(llprp_ptr, prp, 0);
	
}

// 物件mainbと専門街Sを受け取り、可能な配置をp_LinkedList_possible_relative_position配列に入れて、要素数を返す関数

void store_prp_to_LinkedList(SpecialTown *specialtown, Building *B_mainb, Building *B_element_1, Building *B_element_2, int flag, LinkedList_Possible_Relative_Position **llprp_ptr) {
	
	printf("\nstore_prp_to_LinkedListに入るよ\n");

	int i,k;
	int cnt_e1_possible_point = 0;
	int cnt_e2_possible_point = 0;
	Building B_null, *p_B_null;
	B_null = building_null(), p_B_null = &B_null;
	int cnt_dominated_mainbs_adjacent_square;
	if(flag == 1) {
		Building *temp; 
		temp = B_element_1;
		B_element_1 = B_element_2;
		B_element_2 = temp;
	}

	Point p = point_init(0,0,0);	
	LinkedList_Possible_Point *LinkedList_e1_possible_point = make_LinkedList_possible_point(p, NULL);
	LinkedList_Possible_Point **llpp_e1_ptr = &LinkedList_e1_possible_point, **llpp_e2_ptr = NULL;

	printf("まず%sが中心で、そのまわりに%sを置くことを考えるよ\n", B_mainb->B_name, B_element_1->B_name);

	cnt_e1_possible_point = store_possible_point(B_mainb, B_element_1, p_B_null, llpp_e1_ptr);

	printf("置ける位置が%d個出てきたよ\n", cnt_e1_possible_point);

	for (i=0; i<cnt_e1_possible_point; i++) {
	
		Point nth_p;
		nth_p.x = nth_LinkedList_possible_point(LinkedList_e1_possible_point, i)->p.x;
		nth_p.y = nth_LinkedList_possible_point(LinkedList_e1_possible_point, i)->p.y;
		
		printf("\nいま%sを座標(%d,%d)に置くことを考えてるよ\n", B_element_1->B_name, nth_p.x, nth_p.y);

		B_element_1->B_left_bottom_point = ((nth_LinkedList_possible_point(LinkedList_e1_possible_point, i))->p); //b_e1に座標を格納する
		printf("%d, %d\n", nth_LinkedList_possible_point(LinkedList_e1_possible_point, i)->p.x, nth_LinkedList_possible_point(LinkedList_e1_possible_point, i)->p.y);

		LinkedList_Possible_Point *LinkedList_e2_possible_point = make_LinkedList_possible_point(p, NULL);
		llpp_e2_ptr = &LinkedList_e2_possible_point;
		
		if(flag == 2) {
			printf("このパターンは建物%sと%sの両方が%sに隣接するよ\n", B_element_1->B_name, B_element_2->B_name, B_mainb->B_name);
			cnt_e2_possible_point = store_possible_point(B_mainb, B_element_2, B_element_1, llpp_e2_ptr);
		}
		else {
			printf("このパターンは%sのとなりに%sを置くことを考えてるよ。そのとき%sとは隣接しない、overlapしないようにしたいよ\n", B_element_1->B_name, B_element_2->B_name, B_mainb->B_name);

			cnt_e2_possible_point = store_possible_point(B_element_1, B_element_2, B_mainb, llpp_e2_ptr);
		}		
	
		printf("この座標では置けるパターンは%d種類発見されたよ\n", cnt_e2_possible_point);

		for(k=0; k<cnt_e2_possible_point; k++) {
			printf("%d",k);
			// まず、b_e2に座標を格納する。
//			B_element_1->B_left_bottom_point = *((nth_LinkedList_possible_point(LinkedList_e1_possible_point, i))->p);
			B_element_2->B_left_bottom_point = ((nth_LinkedList_possible_point(LinkedList_e2_possible_point, k))->p);

			//専有している周囲のマスの数を計算する。
			cnt_dominated_mainbs_adjacent_square += cnt_shared_part_of_side(B_mainb, B_element_1);
			cnt_dominated_mainbs_adjacent_square += cnt_shared_part_of_side(B_mainb, B_element_2);
			//次に、prpを作る。
			Possible_Relative_Position prp = make_possible_relative_position(specialtown, B_element_1, B_element_2, cnt_dominated_mainbs_adjacent_square);

			printf("e1の座標は%d, %d、e2の座標は%d, %d\n", B_element_1->B_left_bottom_point.x, B_element_1->B_left_bottom_point.y, B_element_2->B_left_bottom_point.x, B_element_2->B_left_bottom_point.y);
			printf("%d個目\n", cnt_llprp_element+1);
			// そして、それを連結リストにプッシュする。
			insert_nth_LinkedList_possible_relative_position(llprp_ptr, prp, cnt_llprp_element);
			Possible_Relative_Position nth_prp = nth_LinkedList_possible_relative_position(*llprp_ptr, cnt_llprp_element)->prp;
			printf("(%d, %d), (%d, %d)\n", nth_prp.b_e1->B_left_bottom_point.x, nth_prp.b_e1->B_left_bottom_point.y, nth_prp.b_e2->B_left_bottom_point.x, nth_prp.b_e2->B_left_bottom_point.y);
		//	printf("%d個目の要素がprpに格納されたよ\n",cnt_llprp_element);
			//連結リストの長さを+1する。
			cnt_llprp_element++;
		}
		
		//b_e1, b_e2の座標をリセットする
		
		//B_element_1->B_left_bottom_point = point_init(0,0,0);
		//B_element_2->B_left_bottom_point = point_init(0,0,0);
		delete_LinkedList_possible_point(llpp_e2_ptr);
	}
	
	delete_LinkedList_possible_point(llpp_e1_ptr);
//	printf("\nprpの連結リストの要素数は%dだよ\n", cnt_llprp_element);
	//return cnt_llprp_element;
}


extern int generate_LinkedList_of_prp(Building *B_mainb, SpecialTown *specialtown_regards_mainb, LinkedList_Possible_Relative_Position **llprp_ptr) {
	
	printf("generate_LinkedList_of_prpが呼び出されたよ\n");
	printf("%sが専門街の名前\n", specialtown_regards_mainb->ST_name);
	printf("%s, %s, %sが構成物の名前\n", specialtown_regards_mainb->trio_building_compose_specialtown[0]->B_name, specialtown_regards_mainb->trio_building_compose_specialtown[1]->B_name, specialtown_regards_mainb->trio_building_compose_specialtown[2]->B_name);
	Building B_null, *B_element_1, *B_element_2;
	B_null = building_null();
	B_element_1 = &B_null;
	B_element_2 = &B_null;

	// element_1 & element_2 にBuilding情報を格納したい

	int i;
	int isnum_mainb = -1; // mainb が専門街の何番目の要素か
	//	int cnt_llprp_element = 0;

	for (i=0; i<3; i++) {

		if (B_mainb->id == specialtown_regards_mainb->trio_building_compose_specialtown[i]->id) {

			isnum_mainb = i;
			break;
		} // mainbを各専門街から検索
	}
	if(isnum_mainb == -1) {
		printf("Error, mainb is not found from st_regards_mainb");
	}

	switch (isnum_mainb) {
		case 0 : B_element_1 = specialtown_regards_mainb->trio_building_compose_specialtown[1]; B_element_2 = specialtown_regards_mainb->trio_building_compose_specialtown[2]; break;
		case 1 : B_element_1 = specialtown_regards_mainb->trio_building_compose_specialtown[0]; B_element_2 = specialtown_regards_mainb->trio_building_compose_specialtown[2]; break;
		case 2 : B_element_1 = specialtown_regards_mainb->trio_building_compose_specialtown[0]; B_element_2 = specialtown_regards_mainb->trio_building_compose_specialtown[1]; break;
		default : break;
	}

	printf("いまの専門街の中心は%sで、一番目の要素は%sで、２番めの要素は%sだよ。中心は%d番目に入ってるよ\n", B_mainb->B_name, B_element_1->B_name, B_element_2->B_name, isnum_mainb);
	// mainbの位置によって、element1,2にどれを入れればいいか指定している。
	// element1,2の格納は終わり
	//
	for(i=0; i<3; i++) {

		store_prp_to_LinkedList(specialtown_regards_mainb, B_mainb, B_element_1, B_element_2,i,llprp_ptr);
		// まず、mainb|e_a, e_a|e_bの場合を考える。
		// mainb|e_b, e_a|e_b
		// mainb|e_a, mainb|e_b
	}	
	return cnt_llprp_element;
}

