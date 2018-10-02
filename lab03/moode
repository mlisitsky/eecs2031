OBJS=main.o morsecode.o
LDFLAGS=-lwiringPi
CC=gcc
CFLAGS=-Wall -pedantic 

%.o:	%.c morsecode.h
	$(CC) $(CFLAGS) -c -ansi $<


main:	${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -o main $(LDFLAGS)
    


