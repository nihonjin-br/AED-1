// Beecrowd | 1195 - Árvore Binária de Busca //

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void prefixTraversal(Node* root) {
    if (root != NULL) {
        printf(" %d", root->value);
        prefixTraversal(root->left);
        prefixTraversal(root->right);
    }
}

void infixTraversal(Node* root) {
    if (root != NULL) {
        infixTraversal(root->left);
        printf(" %d", root->value);
        infixTraversal(root->right);
    }
}

void postfixTraversal(Node* root) {
    if (root != NULL) {
        postfixTraversal(root->left);
        postfixTraversal(root->right);
        printf(" %d", root->value);
    }
}

int main() {
    int C, N, value;
    scanf("%d", &C); 

    for (int caseNumber = 1; caseNumber <= C; caseNumber++) {
        scanf("%d", &N); 

        Node* root = NULL; 

        for (int i = 0; i < N; i++) {
            scanf("%d", &value);
            root = insert(root, value);
        }

        printf("Case %d:\n", caseNumber);

        printf("Pre.:");
        prefixTraversal(root);
        printf("\n");

        printf("In..:");
        infixTraversal(root);
        printf("\n");

        printf("Post:");
        postfixTraversal(root);
        printf("\n");

        printf("\n");
    }

    return 0;
}
