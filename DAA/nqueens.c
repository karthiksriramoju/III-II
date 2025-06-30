#include <stdio.h>
#include <stdlib.h>

int board[20], count = 0;

int place(int row, int col) {
    for (int i = 1; i < row; i++)
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    return 1;
}

void print(int n) {
    printf("\n\nSolution %d:\n", ++count);
    for (int i = 1; i <= n; i++) printf("\t%d", i);
    for (int i = 1; i <= n; i++) {
        printf("\n%d", i);
        for (int j = 1; j <= n; j++)
            printf("\t%c", board[i] == j ? 'Q' : '-');
    }
}

void queen(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (place(row, col)) {
            board[row] = col;
            if (row == n) print(n);
            else queen(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("N-Queens Problem\nEnter number of Queens: ");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}
