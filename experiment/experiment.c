#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int x;
	int y;
} Point;

Point *yakusuu(int x) {

	int i;
	int cnt = 0;

	for(i=1; i<=x; i++) {
		if (x%i == 0){
			cnt++;
		}
	}

	Point *point = malloc(sizeof(Point) * cnt);

	cnt = 0;

	for(i=1; i<=x; i++) {
		if (x%i == 0) {
			point[cnt].x = x;
			point[cnt].y = i;
			cnt++;
		}
	}

	return point;
}

int main() {
	int i;
	Point *point = yakusuu(8);

	for(i=0; i<4; i++) {
		printf("%d %d\n", point[i].x, point[i].y);
	}

	return 0;

}
		
