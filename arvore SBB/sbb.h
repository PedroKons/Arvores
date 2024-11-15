#ifndef SBB_H_INCLUDED
#define SBB_H_INCLUDED

const char VERTICAL = 'v';
const char HORIZONTAL = 'h';

template <typename TIPO>
struct TNo {
    TIPO chave;
    TIPO dado;
    TNo<TIPO> * dir;
    char orientD;
    TNo<TIPO> * esq;
    char orientE;
};

template <typename TIPO>
struct TArvore {
    TNo<TIPO> * raiz;
};

template <typename TIPO>
bool inicializa(TArvore<TIPO> &arv){
    arv.raiz = NULL;
    return true;
}

template<typename TIPO> //esq esq
void LL(TNo<TIPO> *& r){
    TNo<TIPO> *ap1 = r->esq;
    r->esq = ap1->dir;
    ap1->dir = r;
    ap1->orientE = VERTICAL;
    r->orientE = VERTICAL;
    r = ap1;
}

template<typename TIPO> //dir dir
void RR (TNo<TIPO> *&r) {
    TNo<TIPO> *ap1 = r->dir;
    r->dir = ap1->esq;
    ap1->esq = r;
    ap1->orientD = VERTICAL;
    r->orientD = VERTICAL;
    r = ap1;
}

template<typename TIPO> //dir esq
void RL (TNo<TIPO> *&r) {
    TNo<TIPO> *ap1 = r->dir;
    TNo<TIPO> *ap2 = ap1->esq;
    ap1->orientE = VERTICAL;
    r->orientD = VERTICAL;
    ap1->esq = ap2->dir;
    ap2->dir = ap1;
    r->dir = ap2->esq;
    ap2->esq = r;
    r = ap2;
}

template<typename TIPO> //esq dir
void LR (TNo<TIPO> *&r) {
    TNo<TIPO> * ap1 = r->esq;
    TNo<TIPO> * ap2 = ap1->dir;
    ap1->dir = ap2->esq;
    r->esq = ap2->dir;
    ap2->esq = ap1;
    ap2->dir = r;
    ap1->orientD = VERTICAL;
    r->orientE = VERTICAL;
    r = ap2;
}


template <typename TIPO>
int inserir (TNo<TIPO> *&no, int chave, TIPO dado) {
    int n = 0;
    if(no == NULL) {
        no = new TNo<TIPO>;
        no->chave = chave;
        no->dado = dado;
        no->esq = NULL;
        no->dir = NULL;
//        no->orientD = HORIZONTAL;
//        no->orientE = HORIZONTAL;
        return 1;
    } else {
        if(chave > no->chave) {
           n = inserir(no->dir, chave, dado);
           if( n == 1) {
              no->orientD = HORIZONTAL;
              n++;
           } else {
              if(n == 2 && no->orientD == HORIZONTAL) {
                n = 1;
                if(no->dir->orientD == HORIZONTAL) {
                    RR(no);
                } else {
                    RL(no);
                }
              } else {
                n = 0;
              }
           }
        } else {
            if(chave < no->chave) {
                n = inserir(no->esq, chave, dado);
                if( n == 1) {
                    no->orientE = HORIZONTAL;
                    n++;
                } else {
                    if(n == 2 && no->orientE == HORIZONTAL) {
                        n = 1;
                        if(no->esq->orientE == HORIZONTAL) {
                            LL(no);
                        } else {
                            LR(no);
                        }
                    } else {
                        n = 0;
                    }
                }
            }
        }
    }
    return n;
}


template <typename TIPO>
void printTreeHelper(TNo<TIPO> *no, int space) {
    const int COUNT = 5;
    if (no == nullptr)
        return;

    space += COUNT;

    printTreeHelper(no->dir, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << no->chave << (no->orientD == HORIZONTAL ? '-' : '|') << endl;

    printTreeHelper(no->esq, space);
}

template <typename TIPO>
void mostrar_arv(TNo<TIPO> *no) {
    printTreeHelper(no, 0);
}


#endif // SBB_H_INCLUDED
