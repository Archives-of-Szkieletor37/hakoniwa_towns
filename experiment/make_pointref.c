#include <stdio.h>

int main() {

	int i;

	printf("{");

	for(i=0; i<150; i++) {
		printf("%d ,", i-74);
	}

	printf("}");

	return 0;

}

