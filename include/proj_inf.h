typedef struct tabs_s *tabs;

tabs lire_entrer();
//tabs lire_fichier(const char *name);
tabs convert_tchar_into_tint(tabs t);
tabs binaire(tabs t);
tabs trier(tabs t);
void affichage(tabs t);