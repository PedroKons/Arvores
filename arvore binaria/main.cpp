#include <iostream>
using namespace std;
#include "arvoreBinaria.h"

int main()
{
    TArvore<int> minhaArvore;
    inicializaArvore(minhaArvore);
    insereArvore(minhaArvore.raiz, 10, 10);
    insereArvore(minhaArvore.raiz, 5, 5);
    insereArvore(minhaArvore.raiz, 15, 15);
    insereArvore(minhaArvore.raiz, 7, 7);
    insereArvore(minhaArvore.raiz, 12, 12);
    insereArvore(minhaArvore.raiz, 20, 20);
    insereArvore(minhaArvore.raiz, 8, 8);
    insereArvore(minhaArvore.raiz, 2, 2);


    cout << "Arvore Binaria de Busca:" <<endl;
    cout << "-------------------------" <<endl;
    removerArvore(minhaArvore.raiz,10);
    centralesq(minhaArvore.raiz);

    return 0;
}
