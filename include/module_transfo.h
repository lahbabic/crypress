typedef struct tabs_s *tabs;
typedef struct code_s *code;
tabs convert_tchar_into_tint(tabs t);
tabs trier(tabs t);
tabs binaire(tabs t);
tabs codage(tabs t, const code D);
void affichC(code c);
void affichTS(tabs t);
void test_nonambigu(code c);
tabs 			trier(tabs t);