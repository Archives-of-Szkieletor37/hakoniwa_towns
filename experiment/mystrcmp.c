#include <stdio.h>


int mystrcmp(char* s1, char* s2) {

	int i = 0;

	while(((s1[i]='\0') && (s2[i]!='\0')) || ((s1[i] != '\0') && (s2[i] = '\0'))) {
		if (s1[i] != s2[i]) {
			break;
		}
		else {
			if (s1[i] == '\0' && s2[i] == '\0') {
				return 0;
			}
			i++;
		}

	}
		return -1;
}


int main() {

	if(mystrcmp("農家", "農家") == 0) {

		printf("よさげ");
	}

	if(mystrcmp("農家", "農家人") != 0) {

		printf("よさそう");

	}

	return 0;

}

