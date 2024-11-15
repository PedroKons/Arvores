#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

template<typename TIPO>
struct TNo {
    int chave;
    TIPO dado;
    TNo<TIPO> * direita;
    TNo<TIPO> * esquerda;
};

template<typename TIPO>
struct TArvore {
    TNo<TIPO> * raiz;
};

template<typename TIPO>
bool inicializaArvore(TArvore<TIPO> &no) {
    no.raiz = NULL;
    return true;
}

template<typename TIPO>
void insereArvore(TNo<TIPO> *&no, TIPO dado, int chave) {
    if(no == NULL) {
        no = new TNo<TIPO>;
        no->dado = dado;
        no->chave = chave;
        no->direita =  NULL;
        no->esquerda = NULL;
    } else {
        if(chave > no->chave) {
            insereArvore(no->direita, dado, chave);
        } else  {
            if(chave < no->chave) {
                insereArvore(no->esquerda, dado, chave);
            }
        }
    }

}

template<typename TIPO>
void prefixadoesq(TNo<TIPO> *no) { // pre fixado a esquerda
    if (no != NULL) {
        cout << "Chave: " << no->chave << ", Dado: " << no->dado << endl;
        prefixadoesq(no->esquerda);
        prefixadoesq(no->direita);
    }
}

template<typename TIPO>
void centralesq(TNo<TIPO> *no) { // central a esquerda
    if (no != NULL) {

        centralesq(no->esquerda);
        cout << "Chave: " << no->chave << ", Dado: " << no->dado << endl;
        centralesq(no->direita);
    }
}

template<typename TIPO>
void posfixado(TNo<TIPO> *no) { // pos fixado
    if (no != NULL) {

        posfixado(no->esquerda);
        posfixado(no->direita);
        cout << "Chave: " << no->chave << ", Dado: " << no->dado << endl;
    }
}

template<typename TIPO>
void removerArvore(TNo<TIPO> *&no, int chave) {
    if(no != NULL){
        if(no->chave == chave){

            if(no->direita == NULL && no->esquerda == NULL){ // Se o nó nao tiver filhos
                delete no;
                no = NULL;
            } else if(no->esquerda == NULL){ // Se tiver filhos a diretia
                TNo<TIPO> *temp = no;
                no = no->direita;
                delete temp;
            } else if (no->direita == NULL) { // se tiver filhos a esquerda
                TNo<TIPO> *temp = no;
                no = no->esquerda;
                delete temp;
            } else {
                //caso tenha dois filhos
                TNo<TIPO> *antecessor = no->esquerda;
                while (antecessor->direita != NULL) {
                    antecessor = antecessor->direita;
                }

                no->chave = antecessor->chave;
                no->dado = antecessor->dado;
                removerArvore(no->esquerda, antecessor->chave);
            }
        } else {
            removerArvore(no->esquerda, chave);
            removerArvore(no->direita, chave);
        }
    }
}


#endif // ARVOREBINARIA_H_INCLUDED
