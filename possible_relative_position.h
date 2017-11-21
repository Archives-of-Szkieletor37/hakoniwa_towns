// possible_relative_position.h
//

#ifndef _POSSIBLE_RELATIVE_POSITION_H_
#define _POSSIBLE_RELATIVE_POSITION_H_

#include <stdio.h>
#include "specialtown.h"
#include "point.h"

typedef struct {

	SpecialTown *specialtown;
	Point *point_e1;
	Point *point_e2;
	int cnt_dominated_mainbs_adjacent_square;

} Possible_Relative_Position;

extern Possible_Relative_Position *make_possible_relative_position(SpecialTown *specialtown, Point *point_e1, Point *point_e2, int cnt_dominated_mainbs_adjacent_square);
//これは連接リストの空ヘッダのを作るための関数
extern void free_possible_relative_position(Possible_Relative_Position *prp);

#endif // _POSSIBLE_RELATIVE_POSITION_H_
