// Beecrowd | 2729 - Lista de Compras //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_LENGTH 21

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {
        char line[20000];
        fgets(line, sizeof(line), stdin);

        char *items[MAX_ITEMS];
        int item_count = 0;

        char *token = strtok(line, " \n");
        while (token != NULL) {
            items[item_count++] = token;
            token = strtok(NULL, " \n");
        }

        qsort(items, item_count, sizeof(char *), compare);

        printf("%s", items[0]);
        for (int j = 1; j < item_count; j++) {
            if (strcmp(items[j], items[j - 1]) != 0) {
                printf(" %s", items[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
