#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

// Função para ajustar o heap de forma que o maior elemento esteja na raiz
void heapify(int array[], int size, int i) {
    int largest = i;          // Inicializa o maior como a raiz
    int left = 2 * i + 1;     // Filho à esquerda
    int right = 2 * i + 2;    // Filho à direita

    // Se o filho à esquerda é maior que a raiz
    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    // Se o filho à direita é maior que o maior elemento atual
    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    // Se o maior não for a raiz
    if (largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        // Recursivamente ajusta o sub-heap afetado
        heapify(array, size, largest);
    }
}

// Função para implementar o Heap Sort
void heapSort(int array[], int size) {
    // Constrói o heap (reorganiza o array)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    // Extrai os elementos do heap um por um
    for (int i = size - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Chama heapify na árvore reduzida
        heapify(array, i, 0);
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

    // Ordena o array usando Heap Sort
    heapSort(array, SIZE);

    // Imprime o array ordenado
    printf("\nVetor ordenado:\n");
    printArray(array, SIZE);

    return 0;
}
