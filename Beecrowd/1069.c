// Beecrowd | 1069 - Diamantes e Areia //

#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 1000

int contar_diamantes(char *sequencia) {
    int diamantes = 0;
    int pilha = 0;

    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (sequencia[i] == '<') {
            pilha++;  
        } else if (sequencia[i] == '>' && pilha > 0) {
            diamantes++;
            pilha--;  
        }
    }
    return diamantes;
}

int main() {
    int N;
    char sequencia[MAX_TAMANHO + 1];

    scanf("%d", &N);
    getchar();  

    for (int i = 0; i < N; i++) {
        fgets(sequencia, sizeof(sequencia), stdin);

        sequencia[strcspn(sequencia, "\n")] = '\0';

        int resultado = contar_diamantes(sequencia);
        printf("%d\n", resultado);
    }

    return 0;
}
