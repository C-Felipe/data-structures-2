#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->dado = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    } else if (valor > raiz->dado) {
        raiz->direito = inserir(raiz->direito, valor);
    }

    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) {
        return raiz;
    }

    if (valor < raiz->dado) {
        return buscar(raiz->esquerdo, valor);
    } else {
        return buscar(raiz->direito, valor);
    }
}

No* encontrarMenor(No* raiz) {
    while (raiz && raiz->esquerdo != NULL) {
        raiz = raiz->esquerdo;
    }
    return raiz;
}

No* remover(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->dado) {
        raiz->esquerdo = remover(raiz->esquerdo, valor);
    } else if (valor > raiz->dado) {
        raiz->direito = remover(raiz->direito, valor);
    } else {
        if (raiz->esquerdo == NULL && raiz->direito == NULL) {
            free(raiz);
            return NULL;
        }
        else if (raiz->esquerdo == NULL) {
            No* temp = raiz->direito;
            free(raiz);
            return temp;
        } else if (raiz->direito == NULL) {
            No* temp = raiz->esquerdo;
            free(raiz);
            return temp;
        }
        else {
            No* temp = encontrarMenor(raiz->direito);
            raiz->dado = temp->dado;
            raiz->direito = remover(raiz->direito, temp->dado);
        }
    }
    return raiz;
}

int main() {
    No* raiz = NULL;

    return 0;
}