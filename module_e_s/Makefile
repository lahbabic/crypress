
mem=../module_mem
FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION 

module_e_s.o: module_e_s.c module_e_s.h $(mem)/module_mem.h 
	gcc $(FLAGS) -c $^

test: test_module_e_s.c module_e_s.o 
	gcc $(FLAGS) -o test_module_e_s $< $(mem)/module_mem.o module_e_s.o
	./test_module_e_s
install: module_e_s.o module_e_s.h
	cp -v module_e_s.o ../lib
	cp -v module_e_s.h ../include