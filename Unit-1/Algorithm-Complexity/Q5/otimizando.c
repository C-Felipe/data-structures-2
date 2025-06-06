// Otimizando oalgoritmo


#include <stdio.h>
#include <time.h>

#define MAX_N 1000 // Tamanho m�ximo do vetor de memoiza��o (deve ser >= n)

// N�mero de vezes que o c�lculo ser� repetido para medir o tempo m�dio
int NMax = 100000;

// Vetor global para armazenar resultados j� calculados (memoiza��o)
int memo[MAX_N]; 

// Fun��o recursiva de Fibonacci com memoiza��o (top-down)
int x(int n) {
    if (n <= 1)
        return 1; // Caso base: F(0) = 1 e F(1) = 1 (padr�o usado aqui)

    if (memo[n] != 0)
        return memo[n]; // Se j� foi calculado, retorna o valor salvo

    // Calcula e armazena o valor antes de retornar
    memo[n] = x(n - 1) + x(n - 2);
    return memo[n];
}

int main() {
    int n = 20; // Valor de n para o qual a fun��o ser� testada
    double total_time = 0; // Acumulador do tempo total

    clock_t start, end; // Vari�veis para marca��o do tempo

    start = clock(); // In�cio da contagem do tempo

    for (int i = 0; i < NMax; i++) {
        // Zera o vetor memo para simular uma nova execu��o "do zero"
        for (int j = 0; j <= n; j++) {
            memo[j] = 0;
        }

        x(n); // Executa a fun��o de Fibonacci com memoiza��o
    }

    end = clock(); // Fim da contagem do tempo

    // Converte o tempo total para segundos
    total_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calcula o tempo m�dio por execu��o
    double tempo_medio = total_time / NMax;

    // Exibe o tempo m�dio com 12 casas decimais
    printf("Tempo medio = %.12f segundos\n", tempo_medio);

    return 0;
}
