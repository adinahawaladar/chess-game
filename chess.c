#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Representation of the chess board
char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the chess board
void init_board() {
    // Set up the initial positions of the pieces
    // For simplicity, let's represent pieces with their initial letters
    // 'P' for pawn, 'R' for rook, 'N' for knight, 'B' for bishop, 'Q' for queen, 'K' for king
    // Use lowercase for black pieces and uppercase for white pieces
    
    // Clear the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    
    // Set up pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }
    
    // Set up other pieces
    board[0][0] = board[0][7] = 'R';
    board[7][0] = board[7][7] = 'r';
    board[0][1] = board[0][6] = 'N';
    board[7][1] = board[7][6] = 'n';
    board[0][2] = board[0][5] = 'B';
    board[7][2] = board[7][5] = 'b';
    board[0][3] = 'Q';
    board[7][3] = 'q';
    board[0][4] = 'K';
    board[7][4] = 'k';
}

// Function to display the chess board
void display_board() {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("  a b c d e f g h\n\n");
}

// Function to convert chess coordinates to array indices
bool convert_input(char input[5], int *x, int *y) {
    if (input[0] >= 'a' && input[0] <= 'h' &&
        input[1] >= '1' && input[1] <= '8' &&
        input[2] == '-' &&
        input[3] >= 'a' && input[3] <= 'h' &&
        input[4] >= '1' && input[4] <= '8') {
        *x = 8 - (input[1] - '0');
        *y = input[0] - 'a';
        return true;
    }
    return false;
}

// Function to move a piece
bool move_piece(int from_x, int from_y, int to_x, int to_y) {
    // Add validation logic here
    // For now, we'll just move the piece without any checks
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = ' ';
    return true;
}

int main() {
    char input[5];
    int from_x, from_y, to_x, to_y;
    
    // Initialize the board
    init_board();
    
    // Display the board
    display_board();
    
    // Game loop
    while (true) {
        printf("Enter your move (e.g., e2-e4): ");
        scanf("%s", input);
        
        if (convert_input(input, &from_x, &from_y)) {
            scanf("%s", input + 3);
            if (convert_input(input + 3, &to_x, &to_y)) {
                if (move_piece(from_x, from_y, to_x, to_y)) {
                    display_board();
                } else {
                    printf("Invalid move!\n");
                }
            } else {
                printf("Invalid input format!\n");
            }
        } else {
            printf("Invalid input format!\n");
        }
    }
    
    return 0;
}
