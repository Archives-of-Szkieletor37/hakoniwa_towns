#include <stdio.h>
#include "eval_result_of_combination.h"
#include "LL_version_possible_relative_position.h"

LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *LinkedList_position_best_16_combination;

int sum_of_lpbonus(LinkedList_Possible_Relative_Position *LinkedList_possible_position_combination) {
	
	int sum_of_landprice_bonus_rate = 0;
	while(LinkedList_possible_position_combination == NULL) {

		sum_of_landprice_bonus_rate += ((LinkedList_possible_position_combination->prp)->DS_specialtown->)landprice_bonus_rate;
		LinkedList_possible_position_combination = LinkedList_possible_position_combination->next_llprp;

	}

	return sum_of_landprice_bonus_rate;

}


void eval_result_of_combination(LinkedList_Possible_Relative_Position *LinkedList_target_position_combination) {

	// 処理を書く
	int i = 0;

	int sum_of_landprice_bonus_of_target_combination = sum_of_lpbonus(LinkedList_target_position_combination);

	while(1) {
	
		if (i == 16) {
			break;
		}
	
	if(nth_LinkedList_pair_of_position_combination_and_sum_bonus_rate(LinkedList_position_best_16_combination, i) != NULL) {

		if(sum_of_landprice_bonus_of_target_combination > (nth_LinkedList_pair_of_position_combination_and_sum_bonus_rate(LinkedList_position_best_16_combination, i))->sum_of_landprice_bonus_rate) {
			insert_nth_LinkedList_pair_of_position_combination_and_sum_bonus_rate(LinkedList_position_best_16_combination, LinkedList_target_position_combination, i);
			delete_nth_LinkedList_pair_of_position_combination_and_sum_bonus_rate(LinkedList_position_best_16_combination, 16);	
			break;
		}
		else {
			i++;
		}
	}
}

	// 専門街ボーナスの合計が高い順にソートされた組み合わせを格納する連想配列をサイズ16で確保して、グローバルに参照可能にする。
	// 前から順番に比べていって、どこかで既存のものより大きくなっていればそこにinsertし、最後の要素をdeleteする。
	//



LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *make_LinkedList_pair_of_position_combination_and_sum_bonus_rate(void) {

	LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *llppcsr = malloc(sizeof(LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate));
	
	*(llppcsr->sum_of_landprice_bonus_rate) = malloc(sizeof(int));

	llppcsr->next_llppcsr == NULL;
	llppcsr->sum_of_landprice_bonus_rate == &zero;

	return llppcsr;
}

void delete_LinkedList_pair_of_position_combination_and_sum_bonus_rate(LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *llppcsr) {

	LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *temp;

	// while(llppcsr->next_llppcsr != NULL) {
	
	while(llppcsr != NULL) {
		temp = llppcsr->next_llppcsr;
		free(llppcsr->sum_of_landprice_bonus_rate);
		free(llppcsr);
		llppcsr = temp;`
	}

}


extern LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *nth_LinkedList_pair_of_position_combination_and_sum_bonus_rate(LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *llppcsr, int n) {

	int cnt = -1;

	while (cnt < n) {
		if(llppcsr->next_llppcsr == NULL) {
			return NULL;
		}
		else {
			llppcsr = llppcsr->next_llppcsr;
			cnt++;
		}
	}

	return llppcsr;

}

extern int insert_nth_LinkedList_pair_of_position_combination_and_sum_bonus_rate(LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *llppcsr, LinkedList_Possible_Relative_Position *llprp, int n) {

	LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *front_llppcsr = nth_LinkedList_pair_of_position_combination_and_sum_bonus_rate(llppcsr, n-1);

	if (front_llppcsr == NULL) {
		return 0;
	}

	LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *insert_target_llppcsr = make_LinkedList_pair_of_position_combination_and_sum_bonus_rate();

	if(insert_target_llppcsr == NULL) {
		return 0;
	}

	insert_target_llppcsr->next_llppcsr = front_llppcsr->next_llppcsr;
	front_llppcsr->next_llppcsr = insert_target_llppcsr;

	insert_target_llppcsr->LinkedList_position_best_combination = llprp;// 引数のものを入れた
	int sum_of_landprice_bonus_rate = sum_of_landprice_bonus_of_target_combination(llprp); 
	insert_target_llppcsr->sum_of_landprice_bonus_rate = &sum_of_landprice_bonus_rate; 

	return 1;
}

int delete_nth_LinkedList_pair_of_position_combination_and_sum_bonus_rate(LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *llppcsr, int n) {

	LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *front_llppcsr = nth_LinkedList_pair_of_position_combination_and_sum_bonus_rate(llppcsr, n-1);
	if (front_llppcsr == NULL || front_llppcsr->next_llppcsr == NULL) {
		return 0;
	}
	else {
		LinkedList_Pair_of_Position_Combination_and_Sum_Bonus_Rate *temp = front_llppcsr->next_llppcsr;
		front_llppcsr->next_llppcsr = front_llppcsr->next_llppcsr->next_llppcsr;
		free(temp);

		return 1;
	}
}

