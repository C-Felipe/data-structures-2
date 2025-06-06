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
        }
        else if (raiz->direito == NULL) {
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

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        emOrdem(raiz->direito);
    }
}

int main() {
    No* raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Percurso em ordem (in-ordem) da árvore:\n");
    emOrdem(raiz);
    printf("\n\n");

    // Buscando valor 40
    No* encontrado = buscar(raiz, 40);
    if (encontrado != NULL) {
        printf("Busca: Valor %d encontrado na árvore.\n\n", encontrado->dado);
    } else {
        printf("Busca: Valor não encontrado na árvore.\n\n");
    }

    // Removendo valores 20, 30 e 50
    printf("Removendo valores 20, 30 e 50 da árvore...\n");
    raiz = remover(raiz, 20);
    raiz = remover(raiz, 30);
    raiz = remover(raiz, 50);

    printf("Percurso em ordem (in-ordem) da árvore após as remoções:\n");
    emOrdem(raiz);
    printf("\n");

    return 0;
}
