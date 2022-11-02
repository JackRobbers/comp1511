#include <stdio.h>
#include <stdlib.h> // needed for malloc

struct node {   
    int data;
    struct node *next;
};

void print_list(struct node *head);

struct node *create_node(int data);

int main(void) {
    // create the 2 node
    struct node *head = create_node(2);

    // create the 5 node
    struct node *five = create_node(5);
    head->next = five;

    // create the 10 node
    struct node *ten = create_node(10);
    five->next = ten;

    // create the 3 node
    struct node *three = create_node(3);
    ten->next = three;
    three->next = NULL;

    print_list(head);

    // add another node before 2.

    struct node *seven = create_node(7);
    seven->next = head;
    head = seven;

    print_list(head);

    // remove 10;
    five->next = three;
    free(ten);

    print_list(head);

    // you would loop through and free everything here

    return 0;
}

void print_list(struct node *head) {
    struct node *current = head; // similar to i = 0;
    while (current != NULL) { // i < SIZE
        printf("%d -> ", current->data);
        current = current->next; // i++
    }
    printf("NULL\n");
}

struct node *create_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    return new;
}