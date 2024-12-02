#include <stdio.h>

// Função que ordena o vetor usando o algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    
    // Percorre o vetor várias vezes
    for (i = 0; i < n - 1; i++) {
        // Compara e troca elementos adjacentes
        for (j = 0; j < n - i - 1; j++) {
            // Se o elemento atual é maior que o próximo, faz a troca
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];       // Armazena o valor de arr[j]
                arr[j] = arr[j + 1]; // Coloca arr[j+1] em arr[j]
                arr[j + 1] = temp;   // Coloca o valor salvo em arr[j+1]
            }
        }
    }
}

// Função que imprime o vetor
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Vetor com 50 elementos não ordenados
    int arr[50] = {87, 23, 45, 12, 67, 90, 34, 56, 78, 9,
                   33, 15, 27, 18, 98, 72, 54, 2, 10, 37,
                   89, 11, 55, 88, 22, 66, 77, 44, 25, 63,
                   3, 31, 5, 97, 74, 46, 50, 36, 70, 61,
                   6, 42, 83, 28, 91, 82, 53, 38, 48, 29};

    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o número de elementos no vetor

    printf("Vetor antes da ordenação: \n");
    printArray(arr, n);

    // Ordena o vetor usando bubbleSort
    bubbleSort(arr, n);

    printf("Vetor após a ordenação: \n");
    printArray(arr, n);

    return 0;
}
