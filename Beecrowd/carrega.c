// Beecrowd | 1026 - Carrega ou não Carrega? //

#include <stdio.h>

int main(){
    long long int a, b;

    while(scanf("%lld %lld", &a, &b) != EOF){
        printf("%lld\n", a ^ b);
    }

    return 0;
}
