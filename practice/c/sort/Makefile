CC=gcc
INCL=../common

INCLS= -I $(INCL)
CFLAGS=-g -Wall
OBJS=sort.o sort_comm.o test_sort.o

test: $(OBJS)
	$(CC) $(CLFAGS) $(INCLS) -o test $(OBJS)
test_sort.o:test_sort.c
sort_comm.o: sort_comm.h
sort.o: sort.h
.SUFFIXES:.c
.c.o:
	$(CC) -c $(CFLAGS) $(INCLS) -o $@ $<

.PHONY: clean

clean:
	rm test $(OBJS)




