make_DB: main.o dictionary_building.o
	gcc -Wall -o make_DB dictionary_building.o main.o

main: main.c dictionary_building.h
	gcc -Wall -c -o main.o main.c

dictionary_building.o: dictionary_building.c dictionary_building.h
	gcc -Wall -c -o dictionary_building.o dictionary_building.c

clean: 
	rm main.o dictionary_building.o make_DB
