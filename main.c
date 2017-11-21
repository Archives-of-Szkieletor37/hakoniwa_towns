#include <stdio.h>
#include "point.h"
#include "building.h"
#include "dictionary_building.h"
#include "specialtown.h"
#include "possible_relative_position.h"
#include "eval_result_of_combination.h"


int main(int argc, char* argv[]) {


	put_data_of_building_to_dictionary();
	
	put_data_of_specialtown_to_dictionary();

	// まず、第一引数の名前でDBを検索する。	 

	Building *mainb = search_building_from_dictionary(argv[0]);

	if (mainb == NULL) {
		// エラー
	}

	LinkedList_specialtown *LinkedList_specialtown_regards_mainb = make_LinkedList_specialtown(make_empty_specialtown()); // 中心になる建物に関わる専門街を連結リストに格納, 連結リストは空ヘッダをいれておく
	
	LinkedList_specialtown_regards_mainb = search_specialtown_from_dictionary(LinkedList_specialtown_regards_mainb, mainb);

	if (LinkedList_specialtown_regards_mainb == NULL) {
		// エラー
	}


	/*int B_mainb_length, B_mainb_width;

	int i;

	for(i=0; i<NUMBUILDING; i++) {
		if (strcmp(dictionary_building[i].DB_name, argv[0]) == 0) {
			B_mainb_length = dictionary_building[i].DB_length;
			B_mainb_width = dictionary_building[i].DB_width;
			break;
		}
	}
*/
//	*p_B_mainb = building_init(argv[0], point_init(&zero, &zero, &flag_t), B_mainb_length, B_mainb_width);

	// ここから
/*	SpecialTown list_specialtown_regards_mainb[20], *p_DS_list_specialtown_regards_mainb;
	p_DS_list_specialtown_regards_mainb = DS_list_specialtown_regards_mainb;

	Building B_empty, *p_B_empty;
	p_B_empty = &B_empty;
	*p_B_empty = building_null();
	
	for (i=0; i< 20; i++) {
		*(p_DS_list_specialtown_regards_mainb + i) = DS_init("null", p_B_empty, p_B_empty, p_B_empty, -1);
	} // これも連結リストにしたほうがいいのかもしれない

	extract_specialtown(dictionary_building, p_B_mainb, p_DS_list_specialtown_regards_mainb);
*/	
	// specialtown regards mainb is now stored
	// 専門街の個数もグローバル変数cnt_specialtown_regards_mainbに格納された
	LinkedList_Possible_Relative_Position *LinkedList_possible_relative_position[cnt_specialtown_regards_mainb]; //専門街ごとに可能な配置を格納する連結リストを用意する。
	
	// mainbが関係するすべての専門街について、可能な置き方の格納を行う
	for(i=0; i<cnt_specialtown_regards_mainb; i++) {

		*LinkedList_possible_relative_position[i] = make_LinkedList_possible_relative_position();

		generate_list_possible_relative_position(mainb, LinkedList_specialtown, LinkedList_possible_relative_position[i]);

	}

	/* for(i=0; i<cnt_specialtown_regards_mainb; i++) {

		while(*LinkedList_possible_relative_position[i] == NULL) {
			if (is_putting_concurrently(*LinkedList_possible_relative_position[i], *LinkedList_possible_relative_position[i+1]) == true) {
				// 「これは組み合わせられます」配列に格納
				// 次の専門街へ

			
	}
*/
	// p_LinkedList_possible_relative_position[i] に、ある建築物Bと専門街Sについてのすべてのパターンが入った
	
	int *cnt_nth_position_in_LinkedList = malloc(sizeof(int) * cnt_specialtown_regards_mainb);
	// visited配列の代わり
	
	for (i=0; i<cnt_specialtown_regards_mainb; i++) {
		cnt_nth_position_in_LinkedList[i] = 0;
	} // 初期化

	LinkedList_Possible_Relative_Position *LinkedList_possible_position_combination= make_LinkedList_possible_relative_position();
	// 最後の結果を格納するための連結リスト
	
	LinkedList_position_best_16_combination = make_LinkedList_pair_of_position_combination_and_sum_bonus_rate();
	
	is_putting_concurrently(LinkedList_possible_relative_position, 0, cnt_nth_position_in_LinkedList, LinkedList_possible_position_combination, 0);

	return 0;

}

	// 可能な配置の連接リストが専門街ごとに存在して、それが配列にまとめられている。その連接リストの配列、いま何番目の専門街を考えているかというcount、そしてある専門街の何番目の数を考えているかというcount、すでに置くことが決まっている配置の（連接）リストを受け取り、それが同時に置けるか判定し、置けるなら配列に格納して同じことを繰り返す関数

int is_putting_concurrently(LinkedList_Possible_Relative_Position *LinkedList_possible_relative_position[]/* 連接リストの配列 */, int num_of_specialtown_now_consider/*いま何番目の専門街を考えているか*/, int cnt_nth_position_in_LinkedList[]/*ある専門街の何番目の配置を考えているか*/, LinkedList_Possible_Relative_Position *LinkedList_possible_position_combination /*すでに置くことが決まっている専門街の配置を格納した連接リスト*/, int cnt_specialtown_already_existed /* すでに置くことを決めた専門街の個数 */)

	int i = 0;
/**LinkedList_Possible_Relative_Position prp_specialtown1, **LinkedList_Possible_Relative_Position prp_specialtown2, int num_specialtown, int cnt_specialtown_already_existed, int sum_dominated_mainbs_adjacent_square) {
*/
	if (num_of_specialtown_now_consider = cnt_specialtown_regards_mainb) { // 最後の専門街のものを「置くと決めたリスト」にいれた、あるいは最後の専門街の全ての配置が「置くと決めたリスト」と重複した場合は、
		// 処理を書く
		//
		// まず、確定した配置を結果関数にぶちこむ
		eval_result_of_combination(LinkedList_possible_position_combination);	

		// そのあと、試してないパターンのところまでもどって処理を再開する
		if(cnt_specialtown_already_existed == 1 && num_of_specialtown_now_consider == 0 && (nth_LinkedList_possible_relative_position(LinkedList_possible_relative_position, cnt_nth_position_in_LinkedList[0])->next_llprp == NULL)) {  
		// 	もし、全てのパターンを試したら、すなわち「置くと決めたリスト」の要素数が1で、最初の専門街の配置の末尾ならば、
			free(cnt_nth_position_in_LinkedList);
			
			for (i = 0; i < DS_list_specialtown_regards_mainb; i++) {
				delete_LinkedList_possible_relative_position(LinkedList_possible_relative_position);
			}

			delete_LinkedList_possible_relative_position(LinkedList_possible_position_combination);
			print_position_combination(LinkedList_position_best_combination);	
				//処理を終了する。
				}
		else {
		//「これまでに試したパターンがそれぞれ何番目までか」は、cnt_nth_position_in_LinkedList配列に格納されている。
			delete_LinkedList_possible_relative_position(LinkedList_possible_position_combination, cnt_specialtown_already_existed);
			//まず、「置くと決めたリスト」の末尾を削除する。

			cnt_specialtown_already_existed--;
			//	このとき、「置くことを決めた専門街の数」を-1する。

			cnt_nth_position_in_LinkedList[num_of_specialtown_now_consider] += 1;

			if(nth_LinkedList_possible_point(LinkedList_possible_relative_position[num_of_specialtown_now_consider], cnt_nth_position_in_LinkedList[num_of_specialtown_now_consider]) == NULL) {//	もしその専門街のパターンの最後まで到達してしまっている場合、
				//		cnt_nth_position_in_LinkedList[現在の専門街番号]をリセットする。つまり、ゼロにする。
				//		専門街番号を+1して、次の専門街に移る。つまり、この専門街は置かないことにする。

				cnt_nth_position_in_LinkedList[num_of_specialtown_now_consider] = 0;

				//次に、cnt_nth_position_in_LinkedList[現在の専門街番号]を+1する。
				num_of_specialtown_now_consider += 1;

			}

			is_putting_concurrently(LinkedList_possible_relative_position, num_of_specialtown_now_consider, cnt_nth_position_in_LinkedList, LinkedList_possible_position_combination, cnt_specialtown_already_existed);
			//そしてまたこの関数を呼び出す。

		}
	}

	if (LinkedList_possible_position_combination->next_llprp = NULL) { // もしまだ何も置くことが決まってないなら
		
	/*	if(num_specialtown_now_consider != cnt_specialtown_regards_mainb) { // 最後の専門街まで達していない場合
			is_putting_concurrently(LinkedList_possible_relative_position, num_of_specialtown_now_consider + 1, cnt_nth_position_in_LinkedList, LinkedList_possible_position_combination, cnt_specialtown_already_existed); // 「今までのすべての専門街を置かないパターン」を試行
		}
*/
		
		insert_nth_LinkedList_possible_relative_position(LinkedList_possible_position_combination, nth_LinkedList_possible_relative_position(LinkedList_possible_relative_position[num_of_specialtown_now_consider], cnt_nth_position_in_LinkedList), 0); // 何番目の専門街かに関係なく、まだ試してないパターン（まだ最初に置いたことがないパターン）を「置くことを決めたリスト」に追加する。

		is_putting_concurrently(LinkedList_possible_relative_position, num_of_specialtown_now_consider + 1, cnt_nth_position_in_LinkedList, LinkedList_possible_position_combination, cnt_specialtown_already_existed + 1); // すでに置くことを決めた数を+1し、専門街番号も+1し、同じ関数を呼び出す。つまり、次の専門街へ移る。

	} // ここまで何も置くことが決まってない時の処理
	

	else { // すでに何か置くことが決まっているとき
		for(i=0; i<cnt_specialtown_already_existed; i++) {
			if(isable_putting_concurrently(nth_LinkedList_possible_relative_position(LinkedList_possible_relative_position[num_of_specialtown_now_consider], cnt_nth_position_in_LinkedList), nth_LinkedList_possible_relative_position(LinkedList_possible_position_combination, i)) == false) { //すでに置くことが決まっている専門街のうち一つとでも重なっていたら
				break; //置く処理を飛ばす
			}
			if (i == cnt_specialtown_already_existed - 1) { // 全てと重なっていなかったら、

				insert_nth_LinkedList_possible_relative_position(LinkedList_possible_position_combination, nth_LinkedList_possible_relative_position(LinkedList_possible_relative_position[num_of_specialtown_now_consider],cnt_nth_position_in_LinkedList), /*置く位置*/); // 「置くことを決めたリスト」に追加する。

				is_putting_concurrently(LinkedList_possible_relative_position, num_of_specialtown_now_consider + 1, cnt_nth_position_in_LinkedList, LinkedList_possible_position_combination, cnt_specialtown_already_existed + 1); //すでに置くことを決めた数を+1し、専門街番号も+1し、同じ関数を呼び出す。つまり、次の専門街へ移る。
			}
		}
	}


/*			is_putting_concurrently(LinkedList_possible_relative_position, num_of_specialtown_now_consider+

		insert_LinkedList_possible_relative_position(LinkedList_possible_position_combination,  置きたい配置, 0); */		
	// もし「これは組み合わせられます配列」のすべての要素と重複がなければ
	//
	// 「これは組み合わせられます配列」に入れて、次の専門街の置き方の先頭を呼び出す。
	//
	// あるいは、あえて置かずに次の専門街の置き方の先頭を呼び出す。
	//
	// もし重複があれば、この専門街の次の置き方を呼び出す。
	//
	// もし最後の専門街に到達したら、
	// 	それが最後の置き方でないなら、結果を評価して保持するか決める。
	// 	それが最後の置き方なら、結果を評価したあとまだ試してない専門街の置き方のところから始める。
	// 
	// もしn番目の専門街の候補全てと重複したら、n+1番目の専門外の候補の先頭に進む。
	// もし最後の専門街の¥候補全てと重複したら、結果を評価したあとまだ試してない専門街の置き方のところから始める。
	//
	// かつ、mainbの専有マスが(mainbの外周-1）になったら即終了する。




	
