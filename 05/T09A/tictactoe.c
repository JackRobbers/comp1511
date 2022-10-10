#include <stdio.h>

#define SIZE 5

char did_player_win(char player, char board[SIZE][SIZE]);

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
        {'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    char board[SIZE][SIZE];
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            board[row][col] = diagonal_wins_board[row][col];
            col++;
        }
        row++;
    }

    if (did_player_win('X', board) == 'X') {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', board) == 'O') {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// returns the player who won, or a space.
char did_player_win(char player, char board[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        int is_horizontal = 1;
        int is_vertical = 1;

        while (col < SIZE - 1) {
            if (!(board[row][col] != ' ' && board[row][col + 1] == board[row][col])) {
                is_horizontal = 0;
            }
            if (!(board[col][row] != ' ' && board[col + 1][row] == board[col][row])) {
                is_vertical = 0;
            }
            col++;
        }

        if (is_horizontal == 1) {
            return board[row][0];
        }
        if (is_vertical == 1) {
            return board[0][row];
        }
        row++;
    }

    // diagonal
    int pos = 0;
    int is_diagonal_down_right = 1;
    int is_diagonal_up_right = 1;
    while (pos < SIZE - 1) {
        if (!(board[pos][pos] == board[pos + 1][pos + 1])) {
            is_diagonal_down_right = 0;
        }
        if (!(board[pos][SIZE - pos - 2] == board[pos][SIZE - pos - 1])) {
            is_diagonal_up_right = 0;
        }
        pos++;
    }

    if (is_diagonal_up_right == 1 || is_diagonal_down_right == 1) {
        return board[SIZE / 2][SIZE / 2];
    }   

    return ' ';
}