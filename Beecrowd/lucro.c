// Beecrowd | 1310 - Lucro //

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lucro_maximo(int n, int custo_dia, int receitas[]) {
    int max_atual = 0, max_total = 0;
    for (int i = 0; i < n; i++) {
        max_atual = max(0, max_atual) + receitas[i] - custo_dia;
        if (max_atual > max_total) {
            max_total = max_atual;
        }
    }
    return max_total;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n > 0) { 
        int custo_dia;
        scanf("%d", &custo_dia);
        
        int receitas[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &receitas[i]);
        }
        
        int resultado = lucro_maximo(n, custo_dia, receitas);
        printf("%d\n", resultado);
    }
    return 0;
}
