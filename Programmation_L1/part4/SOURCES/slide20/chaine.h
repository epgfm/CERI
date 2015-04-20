# ifndef _CHAINE_H_
# define _CHAINE_H_

int taille(char *ch);
void copy(char *s, char *d);
void concatenation (char *ch1, char *ch2, char *resultat);
bool egale(char *ch1, char *ch2);
bool cherche_char(char *s , char c);
bool extraction(char *ch1, int deb, int n, char *resultat);
bool contient(char *ch1, char *ch2);

# endif // _CHAINE_H_
