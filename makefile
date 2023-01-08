all: txtfinddir isortdir


txtfinddir: txtfinddir/txtfinddir.a txtfinddir/main.c 
	gcc -Wall txtfinddir/main.c txtfinddir/txtfinddir.a -o txtfinddir

txtfinddir/txtfinddirdir.a: txtfinddir/txtfinddir.o
	ar -rc txtfinddir/txtfinddir.a txtfinddir/txtfinddir.o

txtfinddir/txtfinddir.o: txtfinddir/txtfinddir.c
	gcc -Wall -c txtfinddir/txtfinddir.c -o txtfinddir/txtfinddir.o


isortdir: isortdir/isortdir.a isortdir/main.c 
	gcc -Wall isortdir/main.c isortdir/isortdir.a -o isortdir

isortdir/isortdir.a: isortdir/isortdir.o
	ar -rc isortdir/isortdir.a isortdir/isortdir.o

isortdir/isortdir.o: isortdir/isortdir.c
	gcc -Wall -c isortdir/isortdir.c -o isortdir/isortdir.o

clean:
	rm -f *.o *.a txtfind isort