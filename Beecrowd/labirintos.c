// Beecrowd | 1076 - Desenhando Labirintos //

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Aresta;

bool aresta_existe(Aresta *arestas, int count, int x, int y) {
    for (int i = 0; i < count; i++) {
        if ((arestas[i].x == x && arestas[i].y == y) || (arestas[i].x == y && arestas[i].y == x)) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n, v, a;
        scanf("%d", &n);
        scanf("%d %d", &v, &a);
        
        Aresta *arestas = (Aresta *)malloc(a * sizeof(Aresta));
        int count = 0;
        
        for (int j = 0; j < a; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            
            if (!aresta_existe(arestas, count, x, y)) {
                arestas[count].x = x;
                arestas[count].y = y;
                count++;
            }
        }
        
        printf("%d\n", 2 * count);
        free(arestas);
    }
    
    return 0;
}
