// Utilizando uma abordagem iterativa.

#include <stdio.h>
#include <time.h>

// Fun��o iterativa para calcular o n-�simo n�mero de Fibonacci
unsigned long long fibonacci(int n) {
    if (n <= 1)
        return 1;

    unsigned long long a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 20;                  // Valor de Fibonacci a ser calculado
    int NMax = 100000;          // N�mero de repeti��es para m�dia
    double total_time = 0;

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        unsigned long long result = fibonacci(n);                 // Chamada da fun��o
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;   // Soma do tempo
    }

    // Impress�o do tempo m�dio por execu��o
    printf("Tempo medio p = %d: %.12f segundos\n", n, total_time / NMax);

    return 0;
}
