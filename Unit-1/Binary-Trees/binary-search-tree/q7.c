#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

No* criarNo(int dado) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = dado;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

No* inserir(No* raiz, int dado) {
    if (raiz == NULL) return criarNo(dado);
    if (dado < raiz->dado)
        raiz->esquerdo = inserir(raiz->esquerdo, dado);
    else if (dado > raiz->dado)
        raiz->direito = inserir(raiz->direito, dado);
    return raiz;
}

int altura(No* raiz) {
    if (raiz == NULL) return -1; // altura de árvore vazia é -1 (ou 0, conforme convenção)
    int alturaEsq = altura(raiz->esquerdo);
    int alturaDir = altura(raiz->direito);
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

int main() {
    No* raiz = NULL;
    int n, valor, i;

    printf("Informe quantos elementos deseja inserir na árvore: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        raiz = inserir(raiz, valor);
    }

    int h = altura(raiz);
    printf("A altura da árvore binária é: %d\n", h);

    return 0;
}