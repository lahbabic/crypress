
FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION 

module_huffman.o: module_huffman.c module_huffman.h 
	gcc $(FLAGS) -c $^

install:
	cp -v module_huffman.o ../lib
	cp -v module_huffman.h ../include