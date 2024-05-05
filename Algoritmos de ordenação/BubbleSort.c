// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar um array usando o algoritmo Bubble Sort
void bubbleSort(int arr[], int n, int *comparisons) {
    int i, j, temp;
    // Loop para percorrer todos os elementos do array
    for (i = 0; i < n-1; i++) {
        // Loop para percorrer os elementos que ainda não foram ordenados
        for (j = 0; j < n-i-1; j++) {
            // Incrementa o contador de comparações
            (*comparisons)++;
            // Se o elemento atual é maior que o próximo, troca os dois
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
            bubbleSort(arr, sizes[j], &comparisons);
            // Imprime o número de comparações
            printf("Vetor %d de tamanho %d: %d comparações\n", i+1, sizes[j], comparisons);
            
            // Libera a memória alocada para o array
            free(arr);
        }
    }

    return 0;
}
