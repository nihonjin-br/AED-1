#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetor(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100000; 
    }
}

int particionar(int *vetor, int esq, int dir) {
    int pivo = vetor[dir];
    int i = esq - 1;
    
    for (int j = esq; j < dir; j++) {
        if (vetor[j] <= pivo) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[dir];
    vetor[dir] = temp;
    
    return i + 1;
}

void quickSort(int *vetor, int esq, int dir) {
    if (esq < dir) {
        int p = particionar(vetor, esq, dir);
        quickSort(vetor, esq, p - 1);
        quickSort(vetor, p + 1, dir);
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

    quickSort(vetor, 0, n - 1);
    printf("\nVetor ordenado com QuickSort:\n");
    imprimirVetor(vetor, n);

    return 0;
}
