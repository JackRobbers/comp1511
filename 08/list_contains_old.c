#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STRING_SIZE 1024
#define MAX_STRINGS 50

struct node {
    struct node *next;
    char         data[MAX_STRING_SIZE];
};

int contains(char *value, struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main() {
    // Need to read in a number of ints into an array
    printf("How many strings in initial list?: ");
    int list_size = 0;
    scanf("%d", &list_size);
    char *initial_elems[MAX_STRING_SIZE] = {0};
    // Allocate enough space for n strings
    int i = 0;
    while (i < list_size) {
        initial_elems[i] = malloc(sizeof(char) * MAX_STRING_SIZE);
        i++;
    }

    // Read in n strings
    int n_read = 0;
    while (n_read < list_size && scanf("%s", initial_elems[n_read])) {
        n_read++;
    }

    printf("Enter word to check contained: ");

    // Read in word to check that contained inside
    char value[MAX_STRING_SIZE];
    scanf("%s", value);

    // Remove new line if added
    int len = strlen(value);
    if (value[len - 1] == '\n') {
        value[len - 1] = '\0';
    }

    // create linked list from inputs
    struct node *head = NULL;
    if (list_size > 0) {
        // list has elements
        head = strings_to_list(list_size, initial_elems);
    }

    int result = contains(value, head);
    printf("%d\n", result);

    return 0;
}



// Return 1 if value occurs in linked list, 0 otherwise
int contains(char *value, struct node *head) {
    return 42
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        strcpy(n->data, strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

