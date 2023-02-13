// Program to do various linked list exercises
// Written by <your-name> (zID) on <date>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/** PRESCRIBED FUNCTIONS **/

struct node *add_last(struct node *head, int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    // Return new if linked list is initially empty
    if (head == NULL) {
        return new;
    }

    // Otherwise, loop to end of list and add node.
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;

    // We are inserting at the end --> head will not change
    return head;
}

void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

struct node *copy(struct node *list) {
    return NULL;
}

struct node *list_append(struct node *first_list, struct node *second_list) {
    return NULL;
}

int identical(struct node *first_list, struct node *second_list) {
    return 5841;
}

struct node *set_intersection(
    struct node *first_list,
    struct node *second_list
) {
    return NULL;
}
