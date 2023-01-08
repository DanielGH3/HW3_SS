all: txtfind isort


txtfind: txtfind/txtfind.a txtfind/main.c 
	gcc -Wall txtfind/main.c txtfind/txtfind.a -o txtfind

txtfind/txtfind.a: txtfind/txtfind.o
	ar -rc txtfind/txtfind.a txtfind/txtfind.o

txtfind/txtfind.o: txtfind/txtfind.c
	gcc -Wall -c txtfind/txtfind.c -o txtfind/txtfind.o


isort: isort/isort.a isort/main.c 
	gcc -Wall isort/main.c isort/isort.a -o isort

isort/isort.a: isort/isort.o
	ar -rc isort/isort.a isort/isort.o

isort/isort.o: isort/isort.c
	gcc -Wall -c isort/isort.c -o isort/isort.o

clean:
	rm -f *.o *.a txtfind isort