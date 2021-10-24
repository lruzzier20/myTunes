all: main.o list.o
	gcc -o fin main.o list.o

main.o: main.c list.h
	gcc -c main.c

foo.o: list.c list.h
	gcc -c list.c

run:
	./fin

clean:
	rm *.o
