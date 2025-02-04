// Beecrowd | 1905 - Polícia e Ladrão //

#include <stdio.h>
#include <stdbool.h>

int vizinhos(int n, int resultado[]) {
    int count = 0;
    resultado[count++] = n + 5;
    if (n % 5 != 0) {
        resultado[count++] = n + 1;
    }
    if (n % 5 != 1) {
        resultado[count++] = n - 1;
    }
    resultado[count++] = n - 5;
    return count;
}

bool policia(char labirinto[], int caminho[], int caminho_len) {
    if (caminho[0] == 25) {
        return true;
    } else {
        int proximos[4];
        int prox_count = vizinhos(caminho[0], proximos);
        for (int i = 0; i < prox_count; i++) {
            if (labirinto[proximos[i] - 1] == '0') {
                bool presente = false;
                for (int j = 0; j < caminho_len; j++) {
                    if (caminho[j] == proximos[i]) {
                        presente = true;
                        break;
                    }
                }
                if (!presente) {
                    int novo_caminho[caminho_len + 1];
                    novo_caminho[0] = proximos[i];
                    for (int k = 0; k < caminho_len; k++) {
                        novo_caminho[k + 1] = caminho[k];
                    }
                    if (policia(labirinto, novo_caminho, caminho_len + 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}

void leia_labirinto(char labirinto[]) {
    int index = 0;
    while (index < 25) {
        char entrada[6];
        fgets(entrada, 6, stdin);
        for (int i = 0; entrada[i] != '\0' && index < 25; i++) {
            if (entrada[i] == '1' || entrada[i] == '0') {
                labirinto[index++] = entrada[i];
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char labirinto[25];
        leia_labirinto(labirinto);
        int caminho[1] = {-4};
        if (policia(labirinto, caminho, 1)) {
            printf("COPS\n");
        } else {
            printf("ROBBERS\n");
        }
    }
    return 0;
}
