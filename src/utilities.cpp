#include <iostream>
#include <fstream>
#include <queue>
#include <climits>
#include "utilities.h"

using namespace std;

void affichage(int* mat[], int n)
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n-1); j++)
			cout << mat[i][j] << "\t";
		cout << mat[i][n-1] << endl;		
	}
	cout << endl;
}

/****************************************************/
/* Entrées :                                        */
/* c : matrice des capacités des arcs du réseau     */
/* f : matrice des flots sur les arcs               */
/* n : nombre de noeuds du réseau                   */
/* s : sommet source                                */                            
/* t : sommet destination                           */
/* Sortie : ch : chaîne augmentante de s à t        */
/* (s'il en existe)                                 */
/****************************************************/
/* Indication  : La chaîne augmentante doit être    */
/* trouvée par un parcours en largeur du réseau.    */
/* Un tel parcours se code en utilisant la méthode  */
/* présentée en cours, en remplaçant toutefois la   */
/* pile par une file                                */
/****************************************************/
bool chaineaugmentante(int* c[], int* f[], int n, int ch[],int s, int t)
{
	queue<int> Q;

    for (int i = 0; i < n; i++)
    {
        ch[i] = -1;
    }

    Q.push(s);

    while (!Q.empty())
    {
        int i = Q.front();
        Q.pop();

        for (int j = 0; j < n; j++)
        {
            if (ch[j] == -1 && ((c[i][j] > 0 && f[i][j] < c[i][j]) || (c[j][i] > 0 && f[j][i] > 0)))
            {
                ch[j] = i;

                if (j == t) {return true;}
                else {Q.push(j);}
            }
        }
    }

    return false;
}

/****************************************************/
/* Entrées :                                        */
/* c : matrice des capacités des arcs du réseau     */
/* f : matrice des flots sur les arcs               */
/* n : nombre de noeuds du réseau                   */
/* s : sommet source                                */                            
/* t : sommet destination                           */
/* ch : chaîne augmentante de s à t                 */
/* Sortie : valeur d'augmentation du flot           */
/****************************************************/
int increment(int* c[], int* f[], int n, int ch[], int s, int t)
{
	int delta = INT_MAX;

    int i = t;

	while (i != s)
	{
		if (c[ch[i]][i] > 0 && c[ch[i]][i] - f[ch[i]][i] > 0) 
        {
            delta = min(delta, c[ch[i]][i] - f[ch[i]][i]); 
        }
        
        i = ch[i];
	}

    i = t;

	while (i != s)
	{
		if (c[ch[i]][i] >= f[ch[i]][i] + delta) { f[ch[i]][i] += delta; }
		
        else { f[ch[i]][i] -= delta; }
        
        i = ch[i];
	}

	return delta;
}

/****************************************************/
/* Entrées :                                        */
/* c : matrice des capacités des arcs du réseau     */
/* f : matrice des flots sur les arcs               */
/* n : nombre de noeuds du réseau                   */
/* s : sommet source                                */                            
/* t : sommet destination                           */
/****************************************************/
/* Sorties :                                        */
/* Flot Max de s à t                                */
/* Coupe minimum stockée dans S                     */
/****************************************************/
int fordfulkerson(int* c[], int* f[], int n, int s, int t, bool* S)
{
	int ch[n];
    int delta = 0;

    while(chaineaugmentante(c,f,n,ch,s,t))
    {
        delta += increment(c,f,n,ch,s,t);
    }

    for (int i = 0; i < n; i++)
    {
        S[i] = false;
    }

    queue<int> q;

    S[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        for (int j = 0; j < n; j++)
        {
            if (!S[j] && c[i][j] > f[i][j])
            {
                S[j] = true;
                q.push(j);
            }
        }
    }

	return delta;
}