// Beecrowd | 1259 - Pares e Ímpares //

#include <stdio.h>
#include <stdlib.h>

int compararPares(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compararImpares(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int pares[n], impares[n];
    int contPares = 0, contImpares = 0;

    for (int i = 0; i < n; i++) {
        int valor;
        scanf("%d", &valor);

        if (valor % 2 == 0) {
            pares[contPares++] = valor;
        } else {
            impares[contImpares++] = valor;
        }
    }

    qsort(pares, contPares, sizeof(int), compararPares);

    qsort(impares, contImpares, sizeof(int), compararImpares);

    for (int i = 0; i < contPares; i++) {
        printf("%d\n", pares[i]);
    }

    for (int i = 0; i < contImpares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
