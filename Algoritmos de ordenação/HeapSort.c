// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função para criar um heap máximo a partir de um array
void heapify(int arr[], int n, int i, int *comparisons) {
    int largest = i; // Inicializa o maior como raiz
    int left = 2*i + 1;
    int right = 2*i + 2;

    // Se o filho esquerdo é maior que a raiz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        (*comparisons)++;
    }

    // Se o filho direito é maior que a raiz
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        (*comparisons)++;
    }

    // Se a maior não é a raiz
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursivamente cria o heap afetado
        heapify(arr, n, largest, comparisons);
    }
}

// Função principal para fazer a ordenação heap
void heapSort(int arr[], int n, int *comparisons) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comparisons);

    // Um por um extrai um elemento do heap
    for (int i=n-1; i>=0; i--) {
        // Move a raiz atual para o fim
        swap(&arr[0], &arr[i]);

        // chama max heapify na pilha reduzida
        heapify(arr, i, 0, comparisons);
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
            heapSort(arr, sizes[j], &comparisons);
            // Imprime o número de comparações
            printf("Vetor %d de tamanho %d: %d comparações\n", i+1, sizes[j], comparisons);

            // Libera a memória alocada para o array
            free(arr);
        }
    }

    return 0;
}
