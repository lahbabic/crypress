//
//
//   ***   Projet d'info   ***
//By Dang Vincent-Nam && Lahbabi Chems Eddine
//
//

//  Include && Déclaration

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj_inf.h"

#define tableau_entrer t->te
#define tableau_trier t->tt
#define tableau_binaire t->tb
#define taille_tableau t->sot
//#define interger "%d"
//#define character "%c"
tabs mem_remem_tentrer(tabs t);
tabs mem_taux(tabs t);

struct codage
{
	char caractere;
	int* code;
	struct codage* suivant;
};

typedef struct codage *codage;

struct 			tabs_s
{
    int sot; // size of tabs
    char *te; //tabs entrée
    int *tt; //tabs trier
    int *tb; //tab binaire

};
/*tabs 			mem_remem_tentrer(tabs t){
	if(taille_tableau==0){
		taille_tableau = 0;
		tableau_entrer = (char*)malloc(sizeof(char));
	}
	else if(taille_tableau!=0){
		char *t1;
		t1 = realloc(tableau_entrer, taille_tableau*sizeof(int));
		tableau_entrer = t1;
	}
return t;
}

tabs mem_taux(tabs t){
	tableau_trier = (int*) malloc(taille_tableau*sizeof(int));
	tableau_binaire = (int*) malloc(8*taille_tableau*sizeof(int));
	return t;
}*/


//PROGRAMME
/*tabs			lire_entrer()
{
	tabs t;
	t = (tabs) malloc(sizeof(struct tabs_s));
	t = mem_remem_tentrer(t); 				  		
    char c;
    while((c!='\n')&&(c!=EOF)){
		t = mem_remem_tentrer(t); 				  		
  		c = getchar();
		tableau_entrer[taille_tableau]=c;
      	taille_tableau++;
    }
    tableau_entrer[taille_tableau-1] = '\0';
    t = mem_taux(t);
    taille_tableau -= 1;//enlever le dernier char qui est '\n' ou '\0'
    return t;
}*/
//PROGRAMME
tabs 			convert_tchar_into_tint(tabs t)
{
	int i;
	for (i = 0; i < taille_tableau; i++)
		tableau_trier[i] = (int)(tableau_entrer[i]);
	return t;
}

tabs 			trier(tabs t)
{
    int i, j, y;
	for(i=0; i<taille_tableau ;i++){
        for(j=i; j<taille_tableau ;j++)
        {
            if(tableau_trier[i] < tableau_trier[j] ){
            	y = tableau_trier[i];
                tableau_trier[i]= tableau_trier[j];
                tableau_trier[j]= y;
            }
        }
    }
    return t;
}
//PROGRAMME
tabs binaire(tabs t){
	int i,j,vb,v;
	for (j = 0; j < taille_tableau; j++){
		v=(int)tableau_entrer[j];
		vb=128;
		for(i=0; i<8; i++){
			
			if (vb>v)
			{
				tableau_binaire[i+(j*8)]=0;
			}
			if (vb<=v){
				tableau_binaire[i+(j*8)]=1;
				v=v-vb;	
			}
			vb=vb/2;
		}
	}
	return t;
}
//PROGRAMME
void 			affichage(tabs t)
{
	int i, j;
    printf("\nsize of tabs :%d\n\n",taille_tableau );
    for(i=0; i< (taille_tableau); i++)
    	printf("%d ", tableau_trier[i]);
    printf("\n");
    for(i=0; i< (taille_tableau); i++){
    	printf("%c: ", tableau_entrer[i]);
    	for(j=0; j< 8; j++)
    		printf("%d" , tableau_binaire[j]);
    	printf("     ");
    }
    printf("\n");
}

//tabs trier_taille(tabs t){
	/*
	soit list Ltriée,L ={	char caractère;
							int* code;
							list suivant;
							}
	prendre L.code[i]
	vérifier si L.code[i] est plus petit que tout les autres codes
	placer L.code[i] tel que taille(L.code[i-1])>taille(L.code[i])
							 taille(L.code[i+1])<taille(L.code[i])

	*/
//}

//tableau_code : tableau contenant les codes des caractères
//tableau_char : tableau contenant les caractères associés à un code
//int non_ambigue (tabs t){
	/*
	trier les codes (et le caractère associé) dans l'autre croissant des tailles de codes
	prendre 2 codes
	vérifier si un est préfixe de l'autre
		si un est préfixe de l'autre
			return FALSE
	continuer pour tous les codes de tableau_code
	si aucun code n'est préfixe d'un autre
		return le code est non ambigue
	sinon
		return le code est ambigue
	*/
/*	for (int j = 0; j < count; j++)
	{
		 code 
	

	for (int i = 0; i < count; ++i)
	{
		y=tableau_code[j]
		x=tableau_code[i]

	
	
	}
	}
	if (y==x)
	{
		return FALSE;
	}

}
*/
/*tabs			nouveau_tabs()
{
	tabs t;
	t = (tabs) malloc(sizeof(struct tabs_s));
    tableau_entrer=(char*)malloc(sizeof(char));
    return t;
}

void 			allocation_de_mem(tabs t)
{
	char *t1;
	if( taille_tableau!= 0)
		t1 = realloc(tableau_entrer, taille_tableau*sizeof(char) );
	tableau_entrer = t1;	
}*/
/*tabs 			lire_fichier(const char *name)
{
	FILE *f;
	tabs t;
	t = nouveau_tabs();
    taille_tableau = 0;
    char c;
	f = fopen(name,"r");
	if(f == NULL )
	{
		printf( "Erreur lors de l'ouverture du fichier %s\n", name ) ;
		return NULL;
	}
    while(c!=EOF){
  		c = fgetc(f);
		tableau_entrer[taille_tableau]=c;
      	taille_tableau++;
		allocation_de_mem(t); 				
    }
    taille_tableau -= 1;//enlever le dernier char qui est '\n' ou '\0'
	fclose(f);
	return t;
}*/

//test
/*int main()
{
    int  i;
    tabs t;
    t = (tabs) malloc(sizeof(struct tabs_s));
    tableau_entrer=(char*)malloc(sizeof(char));
    taille_tableau = 0;
    lire_entrer(t);
    trier(t);

    for(i=0; i< (taille_tableau); i++)
    	printf("%c", tableau_entrer[i]);
    printf("\n");
    for(i=0; i< (taille_tableau); i++)
    	printf("%d:= %c \n", i ,tableau_trier[i]  );

    printf("\nsize of tabs :%lu\n",strlen(tableau_entrer) );
    printf("%d\n",taille_tableau );



    return 0;
}



int** transfo(char c,int x,int* t){
	int a,i,n;
	a=c;
	n=255;
	for (i=x;i<x+8;i++){
		if (a>=n){
			t[i]=1;
			a=a-n;}
		else t[i]=0;
		n=n/2;
	}
	for (i = 0; i < 8; ++i)
	{
		printf("%d", t[i]);
	}
	return *t;
}

int** transfot(char* C, int taillet){
	int* t, *y;
	int i,j;
	y=malloc(8*sizeof(int));
	for (i = 0; i < taillet; ++i){
		y=transfo(t[i],taillet/i,t);
		for (j = 0; j < 8; ++j){
			t[i*taillet]=y[j];
		}
	}
	return *t;
	
}*/


/*int maxI(int n, int m){
	if( n<m ) return m;
	else return n;
}

int trierC(int* t, int taillet){
	int i, y, j, k, w;
	for (i=0; i<taillet-1; i++);{
		for(j=i+1; j<taillet; j++);{
			y=maxI(t[i], t[j]);
			if (t[i]<t[j])
				k=j;

			}	
	w=t[i];
	t[i]=y;
	t[k]=w;	
	}
	return  *t;
}*/

//{
	/* code */
//}
/*
struct node
{
  int value;
  int frecency;
  struct node *left;
  struct node *right;
};



void insert(int n , struct **tree)
{
	if (n == 
	{
		/
	}

};
*/
//
//{	
	//# Définition
	
//	struct node *tree = 0;
//	tree = (struct node*) malloc( sizeof( struct node ) );
//	printf("value:%d\n left:%p\n right:%p\n",(*tree).value,tree->left,tree->right );
	
	//# Lire entrée

	//# Transfo en binaire

	//# Crypter

	//# Affichage

	//         HUFFMAN

	//#$ trier
//	trier(*t)

	//#$ création de l'arbre   

	//#$ déduire le codage
	
	//# Recodage

	//#$ affichage



	//Tests
/*	int *t;
	int i,j,k,y, w,taillet;
	taillet=5;
	t=malloc(taillet*sizeof(int));
	t[0]=4;
	t[1]=14;
	t[2]=1;
	t[3]=1;
	t[4]=2;
	for (i=0; i<taillet-1; i++);{
		for(j=i+1; j<taillet; j++);{
			y=maxI(t[i], t[j]);
			if (t[i]<t[j])
				k=j;

			}	
	w=t[i];
	t[i]=y;
	t[k]=w;	
	}
	for(i=0;i<5;i++)
		printf("%d\n",t[i] ); */



/*char* C;
C=malloc(2*sizeof(char));
int* t;
t=malloc(16*sizeof(int));
int i;
C[0]='a';
C[1]='b';
*t=transfot(C,2);
for (i = 0; i < 16; ++i)
{
	printf("%d",t[i] );
}*/
//return 0;
//}