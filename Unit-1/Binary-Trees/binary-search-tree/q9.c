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

int soma(No* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dado + soma(raiz->esquerdo) + soma(raiz->direito);
}

int main() {
    No* raiz = NULL;
    int n, valor, i;

    printf("Informe a quantidade de elementos que deseja inserir na árvore: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        raiz = inserir(raiz, valor);
    }

    printf("A soma total dos valores armazenados na árvore é: %d\n", soma(raiz));

    return 0;
}
