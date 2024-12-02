#include <stdio.h>

// Função que implementa o algoritmo Selection Sort
// Esta função ordena o vetor de forma crescente
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    // O loop externo percorre cada elemento do vetor
    for (i = 0; i < n - 1; i++) {
        // Assume que o menor elemento é o primeiro da sublista não ordenada
        minIndex = i;

        // O loop interno encontra o índice do menor elemento na sublista não ordenada
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Atualiza o índice do menor elemento
            }
        }

        // Se o menor elemento não for o primeiro da sublista não ordenada, faz a troca
        if (minIndex != i) {
            // Troca o elemento atual com o menor elemento encontrado
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Função auxiliar para imprimir o vetor
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Declaração e inicialização do vetor não ordenado de 50 elementos
    int arr[50] = {87, 23, 45, 12, 67, 90, 34, 56, 78, 9,
                   33, 15, 27, 18, 98, 72, 54, 2, 10, 37,
                   89, 11, 55, 88, 22, 66, 77, 44, 25, 63,
                   3, 31, 5, 97, 74, 46, 50, 36, 70, 61,
                   6, 42, 83, 28, 91, 82, 53, 38, 48, 29};

    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o número de elementos no vetor

    printf("Vetor antes da ordenação: \n");
    printArray(arr, n);

    // Chama a função selectionSort para ordenar o vetor
    selectionSort(arr, n);

    printf("Vetor após a ordenação: \n");
    printArray(arr, n);

    return 0;
}
