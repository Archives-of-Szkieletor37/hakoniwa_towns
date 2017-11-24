program = make_possible_relative_position 
objs = main.o point.o building.o specialtown.o LinkedList_possible_point.o possible_relative_position.o LinkedList_possible_relative_position.o LinkedList_specialtown.o dictionary_building.o dictionary_specialtown.o print_prp.o

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


