program = store_st_regards_mainb 
objs = main.o point.o building.o specialtown.o LinkedList_specialtown.o dictionary_building.o dictionary_specialtown.o

CC = gcc
CFLAGS = -g -Wall

.SUFFIXES: .c .o .h

$(program): $(objs)
	$(CC) -o $(program) $^

.c.o:
	$(CC) $(CFLAGS) -c $<

.h.o: 

.PHONY: clean

clean: 
	$(RM) $(program) $(objs)


