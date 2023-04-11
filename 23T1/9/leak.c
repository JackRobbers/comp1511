#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("Type y to start allocating heaps of memory ");
    scanf(" ");
    printf("doing it\n");
    while (1) {
        void *memory = malloc(10000);
        // do something with the memory
        free(memory);
    }

}
