#include <stdio.h>
#include <string.h>
#include "dictionary_specialtown.h"
#include "dictionary_building.h"

#define MAPWIDTH 30
#define MAPLENGTH 30
#define SPECIALTOWNSUM 150
#define MAX_SPECIALTOWN_PER_BUILDING 20
//すべての配列はinitializeする
//

int cnt_district_pattern = 0;

typedef struct {

	int x,y;

} Point;

/*typedef struct {

	char ST-name[20];
	bool flag_existance; // 存在するならtrue

} SpecialTown;
*/
typedef struct  {

	char B_name[20];
	Point left_bottom_point; // left, bottom
	int B_length;
	int B_width;

} Building;

typedef struct  {
	
	Building main; //中心になる建物
	Building list_existed_building[100]; //すでに建っている建物
	int cnt_existed_building;
	Building district_map[MAPWIDTH][MAPLENGTH]; //地区のマップ 
	Dictionary_SpecialTown DS_list_specialtown_regards_mainb[MAX_SPECIALTOWN_PER_BUILDING];
	int cnt_DS_list_specialtown_regards_mainb;
	int district_length; //実際に何マス専有しているか
	int district_width;

} District;

typedef struct {
	Building B_instance;
	int sum_landprice_bonus_rate;
} Sum_Landprice_Bonus_Rate;

//マップと置く建物、隣接させたい建物のリストを受け取ってマップに格納する関数

/*Point point_init(Point target) {

	Point z;
	z.x = i_x;
	z.y = i_y;

	return z;
}*/

// Building building_init(char i_name[], point i_point, int i_length, int i_width) {




/* void initialize_district(District D_district) {

	D_district->cnt_existed_building = 0;
	district_length = 0;
	district_width = 0;
*/

void initial_put(Building *B_main, District *D_district) {
	
	B_main->left_bottom_point.x = MAPWIDTH/2;
	B_main->left_bottom_point.y = MAPLENGTH/2;

	int i,j;

	for(i=0; i<(B_main->B_width); i++) {
		for(j=0; j<(B_main->B_length); j++) {
			D_district->district_map[B_main->left_bottom_point.x + i][B_main->left_bottom_point.y + j] = *B_main;
		}
	}

}

int search_specialtown(Building *B_object, Dictionary_SpecialTown DS_list_specialtown[], Dictionary_SpecialTown list_specialtown_regards_mainb[]) {

	int cnt_specialtown_regards_mainb = 0;

	int i;

	for(i=0; i<SPECIALTOWNSUM; i++) {
		if (strcmp(DS_list_specialtown[i].trio_building_compose_specialtown[0], B_object->B_name) == 0) {
			list_specialtown_regards_mainb[cnt_specialtown_regards_mainb] = DS_list_specialtown[i];
			cnt_specialtown_regards_mainb++;
		}
	}

	return cnt_specialtown_regards_mainb;
}




		
void generate_specialtown(Building *B_main, Dictionary_SpecialTown list_specialtown[]) {

	District D_district, *p_D_district;
	p_D_district = &D_district;

	p_D_district->main = *B_main;

	// main_buildingの配置

	initial_put(B_main, p_D_district);
	p_D_district->list_existed_building[0] = B_main;
	p_D_district->cnt_existed_building++;

	// main_buildingに関係する専門街を抽出
	Dictionary_SpecialTown list_specialtown_regards_mainb[20];
	
	p_D_district->cnt_DS_list_specialtown_regards_mainb = search_specialtown(B_main, list_specialtown, p_D_district->DS_list_specialtown_regards_mainb);

	int i,j,k;

/*	for(i=0; i < cnt_specialtown_regards_mainb; i++) {
		D_district->DS_list_specialtown_regards_mainb[i] = list_specialtown_regards_mainb[i];
	}

	*/

	Sum_Landprice_Bonus_Rate R_list_building_regards_mainb[40], *p_R_list_building_regards_mainb;
	*p_R_list_building_regards_mainb = R_list_building_regards_mainb;
	
	int cnt_building_regards_mainb = 0;

	for(k = 1; k < 3; k++) {
		for(i = 0; i < cnt_specialtown_regards_mainb; i++) {
			if (cnt_building_regards_mainb == 0) {
				(p_R_list_building_regards_mainb + cnt_building_regards_mainb)->B_instance = p_D_district->DS_list_specialtown_regards_mainb[i].trio_building_compose_specialtown[k];
					cnt_building_regards_mainb++;
			}
			else {
				for (j = 0; j < cnt_building_regards_mainb; j++) {
					if ((p_R_list_building_regards_mainb + j)->B_instance == p_D_district->DS_list_specialtown_regards_mainb[i].trio_building_compose_specialtown[k]) {
						break;
					}
					if (j == cnt_building_regards_mainb-1) {
						(p_R_list_building_regards_mainb + cnt_building_regards_mainb)->B_instance = p_D_district->DS_list_specialtown_regards_mainb[i].trio_building_compose_specialtown[k];
						(p_R_list_building_regards_mainb + cnt_building_regards_mainb)->sum_landprice_bonus_rate += p_D_district->DS_list_specialtown_regards_mainb[i].landplace_bonus_rate;
						cnt_building_regards_mainb++;
					}
				}
			}
		}
	}
	
	Sum_Landprice_Bonus_Rate *temp;

	for(i = 0; i < cnt_building_regards_mainb - 1; i++) {
		for(j = cnt_building_regards_mainb - 1; j > i; j--) {
			if((p_R_list_building_regards_mainb + j)->sum_landprice_bonus_rate < (p_R_list_building_regards_mainb + j-1)->sum_landprice_bonus_rate) {
				temp = (p_R_list_building_regards_mainb + j);
				(p_R_list_building_regards_mainb + j) = (p_R_list_building_regards_mainb + j - 1);
				(p_R_list_building_regards_mainb + j - 1) = temp;
			}
		}
	}

	put_building_regards_mainb(p_R_list_building_regards_mainb, cnt_building_regards_mainb, 0, p_D_district);

	// 建築物の優先順位をつけてリストに入れた
	

int put_building_regards_mainb(Sum_Landprice_Bonus_Rate *p_R_list_ranked_building_regards_mainb, int cnt_list_ranked_building_regards_mainb, int head, District *D_district) {

	if(head == cnt_list_ranked_building_regards_mainb) {
		print_district(D_district);
		cnt_district_pattern++;
		return 0;
	}
		

	int i;

	Building B_target, *p_B_target;
	p_B_target = &B_target;
	(p_R_list_ranked_building_regards_mainb + head)->B_instance = *p_B_target;
	head++;

	// 中心になる建物

	Building B_central, *p_B_central;
	p_B_central = &B_central;
	*p_B_central = D_district->main;

	Building B_make_specialtown_with_target_and_central[5];
	
	int cnt_B_make_specialtown_with_target_and_central = 0;

	// targetとcentralの両方から専門街を作れる建築物をB_make_specialtown_with_target_and_centralに格納

	for(i=0; i<(D_district->cnt_DS_list_specialtown_regards_mainb); i++) {
		if(*p_B_target == D_district->DS_list_specialtown_regards_mainb[i].trio_building_compose_specialtown[1]) {
			B_make_specialtown_with_target_and_central[cnt_B_make_specialtown_with_target_and_central] = D_district->DS_list_specialtown_regards_mainb.trio_building_compose_specialtown[2];
			cnt_B_make_specialtown_with_target_and_central++;
		}
		else if (*p_B_target == D_district->DS_list_specialtown_regards_mainb.trio_building_compose_specialtown[2]) {
			make_specialtown_with_target_and_central[cnt_B_make_specialtown_with_target_and_central] = D_district->DS_list_specialtown_regards_mainb.trio_building_compose_specialtown[1];
			cnt_B_make_specialtown_with_target_and_central++;
		}
	}


	int cnt_B_list_to_put_target_optimizely;
	Building B_list_to_put_target_optimizely[5];

	B_list_to_put_target_optimizely[0] = *p_B_central;
	cnt_B_list_to_put_target_optimizely++;


	// 街にすでに存在しているものを抽出（centralを含む）
	for(i=0; i<cnt_B_make_specialtown_with_target_and_central; i++) {
		for (j=0; j < cnt_of_already_existing_building; j++) {
			if(B_make_specialtown_with_target_and_central[i] == D_district->list_existed_building[j]) {
				B_list_to_put_target_optimizely[cnt_B_list_to_put_target_optimizely] = D_district->list_existed_building[j];
				cnt_B_list_to_put_target_optimizely++;
			}
		}
	}
	
	
	for (i=0; i<cnt_B_list_to_put_target_optimizely; i++) {
		if (put_target(D_district, B_target, &B_list_to_put_target_optimizely[i]) == false) {
			print_district(D_district);
			cnt_district_pattern++;
			return 0;
		}
	 //targetを配置
		else {
			put_building_regards_mainb(R_list_ranked_building_regards_mainb, cnt_list_ranked_building_regards_mainb, head, D_district); 
		}
	}

}

bool put_target(District *D_district, Building *B_object, Building *B_target) {


	int cnt_target = sizeof(B_target[])/sizeof(Building);

	int i,j;
	int *cnt;

	*cnt = 0;

	Point choice[];	// 置ける座標の候補を確認

	for(i = 0; i < cnt_target; i++) {
		int x_B_target = B_target[i]->left_bottom_point->x;
		int y_B_target = B_target[i]->left_bottom_point->y;
		
		// 左側に接する場合
		left_adjacent()


		for(j=(y_B_target+1_(B_target[i]->B_length)); j < (y_B_target+(B_target[i]->B_length)); j++) {
			
			Point check; 

			check->x = x_B_target_(object->width);
			check->y = j;

			if(check_area(map, check, object)) { // 置きたいところに他の建築物がないかチェックする関数
				choice[cnt]->x = check->x;
				choice[cnt]->y = check->y;
				cnt++;
			}
		}
	}
	
	//同様に右側、上側、下側も処理する

	// この時点でchoiceにobjectを置ける座標一覧が入っている。
	
	int cnt_choice = sizeof(choice)/sizeof(Point); //choice配列のサイズ

	bool visited[cnt_choice];

	for(i=0; i<cnt_choice; i++) {
		visited[i] = false;
	}

	for(i=0; i<cnt_choice; i++) {
		Building B_alias; // 座標がchoice[i]のobjectの複製を作る
		B_alias->id = object->id;
		B_alias->B_length = object->B_length;
		B_alias->width = object->width; // ここはまとめられる
		B_alias->left_bottom_point = choice[i];

		for(s = 0; s < object->width; s++) {
			for(t = 0; t < object->B_length; t++) {

				map[(choice[i]->x)+s][(choice[i]->y)+t] = B_alias; //mapの更新
			}
		}
		



	}

//専門街の組み合わせを返す関数
//建物を受け取って、リストから専門街を作る候補を検索する。
//候補のうち、高い順位のものから隣接させる。
	
void possible_D_districts(Building building, *District D_district, *Special_Town st_list) { 
	

	int i;

	Special_Town towns[];

	Building list_ranked_building[];
	
	stsearch(building, st_list, *towns); // towns に専門街情報が入る
	
	rank_building(*towns, *list_ranked_building); //list_ranked_buildingに設置順の候補を入れる。
	
	initial_build(building, *(D_district->D_district_map)); //中心にbuildingを設置する

	int cnt_of_choice = sizeof(list_ranked_building)/sizeof(Building);

	for (i=0; i < cnt_of_choice; i++) {
		list_ranked_building[i]->visited = false;
	}

	for (i=0; i < cnt_of_choice; i++) {

		if(is_build(list_ranked_building[i], D_district->D_district_map)) {
			build_D_district(list_ranked_building[i], *(D_district->D_district_map));
		}
		else 
	}
}


int main(int argc, char *argv[]){

	// 
	special_towns st_list[200];  
}
