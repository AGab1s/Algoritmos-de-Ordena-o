// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para encontrar o máximo em um array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Função para fazer a ordenação Counting Sort
void countingSort(int arr[], int n, int *comparisons) {
    int max = getMax(arr, n);
    int *count = malloc((max + 1) * sizeof(int));

    // Inicializa o array de contagem
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Armazena a contagem de cada elemento
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        count[arr[i]]++;
    }

    // Altera o array para que ele contenha a posição atual de cada elemento no array de saída
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Constrói o array de saída
    int *output = malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copia o array de saída para arr[] para que arr[] contenha os elementos ordenados
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Libera a memória alocada
    free(count);
    free(output);
}

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(0));
    // Define os tamanhos dos arrays a serem gerados
    int sizes[] = {5, 10, 100, 1000, 10000};
    int sizeCount = sizeof(sizes)/sizeof(sizes[0]);
    int i, j, k;

    // Loop para gerar 50 arrays
    for (i = 0; i < 50; i++) {
        // Loop para cada tamanho de array
        for (j = 0; j < sizeCount; j++) {
            // Aloca memória para o array
            int *arr = malloc(sizes[j] * sizeof(int));
            // Preenche o array com números aleatórios
            for (k = 0; k < sizes[j]; k++) {
                arr[k] = rand() % 100;
            }

            // Inicializa o contador de comparações
            int comparisons = 0;
            // Ordena o array e conta as comparações
            countingSort(arr, sizes[j], &comparisons);
            // Imprime o número de comparações
            printf("Vetor %d de tamanho %d: %d comparações\n", i+1, sizes[j], comparisons);

            // Libera a memória alocada para o array
            free(arr);
        }
    }

    return 0;
}
