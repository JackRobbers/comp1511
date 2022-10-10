#include <stdio.h>

// Manually prints out a string, one character at a time.
// Should behave like printf("%s\n");
void print_string(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        printf("%c", string[i]);
        i++;
    }
    printf("\n");
}

int main (void) {
    // char my_string[] =  "Many chars";
    char *my_string =  "Many chars";

    // char argv[][]
    // char *argv[]
    // char **argv

    // my_string[0] == 'M'
    // my_string[8] == 'r'
    // my_string[10] == '\0'
    // my_string[11] -- array out of bounds error / random stuff
    printf("%s\n", my_string);
    print_string(my_string);
    return 0;
}