#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "../module_mem/module_mem.h"
typedef void* dont_now_type;

dont_now_type mem_remem_tabs(void *tab, char *type, int size)
{	
	if(strcmp(type,"int")==0){
		if((size==0))
			tab = (int*)malloc(sizeof(int));
		else if(size!=0){
			int *t1;
			t1 = realloc(tab,size*sizeof(int));
			if(t1==NULL)
				free(tab);
			else
				tab= t1;
		}
	}
	else if(strcmp(type,"char")==0){
		if((size==0))
			tab = (char*)malloc(sizeof(char));
		else if(size!=0){
			char *t2;
			t2 = realloc(tab,size*sizeof(char));
			if(t2==NULL)
				free(tab);
			else
				tab= t2;		
		}
	}
	return tab;
}
tabs mem_taux(tabs t){
	tableau_int = (int*) malloc(taille_tableau*sizeof(int));
	tableau_binaire = (int*) malloc(8*taille_tableau*sizeof(int));
	return t;
}
