#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

// Função que particiona o array e encontra o pivô para dividir o array
int partition(int array[], int low, int high) {
    int pivot = array[high]; // Define o último elemento como pivô
    int i = low - 1;         // Índice para os elementos menores que o pivô

    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (array[j] <= pivot) {
            i++; // Incrementa o índice dos elementos menores
            // Troca array[i] e array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // Coloca o pivô na posição correta no array
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1; // Retorna o índice do pivô
}

// Função recursiva para ordenar o array usando Quick Sort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Particiona o array e obtém o índice do pivô
        int pivotIndex = partition(array, low, high);

        // Ordena os elementos antes e depois do pivô
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

// Função auxiliar para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int array[SIZE];

    // Preenche o array com números aleatórios
    printf("Vetor original:\n");
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100; // Números aleatórios entre 0 e 99
        printf("%d ", array[i]);
    }
    printf("\n");

    // Ordena o array usando quick sort
    quickSort(array, 0, SIZE - 1);

    // Imprime o array ordenado
    printf("\nVetor ordenado:\n");
    printArray(array, SIZE);

    return 0;
}
