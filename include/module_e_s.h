typedef struct tabs_s *tabs;
typedef struct code_s *code;
tabs lire_entrer();
tabs lire_fichier(const char *name);
void affichage(tabs t);
code create_code(const char *name);
int convert_tchar_int(char *t);
void write_in_file(tabs t,const char *name);
void affichec(code c);