#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

int main() {

	char a[100] = "漢字";
	char b[100];
	wchar_t d[100] = L"漢字";
	wchar_t c[100] = {0};
//	mbstowcs(c, a, sizeof(a));
	//wcscpy(b,c);

//	setlocale(LC_ALL, "");
	strcpy(b,a);
	printf("%s\n", b);
	printf("%ls\n", c);

	return 0;

}
