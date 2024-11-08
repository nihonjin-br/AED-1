// Beecrowd | 1022 - TDA Racional //

#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

void simplificar(int *numerador, int *denominador) {
    int divisor = mdc(*numerador, *denominador);
    *numerador /= divisor;
    *denominador /= divisor;

    if (*denominador < 0) {
        *numerador = -*numerador;
        *denominador = -*denominador;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int n1, d1, n2, d2;
        char operador;
        scanf("%d / %d %c %d / %d", &n1, &d1, &operador, &n2, &d2);

        int numerador, denominador;

        if (operador == '+') {
            numerador = n1 * d2 + n2 * d1;
            denominador = d1 * d2;
        } else if (operador == '-') {
            numerador = n1 * d2 - n2 * d1;
            denominador = d1 * d2;
        } else if (operador == '*') {
            numerador = n1 * n2;
            denominador = d1 * d2;
        } else if (operador == '/') {
            numerador = n1 * d2;
            denominador = d1 * n2;
        }

        int numOriginal = numerador;
        int denOriginal = denominador;

        simplificar(&numerador, &denominador);

        printf("%d/%d = %d/%d\n", numOriginal, denOriginal, numerador, denominador);
    }

    return 0;
}
