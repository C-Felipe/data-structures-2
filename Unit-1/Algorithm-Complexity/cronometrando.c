// Cronometrando o algoritmo

#include <stdio.h>
#include <time.h>

// Fun��o recursiva que calcula um valor baseado em x(n-1) + x(n-2)
int x(int n) {
    if (n <= 1)
        return 1;                       // Caso base: para n=0 ou n=1, retorna 1
    return x(n - 1) + x(n - 2);        // Passo recursivo: soma resultados dos dois casos anteriores
}

int main() {
    int n = 20;                         // Valor para calcular x(n)
    int NMax = 1000;                   // N�mero de repeti��es para calcular o tempo m�dio de execu��o
    double total_time = 0;            // Acumulador para o tempo total de todas as execu��es

    // Loop para executar a fun��o x(n) NMax vezes e medir o tempo
    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();         // Marca o tempo antes da execu��o
        x(n);                           // Chama a fun��o recursiva
        clock_t end = clock();         // Marca o tempo ap�s a execu��o

        // Calcula o tempo gasto nessa execu��o e soma ao total
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    // Imprime o tempo m�dio de execu��o da fun��o x(n)
    printf("Tempo medio: %f segundos\n", total_time / NMax);

    return 0;
}
