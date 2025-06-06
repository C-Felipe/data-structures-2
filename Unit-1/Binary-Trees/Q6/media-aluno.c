// Calcular a m´edia das notas dos alunos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um nó da árvore (cada nó é um estudante)
typedef struct Estudante {
    char nome[50];
    int id;
    float media;
    struct Estudante *esq;
    struct Estudante *dir;
} Estudante;

// Cria um novo nó com os dados fornecidos
Estudante* novoEstudante(char *nome, int id, float media) {
    Estudante *novo = (Estudante*) malloc(sizeof(Estudante));
    strcpy(novo->nome, nome);
    novo->id = id;
    novo->media = media;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Insere um estudante na árvore binária de busca com base no ID
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

// Percorre a árvore e acumula as médias dos estudantes
void calcularMediaGeral(Estudante *raiz, float *total, int *qtd) {
    if (raiz == NULL) return;
    calcularMediaGeral(raiz->esq, total, qtd);
    *total += raiz->media;
    (*qtd)++;
    calcularMediaGeral(raiz->dir, total, qtd);
}

int main() {
    Estudante *raiz = NULL;
    int quantidade, id, count = 0;
    float media, acumulador = 0;
    char nome[50];

    printf("Quantos estudantes deseja cadastrar? ");
    scanf("%d", &quantidade);
    getchar();

    for (int i = 0; i < quantidade; i++) {
        printf("\nNome do estudante: ");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = 0;

        printf("Matricula do estudante: ");
        scanf("%d", &id);

        printf("Média obtida: ");
        scanf("%f", &media);
        getchar();

        raiz = adicionar(raiz, nome, id, media);
    }

    calcularMediaGeral(raiz, &acumulador, &count);

    if (count > 0) {
        printf("\nMédia geral da turma: %.2f\n", acumulador / count);
    } else {
        printf("\nNenhum registro para cálculo da média.\n");
    }

    return 0;
}
