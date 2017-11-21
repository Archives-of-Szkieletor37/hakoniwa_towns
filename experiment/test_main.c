#include <stdio.h>
#include "test.h"
#include <string.h>
#include <stdlib.h>

int x = 0;

typedef struct{

	int *x;
} X;

typedef struct piyoo{

	X *piyo;
	struct piyoo *next_piyo;
} PIYO;


PIYO *make_piyo() {

	PIYO *piyopiyo;
	piyopiyo = malloc(sizeof(PIYO));
	piyopiyo->piyo = malloc(sizeof(X));
	
	piyopiyo->piyo->x = &x; 
	piyopiyo->next_piyo = NULL;
		
	return piyopiyo;

}

void delete_piyo(PIYO *piyopiyo) {
	
	free(piyopiyo->piyo);
	free(piyopiyo);
}

int main() {

	
	PIYO *piyopiyo = make_piyo();	
	
	printf("piyo %d\n", *(piyopiyo->piyo->x));
	
//	delete_piyo(piyopiyo);

	free(piyopiyo->piyo);

	int y = 3;

	piyopiyo->piyo->x = &y;

	printf("3 %d\n", *(piyopiyo->piyo->x));

	free(piyopiyo);

	return 0;


}
