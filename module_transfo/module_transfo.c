#include <stdio.h>
#include <stdlib.h>
#include "../module_mem/module_mem.h"
#include "module_transfo.h"
/*
tabs 			convert_tchar_into_tint(tabs t)
{
	int i;
	for (i = 0; i < taille_tableau; i++)
		tableau_trier[i] = (int)(tableau_entrer[i]);
	return t;
}*/

tabs 			trier(tabs t)
{
    int i, j, y;
	for(i=0; i<taille_sortie ;i++){
        for(j=i; j<taille_sortie ;j++)
        {
            if(tableau_sortie[i] < tableau_sortie[j] ){
            	y = tableau_sortie[i];
                tableau_sortie[i]= tableau_sortie[j];
                tableau_sortie[j]= y;
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

tabs codage(tabs t,const code D)
{
	int i=0,j=0,tts=0,x=0;
	code c;
	c = (code)malloc(sizeof(struct code_s));
	tableau_sortie = mem_remem_tabs(tableau_sortie,"char",0);
	while(i < 8*taille_tableau)
	{
		tableau_sortie[tts]=' ';
		c = D;
		j=0;
		while((j<c->sob)&&(tableau_sortie[tts]==' ')){
			if(tableau_binaire[i+j]==c->b[j]){
				x+=1;
				j++;
			}
			else{
				x=0;
				j=0;
				c=c->suivant;
				if(c==NULL){ return NULL;}
			}
			if(x==c->sob){
				tableau_sortie[tts]=c->c;				
				tts++;
				tableau_sortie= mem_remem_tabs(tableau_sortie,"char",tts+1);
				taille_sortie = tts;
				x=0;
				break;
			}
		}
		i= i+c->sob;
	}
	tableau_sortie[taille_sortie]='\0';

	return t;
}

void test_nonambigu( code c)
{
	code Q;
	Q = (code) malloc(sizeof(struct code_s));
	Q = c;
	code D;
	D = (code)malloc(sizeof(struct code_s));
	int i,j;
	D=c;
	Q=c;
	while(c->suivant!=NULL){ 
		++i;
		printf("%d\n",i );
		for (j = 0; j < i; ++j)
		{
			if ((D->sob)>(c->suivant->sob))
			{
				printf("%d\n",j);
				D = c->suivant;
			}
			c = c->suivant;		
		}
		D = D->suivant;
		c = Q;
	}
	c = Q;
	while(D!=NULL){
		printf("%d\n",D->sob);
		D= D->suivant;
	}
}