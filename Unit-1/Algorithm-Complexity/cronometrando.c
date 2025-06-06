// Cronometrando o algoritmo

#include <stdio.h>
#include <time.h>

// Função recursiva que calcula um valor baseado em x(n-1) + x(n-2)
int x(int n) {
    if (n <= 1)
        return 1;                       // Caso base: para n=0 ou n=1, retorna 1
    return x(n - 1) + x(n - 2);        // Passo recursivo: soma resultados dos dois casos anteriores
}

int main() {
    int n = 20;                         // Valor para calcular x(n)
    int NMax = 1000;                   // Número de repetições para calcular o tempo médio de execução
    double total_time = 0;            // Acumulador para o tempo total de todas as execuções

    // Loop para executar a função x(n) NMax vezes e medir o tempo
    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();         // Marca o tempo antes da execução
        x(n);                           // Chama a função recursiva
        clock_t end = clock();         // Marca o tempo após a execução

        // Calcula o tempo gasto nessa execução e soma ao total
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    // Imprime o tempo médio de execução da função x(n)
    printf("Tempo medio: %f segundos\n", total_time / NMax);

    return 0;
}
