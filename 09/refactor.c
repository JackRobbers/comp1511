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

    int turtles_in_row = FALSE;
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i].type == TURTLE) {
            turtles_in_row = 1;
        }
    }

    // guaranteed that start_column <= end_column so don't 
    // have to check start_column < SIZE && end_column > 0

    // this code would pass 1511 style, but isn't good style
    // how would you fix the style here?
    // (there's also a bug, can you spot it?)
    if (!turtles_in_row 
        && row > 0 
        && row < SIZE - 1 
        && start_column >= 0 
        && end_column < SIZE
    ) {
        for (int i = start_column; i < end_column; i++) {
            board[row][i].type = LOG;
        }
    } else if (!turtles_in_row 
        && row > 0 
        && row < SIZE - 1
        && start_column >= 0 
        && end_column >= SIZE
    ) { 
        end_column = SIZE - 1;
        for (int i = start_column; i < end_column; i++) {
            board[row][i].type = LOG;
        }
    } else if (!turtles_in_row 
        && row > 0 
        && row < SIZE - 1
        && start_column < 0 
        && end_column < SIZE
    ) { 
        start_column = 0;
        for (int i = start_column; i < end_column; i++) {
            board[row][i].type = LOG;
        }
    }
}