// scan in 2 numbers and print out the result of their division, if possible
// jack

#include <stdio.h>

int main(void) {

    // don't need to give scanned variables a value
    int a;
    int b;
    scanf("%d %d", &a, &b);

    if (a <= b) {
        printf("small numbers aren't interesting\n");
    } else if (b == 0) {
        printf("division by 0!\n");
    } else {
        // can use else here for a > b, because 
        //we've covered all of the other cases
        printf("%d %lf\n", a / b, (a * 1.0) / (b * 1.0));
    }

    return 0;
}