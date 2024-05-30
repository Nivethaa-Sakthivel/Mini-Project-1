#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

// Function to initialize the board
void initializeBoard(char* board) {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        *(board + i) = ' ';
    }
}

// Function to print the board
void printBoard(char* board) {
    printf("\n");
    printf(" %c | %c | %c\n", *(board), *(board + 1), *(board + 2));
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", *(board + 3), *(board + 4), *(board + 5));
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", *(board + 6), *(board + 7), *(board + 8));
    printf("\n");
}

// Function to check if the move is valid
int isValidMove(char* board, int position) {
    return (*(board + position) == ' ');
}

// Function to check if the game is over
int isGameOver(char* board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (*(board + i * BOARD_SIZE) != ' ' && *(board + i * BOARD_SIZE) == *(board + i * BOARD_SIZE + 1) && *(board + i * BOARD_SIZE) == *(board + i * BOARD_SIZE + 2)) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (*(board + i) != ' ' && *(board + i) == *(board + i + BOARD_SIZE) && *(board + i) == *(board + i + 2 * BOARD_SIZE)) {
            return 1;
        }
    }

    // Check diagonals
    if (*(board) != ' ' && *(board) == *(board + 4) && *(board) == *(board + 8)) {
        return 1;
    }
    if (*(board + 2) != ' ' && *(board + 2) == *(board + 4) && *(board + 2) == *(board + 6)) {
        return 1;
    }

    // Check for draw
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        if (*(board + i) == ' ') {
            return 0;
        }
    }

    return -1; // Game over, draw
}

// Function to make a move
void makeMove(char* board, int position, char symbol) {
    *(board + position) = symbol;
}

int main() {
    char board[BOARD_SIZE * BOARD_SIZE];
    char currentPlayer = 'X';
    int position;
    int gameOver = 0;

    // Initialize the board
    initializeBoard(board);

    printf("Welcome to Tic Tac Toe!\n");

    while (!gameOver) {
        printBoard(board);
        printf("Player %c, enter your move (0-8): ", currentPlayer);
        scanf("%d", &position);

        if (position < 0 || position > 8) {
            printf("Invalid move! Please enter a number between 0 and 8.\n");
            continue;
        }

        if (!isValidMove(board, position)) {
            printf("Invalid move! That position is already taken.\n");
            continue;
        }

        makeMove(board, position, currentPlayer);

        gameOver = isGameOver(board);

        if (gameOver == 1) {
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
        } else if (gameOver == -1) {
            printBoard(board);
            printf("It's a draw!\n");
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
