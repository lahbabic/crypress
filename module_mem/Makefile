FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION 

module_mem.o: module_mem.c module_mem.h 
	gcc $(FLAGS) -c $^

test: test_module_mem.c module_mem.o 
	gcc $(FLAGS) -o test_module_mem $^
	./test_module_mem
install: module_mem.o module_mem.h
	cp -v module_mem.o ../lib
	cp -v module_mem.h ../include