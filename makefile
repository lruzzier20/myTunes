all: main.o list.o library.o
	gcc -o fin main.o list.o library.o

main.o: main.c list.h
	gcc -c main.c

list.o: list.c list.h library.h
	gcc -c list.c

library.o: library.c library.h
	gcc -c library.c

run:
	./fin

clean:
	rm *.o
