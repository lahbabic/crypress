#include <stdio.h>
#include <stdlib.h>
#include "../module_mem/module_mem.h"
#include <unistd.h>


tabs			lire_entrer()
{
	tabs t;
	t = (tabs) malloc(sizeof(struct tabs_s));
    taille_tableau=0;
    tableau_entrer = mem_remem_tabs(tableau_entrer,"char",taille_tableau);                      
    char c;
    while((c!='\n')&&(c!=EOF)){
  		c = getchar();
		tableau_entrer[taille_tableau]=c;
        taille_tableau++;
        tableau_entrer = mem_remem_tabs(tableau_entrer,"char",taille_tableau);                      

    }
    //taille_tableau -= 1;//enlever le dernier char qui est '\n' ou '\0'
    
    if(taille_tableau==1){
        free(t);
        return NULL;}
    else
        t = mem_taux(t);
    return t;
}

void      affichage(tabs t)
{
    int i, j;
    printf("\nNombre de caracteres lus : %d\n\n",taille_tableau );     
    printf("\n");
    for(i=0; i< (taille_tableau); i++){
        for(j=0; j< 8; j++)
            printf("'%d' " , tableau_binaire[j+8*i]);
    }
    printf("\n");
    for (i = 0; i < taille_sortie; ++i)
    {
        printf("%c", tableau_sortie[i] );
    }
    printf("\n");

}

tabs lire_fichier(const char *name)
{
    FILE *f;
    f = fopen(name,"r");
    if(f == NULL )
        return NULL;

    tabs t;
    t = (tabs) malloc(sizeof(struct tabs_s));
    char c;
    taille_tableau=0;

    while(1){
        tableau_entrer = mem_remem_tabs(tableau_entrer,"char",taille_tableau+1);                     
        c = fgetc(f);
        if(c<0){   // EOF
            tableau_entrer[taille_tableau]= '\0';
            break;
        }
        else    
            tableau_entrer[taille_tableau]=c;
        taille_tableau++;
    }
    fclose(f);
    t = mem_taux(t);
    //taille_tableau -= 1;
    return t;
}

int convert_tchar_int(char *t){
    int nb,n;
    int i=0;
    nb=(int)t[i]-48;
    n =nb;
    if((n<0)||(n>9))
            return '\0';
    i++; 
    for (i = 1; (t[i]!='\n'); ++i){
        n=(int)t[i]-48;
        if((n<0)||(n>9))
            return '\0';   
        nb= 10*nb+(n); 
    }
    return nb;    
}

code create_code(const char*name){
    FILE *fp;
    fp = fopen(name,"r");
    if(fp==NULL){
        printf("Impossible de trouver le fichier contenant le code.\n");
        return NULL;
    }
    
    code c,w;
    c = (code)malloc(sizeof(struct code_s));
    w = (code)malloc(sizeof(struct code_s));
    w=c;

    int static id =0;
    char t[5];
    int nb,nbc,i,j;
    fgets(t, 5, fp);
    nbc = convert_tchar_int(t);
    if(nbc=='\0'){printf("Erreur de syntaxe dans l'ecriture du code.\n");return NULL;}
    for(i=0; i<nbc ;i++){
        fgets(t, 5, fp);
        nb = convert_tchar_int(t);
        if(nb=='\0'){printf("Erreur de syntaxe dans l'ecriture du code.\n");return NULL;}        
        c->id = id;
        c->sob=nb;
        c->b= mem_remem_tabs(c->b,"int",0);
        c->b= mem_remem_tabs(c->b,"int",nb);
        fgets(t,5,fp);
        c->c=t[0];
        fgets(t,5,fp);
        for (j = 0; j < nb; ++j)
            c->b[j]=(int)t[j]-48;
        c->suivant=(code)malloc(sizeof(struct code_s));
        c=c->suivant;
        id++;
    }
    c->suivant=NULL;
    fclose(fp);
    return w;
}

void affichec(code c){
    int i;
    while(c!=NULL){
        printf("CARACTERE %c\n",c->c );
        for (i = 0; i < c->sob; ++i)
        {
            printf("%d\n",c->b[i] );
        }
        printf("\n");
        c=c->suivant;
    }
}

void write_in_file(tabs t,const char *name){
    FILE *f=NULL;
    f = fopen(name,"r+");  //ecriture en fin de fichier , fichier creer s il n existe pas
    if(f==NULL){
        printf("Fichier inexistant, creation du fichier %s.\n",name); 
        f = fopen(name,"a");  
    }
    printf("Ecriture dans le fichier ...\n");
    int i;
    for (i = 0; i< taille_sortie; ++i)
    {   
        fprintf(f, "%c",tableau_sortie[i]);
    }
    fclose(f);
    printf("Ecriture terminee.\n");
}