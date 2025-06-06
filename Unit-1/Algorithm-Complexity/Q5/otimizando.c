// Otimizando oalgoritmo


#include <stdio.h>
#include <time.h>

#define MAX_N 1000 // Tamanho máximo do vetor de memoização (deve ser >= n)

// Número de vezes que o cálculo será repetido para medir o tempo médio
int NMax = 100000;

// Vetor global para armazenar resultados já calculados (memoização)
int memo[MAX_N]; 

// Função recursiva de Fibonacci com memoização (top-down)
int x(int n) {
    if (n <= 1)
        return 1; // Caso base: F(0) = 1 e F(1) = 1 (padrão usado aqui)

    if (memo[n] != 0)
        return memo[n]; // Se já foi calculado, retorna o valor salvo

    // Calcula e armazena o valor antes de retornar
    memo[n] = x(n - 1) + x(n - 2);
    return memo[n];
}

int main() {
    int n = 20; // Valor de n para o qual a função será testada
    double total_time = 0; // Acumulador do tempo total

    clock_t start, end; // Variáveis para marcação do tempo

    start = clock(); // Início da contagem do tempo

    for (int i = 0; i < NMax; i++) {
        // Zera o vetor memo para simular uma nova execução "do zero"
        for (int j = 0; j <= n; j++) {
            memo[j] = 0;
        }

        x(n); // Executa a função de Fibonacci com memoização
    }

    end = clock(); // Fim da contagem do tempo

    // Converte o tempo total para segundos
    total_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calcula o tempo médio por execução
    double tempo_medio = total_time / NMax;

    // Exibe o tempo médio com 12 casas decimais
    printf("Tempo medio = %.12f segundos\n", tempo_medio);

    return 0;
}
