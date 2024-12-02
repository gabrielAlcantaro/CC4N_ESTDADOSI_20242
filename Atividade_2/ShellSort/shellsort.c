#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

// Função que implementa o algoritmo Shell Sort
void shellSort(int array[], int size) {
    // Inicializa o "gap" (intervalo) e diminui progressivamente
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Executa a ordenação por inserção para o intervalo atual
        for (int i = gap; i < size; i++) {
            int temp = array[i]; // Armazena o valor atual
            int j;

            // Move os elementos maiores que 'temp' para frente
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }

            // Coloca o valor armazenado na posição correta
            array[j] = temp;
        }
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

    // Ordena o array usando shell sort
    shellSort(array, SIZE);

    // Imprime o array ordenado
    printf("\nVetor ordenado:\n");
    printArray(array, SIZE);

    return 0;
}
