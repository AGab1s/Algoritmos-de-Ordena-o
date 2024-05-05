// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar um array usando o algoritmo Insertion Sort
void insertionSort(int arr[], int n, int *comparisons) {
    int i, key, j;
    // Loop para mover a fronteira do subarray ordenado
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos do arr[0..i-1], que são maiores que a chave, para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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
            insertionSort(arr, sizes[j], &comparisons);
            // Imprime o número de comparações
            printf("Vetor %d de tamanho %d: %d comparações\n", i+1, sizes[j], comparisons);

            // Libera a memória alocada para o array
            free(arr);
        }
    }

    return 0;
}
