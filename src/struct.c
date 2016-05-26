
#define tableau_entrer t->te
#define tableau_trier t->tt
#define tableau_binaire t->tb
#define taille_tableau t->sot
struct 			tabs_s
{
    int sot; // size of tabs
    char *te; //tabs entrée
    int *tt; //tabs trier
    int *tb; //tab binaire

};
typedef struct tabs_s *tabs;