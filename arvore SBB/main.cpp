#include <iostream>
using namespace std;
#include "sbb.h"

int main()
{
    TArvore<char> arvSBB;
    inicializa(arvSBB);

    char insere, i = 0;

    while(i < 50){
        system("cls");
        cout << "\t\tValor a ser inserido: ";
        cin >> insere;
        inserir(arvSBB.raiz, insere, insere);
        cout << "\n\n\n\n";
        mostrar_arv(arvSBB.raiz);
        system("pause>nul");
        i++;
    }

    return 0;
}
