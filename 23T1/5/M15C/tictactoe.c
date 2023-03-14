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
    // second_row = no_wins_board[2] // {' ', 'X', 'O', ' ', ' '}
    // second_row[4] // ' '
    // no_wins_board[2][4]

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
        {'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    if (did_player_win('X', diagonal_wins_board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', diagonal_wins_board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// Function Implementation:
// Determines whether a given player has won the game of tictactoe
// by getting SIZE tokens in a row, in any direction.
// return 1 if the given player wins, 0 otherwise
int did_player_win(char player, char board[SIZE][SIZE]) {
    int has_won = 0;

    // have they won horizontally
    int row = 0;
    int col;
    while (row < SIZE) {
        col = 0;
        int cell_matches_player = 1;
        while (col < SIZE) {
            if (board[row][col] != player) {
                cell_matches_player = 0;
            }
            col++;
        }
        if (cell_matches_player == 1) {
            has_won = 1;
        }
        row++;
    }

    // have they won vertically
    col = 0;
    while (col < SIZE) {
        row = 0;
        int cell_matches_player = 1;
        while (row < SIZE) {
            if (board[row][col] != player) {
                cell_matches_player = 0;
            }
            row++;
        }
        if (cell_matches_player == 1) {
            has_won = 1;
        }
        col++;
    }

    // have they won diagonally
    int pos = 0;
    int cell_matches_player_positive = 1;
    int cell_matches_player_negative = 1;
    while (pos < SIZE) {
        if (board[pos][pos] != player) {
            cell_matches_player_positive = 0;
        }
        if (board[pos][SIZE - pos - 1] != player) {
            cell_matches_player_negative = 0;
        }
        pos++;
    }

    if (cell_matches_player_positive == 1 || cell_matches_player_negative == 1) {
        has_won = 1;
    }

    return has_won;
}