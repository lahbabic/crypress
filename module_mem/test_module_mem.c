#include "module_mem.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{	
	int* Cf=0;
	char* Ff=0;
	Cf=mem_remem_tabs(Cf, "char", 0);
	Ff=mem_remem_tabs(Ff,"int",0);
	Cf=mem_remem_tabs(Cf, "char", 2);
	Ff=mem_remem_tabs(Ff,"int",2);
	Ff[0]=1;
	Ff[1]=0;
	Cf[0]='a';
	Cf[1]='b';
	printf("%c%c%d%d\n",Cf[0],Cf[1],Ff[0],Ff[1] );

	return 0;
}

