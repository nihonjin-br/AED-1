// Beecrowd | 1548 - Fila do Recreio // 

#include <stdio.h>

void ordenar_decrescente(int lista[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (lista[i] < lista[j]) {
                int temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); 

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);

        int notas_original[m]; 
        int notas_ordenadas[m]; 

        for (int j = 0; j < m; j++) {
            scanf("%d", &notas_original[j]); 
            notas_ordenadas[j] = notas_original[j]; 
        }

        ordenar_decrescente(notas_ordenadas, m);

        int alunos_sem_troca = 0;
        
        for (int j = 0; j < m; j++) {
            if (notas_original[j] == notas_ordenadas[j]) {
                alunos_sem_troca++;
            }
        }

        printf("%d\n", alunos_sem_troca); 
    }

    return 0;
}
