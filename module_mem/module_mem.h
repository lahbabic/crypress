#define tableau_entrer t->te
#define tableau_int t->ti
#define tableau_binaire t->tb
#define taille_tableau t->sot
#define tableau_sortie t->ts
#define taille_sortie t->sots
#define tableau_sortieH t->tsh
#define taille_sortieH t->sotsh

struct 	tabs_s
{
    int sot; // size of tabs
    char *te; //tabs entrée
    int *ti; //tabs int
    int *tb; //tab binaire
    char *ts;
    int sots;
    int* tsh;
    int sotsh;
};
typedef struct tabs_s *tabs;
struct code_s{
	int* b;
	char c;
	int sob;
	int id;
	struct code_s *suivant;
};
typedef struct code_s *code;


typedef void* dont_now_type;
dont_now_type mem_remem_tabs(void *tab, char *type, int size);
tabs mem_taux(tabs t);