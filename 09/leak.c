#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("Press enter to start allocating heaps of memory ");
    scanf(" ");
    while (1) {
        malloc(10000);
    }
}