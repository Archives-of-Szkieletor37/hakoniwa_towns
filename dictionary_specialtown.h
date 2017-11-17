// dictionary_specialtown.h


typedef struct {
		
		char DS_name[20];
		char trio_building_compose_specialtown[3][20] // {index, 要素A,要素B}
		double landprice_bonus_rate;

} Dictionary_SpecialTown;

extern Dictionary_SpecialTown dictionary_specialtown[150];
