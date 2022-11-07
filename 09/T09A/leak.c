#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("Type y to start allocating heaps of memory ");
    scanf(" ");
    printf("doing it\n");
    int i = 0;
    while (i < 10) {
        
        malloc(10000);
        i++;
    }
}

