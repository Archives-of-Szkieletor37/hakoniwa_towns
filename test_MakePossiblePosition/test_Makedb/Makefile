make_DB: main.o point.o building.o dictionary_building.o
	gcc -Wall -o make_DB point.o building.o dictionary_building.o main.o

main: main.c dictionary_building.h
	gcc -Wall -c -o main.o main.c

dictionary_building.o: dictionary_building.c dictionary_building.h
	gcc -Wall -c -o dictionary_building.o dictionary_building.c

building.o: building.c building.h
	gcc -Wall -c -o building.o building.c

point.o: point.c point.h
	gcc -Wall -c -o point.o point.c
clean: 
	rm main.o building.o point.o dictionary_building.o make_DB
