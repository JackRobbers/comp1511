#include <stdio.h>

#define MAX_LETTERS 100

int main (void) {

    char my_str[MAX_LETTERS];
    // fgets returns NULL if nothing was scanned in (Ctrl+D)
    // Note to not use scanf for scanning strings
    while (fgets(my_str, MAX_LETTERS, stdin) != NULL) {
        printf("Input: %s", my_str);
    }

    return 0;
}