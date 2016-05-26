struct arbre_s
{
	char c;
	int f;
	int nb;
	struct arbre_s * fd;
	struct arbre_s * fg;
};
typedef struct arbre_s *arbre;
typedef struct tabs_s *tabs;
typedef struct code_s *code;


code creationA(tabs t);
tabs codageH(tabs t,const code D);