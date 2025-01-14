// Beecrowd | 1855 - Mapa do Meistre //

#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_M 100

int n, m;
char a[MAX_N][MAX_M];
bool vis[MAX_N][MAX_M];

bool dfs(int x, int y, int dx, int dy) {
    if (x < 1 || x > m || y < 1 || y > n || vis[x][y]) {
        return false;
    }

    vis[x][y] = true;

    switch (a[x][y]) {
        case '*':
            return true;
        case '>':
            return dfs(x, y + 1, 0, 1);
        case '<':
            return dfs(x, y - 1, 0, -1);
        case '^':
            return dfs(x - 1, y, -1, 0);
        case 'v':
            return dfs(x + 1, y, 1, 0);
        default:
            return dfs(x + dx, y + dy, dx, dy);
    }
}

int main() {

    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= m; i++) {
        scanf("%s", a[i] + 1);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            vis[i][j] = false;
        }
    }

    if (dfs(1, 1, 0, 1)) {
        printf("*\n");
    } else {
        printf("!\n");
    }

    return 0;
}
