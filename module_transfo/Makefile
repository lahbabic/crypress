
mem=../module_mem
FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION -I $(mem)

module_transfo.o: module_transfo.c module_transfo.h $(mem)/module_mem.h 
	gcc $(FLAGS) -c $^

install:
	cp -v module_transfo.o ../lib
	cp -v module_transfo.h ../include