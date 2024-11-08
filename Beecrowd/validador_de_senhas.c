// Beecrowd | 2253 - Validador de Senhas //

#include <stdio.h>
#include <string.h>

int validarSenha(char senha[]) {
    int temMaiuscula = 0, temMinuscula = 0, temNumero = 0;

    int tamanho = strlen(senha);
    if (tamanho < 6 || tamanho > 32) {
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        char c = senha[i];
        
        if (c >= 'A' && c <= 'Z') {
            temMaiuscula = 1;
        }
        else if (c >= 'a' && c <= 'z') {
            temMinuscula = 1;
        }
        else if (c >= '0' && c <= '9') {
            temNumero = 1;
        }
        else {
            return 0;
        }
    }

    return (temMaiuscula && temMinuscula && temNumero);
}

int main() {
    char senha[100];

    while (fgets(senha, sizeof(senha), stdin)) {
        senha[strcspn(senha, "\n")] = '\0';

        if (validarSenha(senha)) {
            printf("Senha valida.\n");
        } else {
            printf("Senha invalida.\n");
        }
    }

    return 0;
}
