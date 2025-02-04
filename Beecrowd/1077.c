// Beecrowd | 1077 - Infixa para Posfixa //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, char c) {
    if (!estaCheia(p)) {
        p->dados[++p->topo] = c;
    }
}

char desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        return p->dados[p->topo--];
    }
    return '\0';
}

char topo(Pilha *p) {
    if (!estaVazia(p)) {
        return p->dados[p->topo];
    }
    return '\0';
}

int precedencia(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int ehAlfanumerico(char c) {
    
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

void infixaParaPosfixa(char *exp) {
    Pilha pilha;
    inicializar(&pilha);
    char saida[MAX] = "";
    int i, k = 0;

    for (i = 0; exp[i]; i++) {
        if (ehAlfanumerico(exp[i])) {
            saida[k++] = exp[i];
        } else if (exp[i] == '(') {
            empilhar(&pilha, exp[i]);
        } else if (exp[i] == ')') {
            while (!estaVazia(&pilha) && topo(&pilha) != '(') {
                saida[k++] = desempilhar(&pilha);
            }
            desempilhar(&pilha);  // remove '(' da pilha
        } else if (ehOperador(exp[i])) {
            while (!estaVazia(&pilha) && precedencia(topo(&pilha)) >= precedencia(exp[i])) {
                saida[k++] = desempilhar(&pilha);
            }
            empilhar(&pilha, exp[i]);
        }
    }

    while (!estaVazia(&pilha)) {
        saida[k++] = desempilhar(&pilha);
    }

    saida[k] = '\0';
    printf("%s\n", saida);
}

int main() {
    int n;
    scanf("%d", &n);
    char expressao[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%s", expressao);
        infixaParaPosfixa(expressao);
    }

    return 0;
}
