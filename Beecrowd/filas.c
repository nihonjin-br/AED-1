// Beecrowd | 2460 - Fila //

#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 50000

int main() {
    int N, M;
    int fila_inicial[MAX_PESSOAS];
    int fila_final[MAX_PESSOAS];
    int saiu[MAX_PESSOAS];
    int i, j, id;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &fila_inicial[i]);
    }

    scanf("%d", &M);

    for (i = 0; i < M; i++) {
        scanf("%d", &saiu[i]);
    }

    int contagem_final = 0;
    for (i = 0; i < N; i++) {
        int esta_na_fila = 1;  
        for (j = 0; j < M; j++) {
            if (fila_inicial[i] == saiu[j]) {
                esta_na_fila = 0;  
                break;
            }
        }
        if (esta_na_fila) {
            fila_final[contagem_final++] = fila_inicial[i];
        }
    }

    for (i = 0; i < contagem_final; i++) {
        printf("%d", fila_final[i]);
        if (i < contagem_final - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
