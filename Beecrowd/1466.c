// Beecrowd | 1466 - Percurso em Árvore por Nível //

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
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

void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    Node* queue[500];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* currentNode = queue[front++];
        printf("%d", currentNode->value);

        if (currentNode->left != NULL) {
            queue[rear++] = currentNode->left;
        }
        if (currentNode->right != NULL) {
            queue[rear++] = currentNode->right;
        }

        if (front < rear) {
            printf(" ");
        }
    }
    printf("\n");
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
        levelOrderTraversal(root);
        printf("\n");
    }

    return 0;
}
