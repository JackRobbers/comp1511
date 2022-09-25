// compare integer and double division

#include <stdio.h>

int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);

    if (a < b) {
        printf("a < b\n");
    } else if (b == 0) {
        printf("watch out for division by 0\n");
    } else {
        printf("%d %lf", a/ b, (a *1.0) / (b * 1.0));
    }

    return 0;
}