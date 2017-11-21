main: main.o point.o
	gcc -Wall -g -o main main.o point.o

main.o: main.c point.h
	gcc -Wall -g -c -o main.c

point.o: point.c point.h
	gcc -Wall -g -c -o point.c
