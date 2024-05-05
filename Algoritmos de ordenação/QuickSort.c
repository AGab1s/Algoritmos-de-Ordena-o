// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função que toma o último elemento como pivô, coloca o pivô no lugar correto no array ordenado,
// e coloca todos os menores (menores que o pivô) à esquerda do pivô e todos os maiores à direita do pivô
int partition (int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high]; // pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor que o pivô
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++; // incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal que implementa o QuickSort
void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        // pi é o índice de partição, arr[p] está agora no lugar certo
        int pi = partition(arr, low, high, comparisons);

        // Ordena separadamente os elementos antes e depois da partição
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
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
            quickSort(arr, 0, sizes[j] - 1, &comparisons);
            // Imprime o número de comparações
            printf("Vetor %d de tamanho %d: %d comparações\n", i+1, sizes[j], comparisons);

            // Libera a memória alocada para o array
            free(arr);
        }
    }

    return 0;
}
