all: txtfind isort


txtfind: txtfinddir/txtfind.a txtfinddir/main.c 
	gcc -Wall txtfinddir/main.c txtfinddir/txtfind.a -o txtfind

txtfinddir/txtfinddir.a: txtfinddir/txtfind.o
	ar -rc txtfinddir/txtfind.a txtfinddir/txtfind.o

txtfinddir/txtfinddir.o: txtfinddir/txtfind.c
	gcc -Wall -c txtfinddir/txtfind.c -o txtfinddir/txtfind.o


isort: isortdir/isort.a isortdir/main.c 
	gcc -Wall isortdir/main.c isortdir/isort.a -o isort

isortdir/isortdir.a: isortdir/isort.o
	ar -rc isortdir/isort.a isortdir/isort.o

isortdir/isortdir.o: isortdir/isort.c
	gcc -Wall -c isortdir/isort.c -o isortdir/isort.o

clean:
	rm -f *.o *.a txtfind isort
