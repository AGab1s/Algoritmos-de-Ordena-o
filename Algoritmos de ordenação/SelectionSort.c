// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar um array usando o algoritmo Selection Sort
void selectionSort(int arr[], int n, int *comparisons) {
    int i, j, min_idx, temp;
    // Loop para mover a fronteira do subarray ordenado
    for (i = 0; i < n-1; i++) {
        // Encontra o mínimo elemento no subarray desordenado
        min_idx = i;
        for (j = i+1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Troca o mínimo elemento encontrado pelo primeiro elemento
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Função para imprimir um array
void printArray(int arr[], int n) {
    int i;
    // Loop para percorrer todos os elementos do array
    for (i=0; i < n; i++)
        // Imprime o elemento atual
        printf("%d ", arr[i]);
    printf("\n");
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
            selectionSort(arr, sizes[j], &comparisons);
            // Imprime o número de comparações
            printf("Vetor %d de tamanho %d: %d comparações\n", i+1, sizes[j], comparisons);
            // Imprime o array ordenado

            // Libera a memória alocada para o array
            free(arr);
        }
    }

    return 0;
}
