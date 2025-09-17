#include <iostream>
#include <cstring>  // pour memset
#include "utilities.h"

using namespace std;

int main() 
{
    const int n = 6; // nombre de sommets
    int s = 0, t = 5;

    // Allocation dynamique des matrices
    int* c[n];
    int* f[n];

    for (int i = 0; i < n; ++i) {
        c[i] = new int[n];
        f[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            f[i][j] = 0;
        }
    }

    // Définition des capacités
    c[0][1] = 10;
    c[0][2] = 10;
    c[1][3] = 4;
    c[1][4] = 8;
    c[1][2] = 2;
    c[2][4] = 9;
    c[4][3] = 6;
    c[3][5] = 10;
    c[4][5] = 10;

    // Affichage de la matrice de capacité
    cout << "Matrice de capacité C:" << endl;
    affichage(c, n);

    bool S[n]; // pour la coupe minimale (non utilisée ici)
    int flot_max = fordfulkerson(c, f, n, s, t, S);

    cout << "Flot maximal de " << s << " à " << t << " = " << flot_max << endl;

    cout << "\nMatrice des flots F après exécution : " << endl;
    affichage(f, n);

    cout << "\nCoupe minimale (S/T) :\n";
cout << "S (atteignables depuis la source dans le graphe résiduel) : ";
for (int i = 0; i < n; ++i)
    if (S[i]) cout << i << " ";
cout << endl;

cout << "T (le reste) : ";
for (int i = 0; i < n; ++i)
    if (!S[i]) cout << i << " ";
cout << endl;

    // Libération mémoire
    for (int i = 0; i < n; ++i) {
        delete[] c[i];
        delete[] f[i];
    }

    return 0;
}