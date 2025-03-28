#include <stdio.h>

char board[3][3];
int playerTurn = 1;

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return playerTurn;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return playerTurn;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return playerTurn;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return playerTurn;
    return 0;
}

void makeMove() {
    int row, col;
    printf("Player %d, enter your move (row and column): ", playerTurn);
    scanf("%d %d", &row, &col);
    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
        printf("Invalid move! Try again.\n");
        makeMove();
    } else {
        board[row - 1][col - 1] = (playerTurn == 1) ? 'X' : 'O';
    }
}

int main() {
    initializeBoard();
    int winner = 0;
    int moves = 0;

    while (moves < 9 && !winner) {
        displayBoard();
        makeMove();
        moves++;
        winner = checkWinner();
        if (!winner) playerTurn = (playerTurn == 1) ? 2 : 1;
    }

    displayBoard();

    if (winner) {
        printf("Player %d wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
