# include "chaine.h"

//---------------------------------------------------------------------------//
//                 Fonctions sur les chaînes de caractères.                  //
//---------------------------------------------------------------------------//

/**
 * Calcule la taille d'une chaîne de caractères passée en argument.
 *
 */
int taille(char *ch) {
    int i = 0;
    while (ch[i] != '\0')
        i++;
    return i;
}



/**
 * Copie une chaine source (*s) dans une chaine de destination (*d).
 *
 */
void copy(char *s, char *d) {
    int i = 0;
    while (s[i] != '\0') {
        d[i] = s[i];
        i++;
    }
    s[i] = '\0';
}



/**
 * Concatène une chaine (*ch1) avec une chaine (*ch2) et place le résultat dans
 * (*resultat). A la fin de l'opération, resultat = ch1 + ch2.
 *
 */
void concatenation(char *ch1, char *ch2, char *resultat) {
    int i = 0;
    while (ch1[i] != '\0') {
        resultat[i] = ch1[i];
        i++;
    }

    int j = 0;
    while (ch2[j] != '\0') {
        resultat[i + j] = ch2[j];
        j++;
    }

    resultat[i + j] = '\0';
}



/**
 * Vérifie si deux chaines de caractères sont identiques.
 *
 */
bool egale(char *ch1, char *ch2) {
    int i = 0;
    while (ch1[i] != '\0' && ch2[i] != '\0') {
        if (ch1[i] != ch2[i])
            return false;
        i++;
    }
        
    return (ch1[i] == '\0' && ch2[i] == '\0');
}



/**
 * Vérifie si le caractère (c) est présent dans la chaine (*s).
 *
 */
bool cherche_char(char *s , char c) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == c)
            return true;
        i++;
    }
    return false;
}



/**
 * Extrait (n) caractères de la chaine (*ch1) en commençant à l'indice (deb).
 * Si l'opération est impossible, renvoie false, sinon met la chaine extraite
 * dans (*resultat) et renvoie true.
 *
 */
bool extraction(char *ch1, int deb, int n, char *resultat) {
    int i = 0;
    if ((deb + n) > taille(ch1))
        return false; 
    for (i = 0 ; i < n ; i++)
        resultat[i] = ch1[deb + i];
    resultat[i] = '\0';
    return true;
}



/**
 * Teste si la chaine (*ch1) contient la chaine (*ch2).
 *
 */
bool contient(char *ch1, char *ch2) {
    int i = 0;
    char res[512];
    int l2 = taille(ch2);
    while (extraction(ch1, i, l2, res)) {
        if (egale(ch2, res))
            return true;
        i++;
    }
    return false;
}








