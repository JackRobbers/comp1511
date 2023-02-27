// A program to explore division in C
// Jack Robbers z5263682


#include <stdio.h>

int main(void) {

    printf("Enter two integers: ");
    int a;
    int b;
    // works for any kind of whitespace seperating the numbers
    scanf("%d %d", &a, &b);

    if (b == 0) {
        printf("Error: Can't divide by 0\n");
    } else if (a > b) {
        printf("%d %lf\n", a / b, (a * 1.0) / b);   
    } else {
        // spec didn't cover but deciding for a == b to error
        printf("Error: we don't like smaller numbers\n");
    }
    return 0;
}