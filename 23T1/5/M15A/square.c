#include <stdio.h>

#define SIZE 5

void square(int x);
void square_array(int xs[SIZE]);
int square_return(int x);


int main(void) {
    printf("Enter a number: ");

    int num;
    scanf("%d", &num);

    int num_array[SIZE] = {1, 2, 3, 4, 5};

    num = square_return(num);
    square_array(num_array);
    printf("%d\n", num);

    int i = 0;
    while (i < SIZE) {
        printf("%d ", num_array[i]);
        i++;
    }
    printf("\n");

    return 0;
}

// take in a variable and square it
void square(int x) {
    x = x * x;
}

void square_array(int xs[SIZE]) {
    int i = 0;
    while (i < SIZE) {
        xs[i] = xs[i] * xs[i];
        i++;
    }
}

int square_return(int x) {
    return x * x;
}