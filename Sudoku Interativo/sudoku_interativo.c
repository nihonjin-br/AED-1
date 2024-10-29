#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

// Função para imprimir o tabuleiro
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                printf(". ");
            else
                printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Verifica se um número pode ser colocado na posição (row, col) de acordo com as regras do Sudoku
int isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return 0;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return 0;
    return 1;
}

// Resolve o tabuleiro de Sudoku
int solveSudoku(int board[SIZE][SIZE]) {
    int row, col, found = 0;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (!found)
        return 1; // Tabuleiro completamente preenchido e válido

    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board))
                return 1;
            board[row][col] = 0; // Backtracking
        }
    }
    return 0;
}

// Gera um tabuleiro completo de Sudoku
void generateFullBoard(int board[SIZE][SIZE]) {
    solveSudoku(board); // Preenche um tabuleiro com uma solução completa de Sudoku
}

// Remove valores para criar um desafio, mantendo solucionabilidade única
void createPuzzle(int board[SIZE][SIZE]) {
    int attempts = 20;
    while (attempts > 0) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        if (board[row][col] != 0) {
            int backup = board[row][col];
            board[row][col] = 0;

            int boardCopy[SIZE][SIZE];
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    boardCopy[i][j] = board[i][j];

            if (!solveSudoku(boardCopy))
                board[row][col] = backup;
            else
                attempts--;
        }
    }
}

// Permite que o usuário insira números no tabuleiro
void playGame(int board[SIZE][SIZE]) {
    int row, col, num;
    while (1) {
        printBoard(board);
        printf("Digite a linha (0-8), coluna (0-8) e o número (1-9) para inserir (ou -1 para sair): ");
        scanf("%d", &row);
        if (row == -1) break; // Encerra o jogo

        scanf("%d %d", &col, &num);

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && num >= 1 && num <= SIZE) {
            if (board[row][col] == 0 && isSafe(board, row, col, num)) {
                board[row][col] = num;
                printf("Número %d inserido na posição (%d, %d)\n", num, row, col);
            } else {
                printf("Posição inválida ou número já inserido!\n");
            }
        } else {
            printf("Entrada inválida!\n");
        }
    }
}

int main() {
    srand(time(0));

    int board[SIZE][SIZE] = {0}; // Tabuleiro vazio
    generateFullBoard(board);     // Gera um tabuleiro completo
    createPuzzle(board);          // Cria o puzzle removendo números

    printf("Bem-vindo ao Sudoku! Complete o tabuleiro.\n");
    playGame(board);

    return 0;
}
