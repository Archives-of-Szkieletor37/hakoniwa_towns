#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *x;
} hoge;

/*hoge *hogehoge(int x) {

	hoge *piyo;
	*(piyo->x) = x;
	return piyo;
}
*/
int main() {

	hoge piyo, *fuga = malloc(sizeof(hoge));
	piyo.x = NULL;
	fuga = &piyo;
	*(fuga->x) = 3;
	printf("%d\n", *(piyo.x));

/*	fuga->(*x) = 3;
	printf("%d\n", fuga->(*x));
*/	return 0;

}


