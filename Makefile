compile: mymalloc.h mymalloc.c memgrind.c
	gcc mymalloc.c memgrind.c -o memgrind.o

compile_crashtests: mymalloc.h mymalloc.c memgrind.c
	gcc mymalloc.c crashtest1.c -o crashtest1.o
	gcc mymalloc.c crashtest2.c -o crashtest2.o
	gcc mymalloc.c crashtest3.c -o crashtest3.o
	gcc mymalloc.c crashtest4.c -o crashtest4.o

submit: mymalloc.h mymalloc.c memgrind.c Makefile
	tar -cvzf proj1.tar mymalloc.h mymalloc.c memgrind.c crashtest1.c crashtest2.c  crashtest3.c  crashtest4.c Makefile README.txt

clean:
	rm *.o