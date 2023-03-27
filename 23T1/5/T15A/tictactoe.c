#include <stdio.h>

#define SIZE 5

// Function Prototype
int did_player_win(char player, char board[SIZE][SIZE]);

int main(void) {
    char no_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', ' ', ' ', ' ', 'O'},
    };

    char x_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {' ', 'X', ' ', ' ', 'O'},
    };
    char o_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };
    char diagonal_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'O', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', ' ', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    if (did_player_win('X', x_wins_board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', x_wins_board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// Function Implementation:
// Determines whether a given player has won the game of tictactoe
// by getting SIZE tokens in a row, in any direction.
int did_player_win(char player, char board[SIZE][SIZE]) {
    int has_won = 0;

    // horizontally
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        int row_matches = 1;
        int col_matches = 1;
        while (col < SIZE) {
            if (board[row][col] != player) {
                row_matches = 0;
            }
            if (board[col][row] != player) {
                col_matches = 0;
            }
            col++;
        }
        if (row_matches == 1 || col_matches == 1) {
            has_won = 1;
        } 
        row++;
    }

    // diagonally
    int position = 0;
    
    int diagonal_positive_matches = 1;
    int diagonal_negative_matches = 1;
    while (position < SIZE) {
        if (board[position][position] != player) {
            diagonal_positive_matches = 0;
        }
        if (board[position][SIZE - position - 1]) {
            diagonal_negative_matches = 0;
        }
        position++;
    }

    if (diagonal_positive_matches == 1 || diagonal_negative_matches == 1) {
        has_won = 1;
    }

    return has_won;
}