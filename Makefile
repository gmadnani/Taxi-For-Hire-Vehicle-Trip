dict1: dict1.o bst.o bst1.o
	gcc -Wall -o dict1 dict1.o bst.o bst1.o -g

dict1.o: dict1.c bst.h bst1.h structure.h
	gcc -Wall dict1.c -c -g -o dict1.o

bst.o: bst.c bst.h bst1.h bst2.h structure.h
	gcc -Wall bst.c -c -g -o bst.o

bst1.o: bst1.c bst1.h bst.h structure.h
	gcc -Wall bst1.c -c -g -o bst1.o

dict2: dict2.o bst.o bst2.o
	gcc -Wall -o dict2 dict2.o bst.o bst2.o -g

dict2.o: dict2.c bst.h bst2.h structure.h
	gcc -Wall dict2.c -c -g -o dict2.o
