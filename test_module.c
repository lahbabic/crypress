#include <stdio.h>
#include <stdlib.h>
#include "module_e_s/module_e_s.h"
#include "module_transfo/module_transfo.h"
#include "module_huffman/module_huffman.h"
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char car, car1;
    char *s;
    s = (char*)malloc(50*sizeof(char));
    tabs t;
    code c,ch;
 
    c=(code) malloc(sizeof(code));
    ch=(code) malloc(sizeof(code));
    t = (tabs) malloc(sizeof(tabs));
 
    printf("Veuillez choisir votre entree fichier/console (f/c):\n");
    car=getchar();getchar();//Pour le \n
    if(car=='c'){
        pas_entree:{}
        printf("Saisissez votre entree:\n");
        t = lire_entrer();   
        if (t==NULL)
        {
            printf("Vous n'avez pas rentre de caractere.\n");
            printf("\n");
            goto pas_entree;
        }
    }
    else if(car=='f'){
        printf("Entrez le nom du fichier :");
        scanf("%s",s);getchar();
        t = lire_fichier(s);
        if(t==NULL){
            printf("Erreur de lecture : fichier inexistant.\n");
            return 0;
        }
    }
    //t = convert_tchar_into_tint(t);
    t = binaire(t);
    printf("Voulez-vous choisir un code? (y/n)\n");
    car=getchar();getchar();

    if(car=='y'){
        printf("Entrez le nom du fichier contenant le code:\n");
        scanf("%s",s);getchar();
        c = create_code(s);
    }
    else if(car=='n'){
        c= create_code("code.txt");
    }
    if(c==NULL)
        return 0;
    t = codage(t,c);

    if(t==NULL){
        printf("Erreur de codage : L'entree n'a pas pu etre codee entierement.\n");
        return 0;
    }
    printf("Voulez-vous que la sortie soit dans un fichier 'f' ou afficher a l'ecran 'e' ou les deux 'fe'?\n");
    car=getchar();car1=getchar();
    if(car1=='\n'){
        if(car=='f'){
            printf("Le nom du fichier de sortie?\n");
            scanf("%s",s);
            printf("\nOuverture du fichier %s ...  \n",s);
            write_in_file(t,s);
        }
        else if(car=='e')
            affichage(t);
    }
    else if((car=='f')&&(car1=='e')){
        getchar();
        printf("Le nom du fichier de sortie?\n");
        scanf("%s",s);
        printf("\nOuverture du fichier %s ...  \n",s);
        write_in_file(t,s);
        affichage(t);
    }
    ch=creationA(t);
    printf("Voulez vous afficher le code de huffman? (y/n)\n");
    car=getchar();getchar();
    if(car=='y'){
       affichec(ch);
    }
    //t = codageH(t,ch);
    return 0;
}