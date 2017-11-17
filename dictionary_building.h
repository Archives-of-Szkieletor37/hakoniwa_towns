
typedef struct  {
						
	char DB_name[100];
	int owned_landprice; // それ自体が上昇させる地価
	int affected_landprice;// 周囲に影響する地価
	int DB_length;
	int DB_width;

} Dictionary_Building;

extern Dictionary_Building dictionary_building[200];
