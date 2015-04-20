# include <iostream>

using namespace std;

int somme_tab(int *t, int taille)
{
    int res = 0;
    for (int i = 0 ; i < taille ; i++)
    {
        res += t[i]; // <--> res = res + t[i];
    }
    return res;
}

int main(int argc, char ** argv)
{
    int  T[10] = {1, 2, 10, 8};
    int somme = somme_tab(T, 10);
    cout <<  "La somme est : " << somme << endl;
    return 0;
}
