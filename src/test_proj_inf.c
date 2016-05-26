#include "proj_inf.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    tabs t;
    t = (tabs) malloc(sizeof(tabs));
    //char *te;
    printf("argv :=%d\n",argc );
    //if (argc == 1) 
    t = lire_entrer();
    //else if(argc == 2)
       	//t = lire_fichier(argv[1]);
    t = convert_tchar_into_tint(t);
    t = trier(t);
    t = binaire(t);
    affichage(t);
    return 0;
}