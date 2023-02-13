#include <stdio.h>

#define SIZE 5

void square(int *x);
void square_and_cube(int *x, int *y);
void square_array(int array[SIZE]);

int main(void) {

    // int to_square = 10;
    // int to_cube = 5;
    // square_and_cube(&to_square, &to_cube);
    // printf("%d %d\n", to_square, to_cube);

    int squares[SIZE] = {1, 2, 3, 4, 5};
    square_array(squares);
    int i = 0;
    while (i < SIZE) {
        printf("%d\n", squares[i]);
        i++;
    }

    return 0;
}

void square(int *x) {
    *x = *x * *x;
}

void square_and_cube(int *x, int *y) {
    *x = *x * *x;
    *y = *y * *y * *y;
}

void square_array(int array[SIZE]) {
    for (int i = 0; i < SIZE; i ++) {
        array[i] = array[i] * array[i]; 
    }
}