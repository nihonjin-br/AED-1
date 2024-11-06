#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);  
    getchar();  

    for (int i = 0; i < n; i++) {
        char texto[51];
        int s;

        fgets(texto, sizeof(texto), stdin);
        texto[strcspn(texto, "\n")] = '\0'; 

        scanf("%d", &s);
        getchar();  

        for (int j = 0; j < strlen(texto); j++) {
            if (texto[j] >= 'A' && texto[j] <= 'Z') {
                texto[j] = ((texto[j] - 'A' - s + 26) % 26) + 'A';
            }
        }

        printf("%s\n", texto);
    }

    return 0;
}
