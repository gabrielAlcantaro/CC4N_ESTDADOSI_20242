#include <stdio.h>

#define SIZE 50

// Função que realiza a intercalação de dois subarrays ordenados.
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamanho do primeiro subarray
    int n2 = right - mid;    // Tamanho do segundo subarray

    // Arrays temporários para armazenar os subarrays
    int leftArray[n1], rightArray[n2];

    // Copia os elementos para os arrays temporários
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    // Índices iniciais para os subarrays e o array principal
    int i = 0, j = 0, k = left;

    // Intercala os elementos nos subarrays de volta no array principal
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes do leftArray, se houver
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copia os elementos restantes do rightArray, se houver
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// Função recursiva para dividir o array e ordená-lo usando merge sort
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calcula o ponto médio do array

        // Chama mergeSort para a metade esquerda
        mergeSort(array, left, mid);

        // Chama mergeSort para a metade direita
        mergeSort(array, mid + 1, right);

        // Intercala as duas metades ordenadas
        merge(array, left, mid, right);
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

    // Ordena o array usando merge sort
    mergeSort(array, 0, SIZE - 1);

    // Imprime o array ordenado
    printf("\nVetor ordenado:\n");
    printArray(array, SIZE);

    return 0;
}
