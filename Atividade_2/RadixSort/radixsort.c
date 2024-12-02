#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

// Função auxiliar para encontrar o maior número no array
int getMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Função auxiliar para realizar a ordenação por contagem com base no dígito significativo atual
void countingSort(int array[], int size, int exp) {
    int output[size]; // Array de saída
    int count[10] = {0}; // Array para contar as ocorrências de cada dígito (0-9)

    // Conta as ocorrências dos dígitos para o dígito significativo atual
    for (int i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    // Atualiza count[i] para conter a posição real de cada dígito no array de saída
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copia os elementos ordenados para o array original
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Função principal do Radix Sort
void radixSort(int array[], int size) {
    // Encontra o maior número para determinar o número de dígitos
    int max = getMax(array, size);

    // Executa o Counting Sort para cada dígito significativo (unidade, dezena, centena, etc.)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(array, size, exp);
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
        array[i] = rand() % 1000; // Números aleatórios entre 0 e 999
        printf("%d ", array[i]);
    }
    printf("\n");

    // Ordena o array usando Radix Sort
    radixSort(array, SIZE);

    // Imprime o array ordenado
    printf("\nVetor ordenado:\n");
    printArray(array, SIZE);

    return 0;
}
