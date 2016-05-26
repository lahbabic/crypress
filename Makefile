all : module_e_s module_mem module_transfo module_huffman

FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION -o
lib= lib/module_mem.o lib/module_transfo.o lib/module_e_s.o lib/module_huffman.o
DEP= module_e_s module_mem module_transfo module_huffman

compile_module:
	./compile
	
compile: test_module.c $(DEP) $(lib) module_e_s
	gcc $(FLAGS) test_module $< $(lib) -I lib 
exec:
	./test_module 

