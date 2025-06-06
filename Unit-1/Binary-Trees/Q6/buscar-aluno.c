#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore representando um estudante
typedef struct Estudante {
    char nome[50];
    int id;
    float media;
    struct Estudante *esq;
    struct Estudante *dir;
} Estudante;

// Cria um novo estudante com os dados fornecidos
Estudante* novoEstudante(char *nome, int id, float media) {
    Estudante *novo = (Estudante*) malloc(sizeof(Estudante));
    strcpy(novo->nome, nome);
    novo->id = id;
    novo->media = media;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Insere um estudante na árvore com base no ID
Estudante* adicionar(Estudante *raiz, char *nome, int id, float media) {
    if (raiz == NULL) {
        return novoEstudante(nome, id, media);
    }
    if (id < raiz->id) {
        raiz->esq = adicionar(raiz->esq, nome, id, media);
    } else if (id > raiz->id) {
        raiz->dir = adicionar(raiz->dir, nome, id, media);
    }
    return raiz;
}

// Busca por nome na árvore (varredura completa)
Estudante* procurarPorNome(Estudante *raiz, const char *alvo) {
    if (raiz == NULL) return NULL;
    if (strcmp(raiz->nome, alvo) == 0) return raiz;

    Estudante *achado = procurarPorNome(raiz->esq, alvo);
    if (achado != NULL) return achado;

    return procurarPorNome(raiz->dir, alvo);
}

int main() {
    Estudante *raiz = NULL;
    int total, id;
    float media;
    char nome[50];

    printf("Quantos registros deseja adicionar? ");
    scanf("%d", &total);
    getchar(); // limpar buffer

    for (int i = 0; i < total; i++) {
        printf("\nNome do estudante: ");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = 0;

        printf("Matricula do estudante: ");
        scanf("%d", &id);

        printf("Média final: ");
        scanf("%f", &media);
        getchar();

        raiz = adicionar(raiz, nome, id, media);
    }

    printf("\nDigite o nome do estudante para pesquisar: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = 0;

    Estudante *resultado = procurarPorNome(raiz, nome);

    if (resultado != NULL) {
        printf("\nEncontrado!\nNome: %s\nID: %d\nMédia: %.2f\n",
               resultado->nome, resultado->id, resultado->media);
    } else {
        printf("\nEstudante não localizado.\n");
    }

    return 0;
}
