#include <stdio.h>

int board[100][100], n;

// Function to print board in grid format
void printBoard() {
    int i, j;

    printf("\nSolution:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("+---");
        }
        printf("+\n");

        for(j = 0; j < n; j++) {
            if(board[i][j] == 1)
                printf("| Q ");
            else
                printf("|   ");
        }
        printf("|\n");
    }

    for(j = 0; j < n; j++) {
        printf("+---");
    }
    printf("+\n");
}

// Check safe position
int isSafe(int row, int col) {
    int i, j;

    for(i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return 0;
    }

    for(i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return 0;
    }

    for(i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

// Solve N Queen
int solveNQueen(int row) {
    int col;

    if(row == n)
        return 1;

    for(col = 0; col < n; col++) {
        if(isSafe(row, col)) {
            board[row][col] = 1;

            if(solveNQueen(row + 1))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if(solveNQueen(0))
        printBoard();
    else
        printf("No solution exists");

    return 0;
}
