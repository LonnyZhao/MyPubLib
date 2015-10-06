CC=gcc
INCL=../../common

INCLS= -I $(INCL)
CFLAGS=-g -Wall
OBJS=dlist.o dlist_test.o locker.o locker_pthread.o rw_locker.o

test: $(OBJS)
	$(CC) $(CLFAGS) $(INCLS) -lpthread -o test $(OBJS)
.SUFFIXES:.c
.c.o:
	$(CC) -c $(CFLAGS) $(INCLS) -lpthread -o $@ $<

.PHONY: clean

clean:
	rm test $(OBJS)




