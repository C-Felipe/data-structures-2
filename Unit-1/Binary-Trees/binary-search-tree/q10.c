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

int nivel(No* raiz, int valor, int nivelAtual) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return nivelAtual;
    if (valor < raiz->dado)
        return nivel(raiz->esquerdo, valor, nivelAtual + 1);
    else
        return nivel(raiz->direito, valor, nivelAtual + 1);
}

int main() {
    No* raiz = NULL;
    int n, valor, i, buscar, niv;

    printf("Quantos elementos deseja inserir na árvore? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        raiz = inserir(raiz, valor);
    }

    printf("Digite o valor do nó para calcular o nível: ");
    scanf("%d", &buscar);

    niv = nivel(raiz, buscar, 0);

    if (niv == -1)
        printf("O valor %d não foi encontrado na árvore.\n", buscar);
    else
        printf("O nível do nó com valor %d é: %d\n", buscar, niv);

    return 0;
}