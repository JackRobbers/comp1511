#include <stdio.h>

#define SIZE 9
#define FALSE 0
#define TRUE 1

enum tile_type {LILYPAD, BANK, WATER, TURTLE, LOG};

struct board_tile {
    enum tile_type type;
    int occupied;
};

void place_log(struct board_tile board[SIZE][SIZE]) {
    int row;
    int start_column;
    int end_column;

    scanf("%d %d %d", &row, &start_column, &end_column);

    if (row > 0 && row < SIZE - 1) {
        return
    }

    int turtles_in_row = FALSE;
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i].type == TURTLE) {
            turtles_in_row = TRUE;
        }
    }

    // guaranteed that start_column <= end_column so don't 
    // have to check start_column < SIZE && end_column > 0
    
    if (!turtles_in_row) {
        return;
    } 

    if (start_column < 0) {
        start_column = 0;
    }

    if (end_column >= SIZE) {
        end_column = SIZE;
    }

    for (int i = start_column; i < end_column; i++) {
        board[row][i].type = LOG;
    }
}