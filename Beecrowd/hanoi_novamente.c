// Beecrowd | 1166 - Torre de Hanoi, Novamente! //

#include <stdio.h>

#define MAX_BOLAS 51

int main() {
    int bolas[MAX_BOLAS];
    for (int i = 1; i < MAX_BOLAS; i++) {
        bolas[i] = ((i + 1) * (i + 1)) / 2 - 1;
    }
    
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", bolas[n]);
    }
    
    return 0;
}
