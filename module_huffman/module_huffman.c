#include <stdio.h>
#include <stdlib.h>
#include "../module_mem/module_mem.h"
#include "module_huffman.h"
#include "../module_transfo/module_transfo.h"



code creationA(tabs t){
	int i, j=0,k,v,h,y,x=0,w;
	char q;
	char* Cf=0;
	int* Ff=0;
					//TRIE + RECUPERATION DES FREQUENCES
	Cf=mem_remem_tabs(Cf, "char", 0);
	Ff=mem_remem_tabs(Ff,"int",0);
	t=trier(t);
	Ff[0]=0;
		for(i=0; i<taille_sortie;i++){
			for(k=0; k<j ;k++){
				if(Cf[k]==tableau_sortie[i])
					x=1;
					w=k;
			}
			if(x==1)
				Ff[w]+=1;
			else{
				Cf=mem_remem_tabs(Cf, "char", j+1);
				Ff=mem_remem_tabs(Ff,"int",j+1);
				Cf[j]=tableau_sortie[i];
				Ff[j]=1;
				j+=1;
			}
			
			x=0;
		}


	for(i=0; i<j ;i++){
        for(k=i; k<j ;k++)
        {
            if(Ff[i] < Ff[k]){
            	y = Ff[k];
            	q = Cf[k];
                Cf[k]= Cf[i];
                Cf[i]= q;
                Ff[k]= Ff[i];
                Ff[i]= y;
            }
        }
    }

	code c,s;
	c=(code)malloc(sizeof(struct code_s));
	s=(code)malloc(sizeof(struct code_s));
	c=s;
	s=c;
	for(i=0; i<j; i++){
		c->c=Cf[i];
		c->suivant=(code)malloc(sizeof(struct code_s));
		c=c->suivant;
	}
	c->suivant=NULL;
	c=s;
	i=0;
	k=0;
	if(j==2){
		c->b=(int*)malloc(sizeof(int));
		c->sob=1;
		c->suivant->b=(int*)malloc(sizeof(int));
		c->suivant->sob=1;
		c->b[0]=0;
		c->suivant->b[0]=1;
		c->c=Cf[0];
		c->suivant->c=Cf[1];
		//printf("%c\n",s->c );
		
		//printf("%c\n",s->suivant->c );
		//printf("%d\n",s->b[0] );
		//printf("%d\n",s->suivant->b[0] );
		return s;

	}
	while(k<(j-2))
	{
		
		c->b=(int*)malloc((2+i)*sizeof(int));
		c->sob=2+i;
		c->suivant->b=(int*)malloc((2+i)*sizeof(int));
		c->suivant->sob=2+i;
		//printf("%d\n",2+i );
		k=k+2;
		i+=1;
		c=c->suivant->suivant;
	}
	i-=i;
	c->suivant->b=(int*)malloc((2+i)*sizeof(int));
	c->b=(int*)malloc((2+i)*sizeof(int));
	c->suivant->suivant=NULL;
	c->suivant->sob=2+i;
	c->sob=2+i;
	c=s;
	h=1;
	for ( v = 0; v < j; v++)
	{
		if(v>2){
			h=h+1;
			c->b[v-h]=1;
			c->suivant->b[v-h]=1;}	
		if((j-v)%2==1){
			c->b[h-1]=1;
			c->b[h]=1;
			c->suivant->b[h-1]=1;
			c->suivant->b[h]=0;
		}
		else{
		c->b[h-1]=0;
		c->b[h]=0;
		c->suivant->b[h-1]=0;
		c->suivant->b[h]=1;
		}
		if(c->suivant->suivant!=NULL)
			c=c->suivant->suivant;
		else
			break;
	}
	
	return s;
}


tabs codageH(tabs t,const code D){
	int i,j,k=0;
	code c;
	c = (code)malloc(sizeof(struct code_s));
	tableau_sortieH = mem_remem_tabs(tableau_sortieH,"int",0);
	for (i = 0; i < taille_sortie; i++)
	{
		while(c!=NULL)
			if (tableau_sortie[i]==c->c)
			{
				for (j = 0; j <t->sotsh ; j++)
				{
					tableau_sortieH = mem_remem_tabs(tableau_sortieH,"int",k+1);
					tableau_sortieH[k]=c->b[j];
					k++;
				}
			}
			c=c->suivant;
	}
	return t;
}

/*
tabs codageH(tabs t,const code D)
{
	int i=0,j=0,tts=0,x=0;
	code c;
	c = (code)malloc(sizeof(struct code_s));
	tableau_sortieH = mem_remem_tabs(tableau_sortieH,"int",0);
	while(i < 8*taille_tableau)
	{
		tableau_sortieH[tts]=' ';
		c = D;
		j=0;
		while((j<c->sob)&&(tableau_sortieH[tts]==' ')){
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
				tableau_sortieH[tts]=c->c;				
				tts++;
				tableau_sortieH= mem_remem_tabs(tableau_sortieH,"int",tts+1);
				taille_sortie = tts;
				x=0;
				break;
			}
		}
		i= i+c->sob;
	}
	tableau_sortieH[taille_sortieH]='\0';

	return t;
}

tabs codageH(tabs t,const code D){
	int i=0,j=0,tts=0,x=0;
	code c;
	c = (code)malloc(sizeof(struct code_s));
	tableau_sortieH = mem_remem_tabs(tableau_sortieH,"int",0);
	for (i = 0; i < taille_sortie; i++)
	{
		
	}
}*/