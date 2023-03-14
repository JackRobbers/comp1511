#include <stdio.h>

#define SIZE 5

void square(int x);
int square_return(int x);
void square_array(int array[SIZE]);

int main(void) {
    printf("Please enter a number: ");

    int num;
    scanf("%d", &num);

    square(num);
    printf("%d %d\n", num, square_return(num));

    int xs[SIZE] = {1, 2, 3, 4, 5};
    square_array(xs);
    int i = 0;
    while (i < SIZE) {
        printf("%d ", xs[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}

void square(int x) {
    x = x * x;
}

int square_return(int x) {
    return x * x;
}

// square all the numbers in the array
// arrays get changed everywhere when you change them in a function
void square_array(int array[SIZE]) {
    int i = 0;
    while (i < SIZE) {
        array[i] = array[i] * array[i];
        i++;
    }
}