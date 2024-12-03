#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetor(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100000; 
    }
}

void insertionSort(int *vetor, int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void imprimirVetor(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); 

    int n = 10; 
    int vetor[n];

    gerarVetor(vetor, n);
    printf("Vetor original:\n");
    imprimirVetor(vetor, n);

    insertionSort(vetor, n);
    printf("\nVetor ordenado com InsertionSort:\n");
    imprimirVetor(vetor, n);

    return 0;
}
