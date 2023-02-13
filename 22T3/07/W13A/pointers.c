#include <stdio.h>

int main(void) {

    // Create an int variable
    int var = 2;

    // Create an int pointer
    int *ptr;

    // Getting the address of a variable
    ptr = &var;

    // Accessing memory via a pointer
    // 1. Print the value that is stored at where the pointer is pointing at
    printf("The value of var is: %d\n", *ptr);

    // 2. Change the value that is stored at where the pointer is pointing at
    *ptr = 5;

    // 3. Print the value that is stored at where the pointer is pointing at
    printf("The value of var is: %d\n", var);

    return 0;
}