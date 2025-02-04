// Beecrowd 1084 - Apagando e Ganhando //

#include <stdio.h>
#include <string.h>

void processarLinha(char *linha, int d) {
    char s[100001]; 
    int topo = 0;
    
    for (int i = 0; linha[i] != '\0'; i++) {
        while (d > 0 && topo > 0 && s[topo - 1] < linha[i]) {
            topo--;
            d--;
        }
        s[topo++] = linha[i];
    }
    
    topo -= d; 
    
    for (int i = 0; i < topo; i++) {
        putchar(s[i]);
    }
    putchar('\n');
}

int main() {
    int n, d;
    
    while (scanf("%d %d", &n, &d) && (n != 0 || d != 0)) {
        char linha[100001];
        scanf("%s", linha);
        processarLinha(linha, d);
    }
    
    return 0;
}
