// Utilizando uma abordagem iterativa.

#include <stdio.h>
#include <time.h>

// Função iterativa para calcular o n-ésimo número de Fibonacci
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
    int NMax = 100000;          // Número de repetições para média
    double total_time = 0;

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        unsigned long long result = fibonacci(n);                 // Chamada da função
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;   // Soma do tempo
    }

    // Impressão do tempo médio por execução
    printf("Tempo medio p = %d: %.12f segundos\n", n, total_time / NMax);

    return 0;
}
