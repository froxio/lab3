CC = gcc
CFLAGS = -g -O1 -Wall

arrayList: arrayList.o main.o\

arrayList.o: arrayList.c arrayList.h\

main.o: main.c

clean:
	rm -f *.o