// Beecrowd | 1088 - Bolhas e Baldes //

#include <stdio.h>
#include <stdlib.h>

int mesclar_e_contar(int arr[], int temp[], int esquerda, int meio, int direita) {
    int i = esquerda; // Índice inicial para a primeira metade
    int j = meio + 1; // Índice inicial para a segunda metade
    int k = esquerda; // Índice para armazenar no array temporariamente
    int inversoes = 0;

    while (i <= meio && j <= direita) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversoes += (meio - i + 1); 
        }
    }

    while (i <= meio) {
        temp[k++] = arr[i++];
    }

    while (j <= direita) {
        temp[k++] = arr[j++];
    }

    for (i = esquerda; i <= direita; i++) {
        arr[i] = temp[i];
    }

    return inversoes;
}

int contar_inversoes_ordenando(int arr[], int temp[], int esquerda, int direita) {
    int inversoes = 0;
    if (esquerda < direita) {
        int meio = (esquerda + direita) / 2;

        inversoes += contar_inversoes_ordenando(arr, temp, esquerda, meio);
        inversoes += contar_inversoes_ordenando(arr, temp, meio + 1, direita);
        inversoes += mesclar_e_contar(arr, temp, esquerda, meio, direita);
    }
    return inversoes;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);

        if (n == 0) {
            break; 
        }

        int arr[n];
        int temp[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int inversoes = contar_inversoes_ordenando(arr, temp, 0, n - 1);

        if (inversoes % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
    }

    return 0;
}
