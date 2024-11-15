#include <iostream>
using namespace std;
#include "AVL.h"

int main() {
    // Cria uma árvore AVL de inteiros
    TArvore<char> arvore;

    // Inicializa a árvore
    inicializaArvore(arvore);

    // Insere elementos na árvore
    insereArvore(arvore.raiz, 'm', 'm');
    insereArvore(arvore.raiz, 'f', 'f');
    insereArvore(arvore.raiz, 'p', 'p');
    insereArvore(arvore.raiz, 'h', 'h');
    insereArvore(arvore.raiz, 'a', 'a');
    insereArvore(arvore.raiz, 'g', 'g');
    insereArvore(arvore.raiz, 'i', 'i');
    // Mostra a árvore
    cout << "arvore AVL apos a inserçoo:" << endl;
    MostraArvore(arvore.raiz,0);

    return 0;
}
