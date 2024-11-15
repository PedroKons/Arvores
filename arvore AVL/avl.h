#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include <iostream>
using namespace std;

template<typename TIPO>
struct TNo {
    int chave;
    TIPO dado;
    int fatorEquilibrio;
    TNo<TIPO>* direita;
    TNo<TIPO>* esquerda;
};

template<typename TIPO>
struct TArvore {
    TNo<TIPO>* raiz;
};

template<typename TIPO>
bool inicializaArvore(TArvore<TIPO>& arvore) {
    arvore.raiz = nullptr;
    return true;
}

template<typename TIPO>
void LL(TNo<TIPO>*& r) {
    TNo<TIPO>* b = r;
    TNo<TIPO>* a = b->esquerda;
    b->esquerda = a->direita;
    a->direita = b;

    a->fatorEquilibrio = 0;
    b->fatorEquilibrio = 0;
    r = a;
}

template<typename TIPO>
void RR(TNo<TIPO>*& r) {
    TNo<TIPO>* a = r;
    TNo<TIPO>* b = a->direita;
    a->direita = b->esquerda;
    b->esquerda = a;

    a->fatorEquilibrio = 0;
    b->fatorEquilibrio = 0;
    r = b;
}

template<typename TIPO>
void RL(TNo<TIPO>*& r) {
    TNo<TIPO>* a = r;
    TNo<TIPO>* c = a->direita;
    TNo<TIPO>* b = c->esquerda;
    c->esquerda = b->direita;
    a->direita = b->esquerda;
    b->esquerda = a;
    b->direita = c;

    switch (b->fatorEquilibrio) {
    case -1:
        a->fatorEquilibrio = 0;
        c->fatorEquilibrio = 1;
        break;
    case 0:
        a->fatorEquilibrio = 0;
        c->fatorEquilibrio = 0;
        break;
    case 1:
        a->fatorEquilibrio = -1;
        c->fatorEquilibrio = 0;
        break;
    }
    b->fatorEquilibrio = 0;
    r = b;
}

template<typename TIPO>
void LR(TNo<TIPO>*& r) {
    TNo<TIPO>* a = r;
    TNo<TIPO>* c = a->esquerda;
    TNo<TIPO>* b = c->direita;
    c->direita = b->esquerda;
    a->esquerda = b->direita;
    b->direita = a;
    b->esquerda = c;

    switch (b->fatorEquilibrio) {
    case -1:
        a->fatorEquilibrio = 0;
        c->fatorEquilibrio = 1;
        break;
    case 0:
        a->fatorEquilibrio = 0;
        c->fatorEquilibrio = 0;
        break;
    case 1:
        a->fatorEquilibrio = -1;
        c->fatorEquilibrio = 0;
        break;
    }
    b->fatorEquilibrio = 0;
    r = b;
}

template<typename TIPO>
int insereArvore(TNo<TIPO>*& no, int chave, TIPO dado) {
    if (no == nullptr) {
        no = new TNo<TIPO>;
        no->chave = chave;
        no->dado = dado;
        no->fatorEquilibrio = 0;
        no->direita = nullptr;
        no->esquerda = nullptr;
        return 1;
    } else {
        if (chave > no->chave) {
            int n = insereArvore(no->direita, chave, dado);
            no->fatorEquilibrio += n;
            if (no->fatorEquilibrio > 1) {
                if (chave > no->direita->chave) {
                    RR(no);
                } else {
                    RL(no);
                }
                return 0;
            } else {
                return no->fatorEquilibrio != 0;
            }
        } else if (chave < no->chave) {
            int n = insereArvore(no->esquerda, chave, dado);
            no->fatorEquilibrio -= n;
            if (no->fatorEquilibrio < -1) {
                if (chave < no->esquerda->chave) {
                    LL(no);
                } else {
                    LR(no);
                }
                return 0;
            } else {
                return no->fatorEquilibrio != 0;
            }
        } else {
            return 0; // Elemento já existe
        }
    }
}

template<typename TIPO>
void removerArvore(TNo<TIPO>*& no, int chave) {
    if (no == nullptr) return;

    if (chave < no->chave) {
        removerArvore(no->esquerda, chave);
    } else if (chave > no->chave) {
        removerArvore(no->direita, chave);
    } else {
        if (no->esquerda == nullptr || no->direita == nullptr) {
            TNo<TIPO>* temp = no->esquerda ? no->esquerda : no->direita;
            if (temp == nullptr) {
                temp = no;
                no = nullptr;
            } else {
                *no = *temp;
            }
            delete temp;
        } else {
            TNo<TIPO>* temp = no->esquerda;
            while (temp->direita != nullptr) {
                temp = temp->direita;
            }
            no->chave = temp->chave;
            no->dado = temp->dado;
            removerArvore(no->esquerda, temp->chave);
        }
    }

    if (no == nullptr) return;

    no->fatorEquilibrio = height(no->esquerda) - height(no->direita);

    if (no->fatorEquilibrio > 1) {
        if (height(no->esquerda->esquerda) >= height(no->esquerda->direita)) {
            LL(no);
        } else {
            LR(no);
        }
    } else if (no->fatorEquilibrio < -1) {
        if (height(no->direita->direita) >= height(no->direita->esquerda)) {
            RR(no);
        } else {
            RL(no);
        }
    }
}


//void imprimeNo(int c, int b) {
//    for (int i = 0; i < b; i++) {
//        cout << "   ";
//    }
//    cout << c << endl;
//}

void imprimeNo(char c, int b) {
    for (int i = 0; i < b; i++) {
        cout << "   ";
    }
    cout << c << endl;
}


template<typename TIPO>
void MostraArvore(TNo<TIPO>* a, int b) {
    if (a == nullptr) {
        imprimeNo('*', b);  // Chamada correta sem dedução de tipo
        return;
    }
    MostraArvore(a->direita, b + 3);
    imprimeNo(a->chave, b);  // Chamada correta sem dedução de tipo
    MostraArvore(a->esquerda, b + 3);
}

template<typename TIPO>
int height(TNo<TIPO>* n) {
    if (n == nullptr) {
        return 0;
    }
    int leftHeight = height(n->esquerda);
    int rightHeight = height(n->direita);
    return max(leftHeight, rightHeight) + 1;
}

#endif // AVL_H_INCLUDED
