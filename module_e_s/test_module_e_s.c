#include "module_e_s.h"
#include <stdio.h>
#include <stdlib.h>
#include "../module_mem/module_mem.h"
int main(int argc, char const *argv[])
{
	tabs t,f;
	printf("Veuillez saisir une entree\n");
	t=lire_entrer();
	//affichage(t);   // Ne peut pas etre utiliser car il n'y a pas de tableau sortie ni tableau binaire 
	f=lire_fichier("entree.txt");
	//affichage(f);
	code c;
	c=create_code("code.txt");
	affichec(c);
	write_in_file(t,"test_sortie.txt");
	write_in_file(f,"test_sortie.txt");
	return 0;
}