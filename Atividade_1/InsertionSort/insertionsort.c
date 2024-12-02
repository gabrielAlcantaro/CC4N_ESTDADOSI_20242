#include <stdio.h>

// Função que implementa o algoritmo Insertion Sort
// Esta função ordena o vetor de forma crescente
void insertionSort(int arr[], int n) {
    int i, j, key;

    // O loop externo percorre cada elemento do vetor, começando do segundo
    for (i = 1; i < n; i++) {
        key = arr[i]; // Armazena o valor do elemento atual
        j = i - 1;    // Começa a comparar com os elementos à esquerda

        // O loop interno usando while para mover os elementos maiores que a chave (key)
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Move o elemento para a direita
            j--;                 // Continua movendo para a próxima posição à esquerda
        }

        // Insere a chave na posição correta
        arr[j + 1] = key;
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

    // Chama a função insertionSort para ordenar o vetor
    insertionSort(arr, n);

    printf("Vetor após a ordenação: \n");
    printArray(arr, n);

    return 0;
}
