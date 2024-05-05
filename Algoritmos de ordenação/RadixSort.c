// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para obter o máximo valor em arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Função principal para fazer a contagem de classificação de arr[] de acordo com o dígito representado por exp.
void countSort(int arr[], int n, int exp, int *comparisons) {
    int output[n]; // array de saída
    int i, count[10] = {0};

    // Armazena a contagem de ocorrências em count[]
    for (i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    // Muda count[i] para que count[i] agora contenha a posição atual deste dígito no output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Constrói o array de saída
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    // Copia o array de saída para arr[], então arr[] contém números inteiros ordenados de acordo com o dígito atual
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Função principal para fazer a ordenação Radix Sort
void radixsort(int arr[], int n, int *comparisons) {
    // Encontra o número máximo para saber o número de dígitos
    int m = getMax(arr, n);

    // Faz a contagem de classificação para cada dígito. Note que, em vez de passar o número de dígitos, exp é passado. exp é 10^i onde i é o número de dígito atual
    for (int exp = 1; m/exp > 0; exp *= 10) {
        (*comparisons)++;
        countSort(arr, n, exp, comparisons);
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
            radixsort(arr, sizes[j], &comparisons);
            // Imprime o número de comparações
            printf("Vetor %d de tamanho %d: %d comparações\n", i+1, sizes[j], comparisons);

            // Libera a memória alocada para o array
            free(arr);
        }
    }

    return 0;
}
