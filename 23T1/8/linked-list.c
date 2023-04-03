// code for linked list, specifically append.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data);
void print_list(struct node *head);
struct node *append_to_list(struct node *head, int data);

int main(void) {
    // struct node *head = create_node(2);
    // struct node *five = create_node(5);
    // struct node *six = create_node(6);
    // struct node *ten = create_node(10);

    // head->next = five;
    // five->next = six;
    // six->next = ten;
    // ten->next = NULL;
    struct node *head = NULL;
    head = append_to_list(head, 2);
    append_to_list(head, 5);
    append_to_list(head, 6);
    append_to_list(head, 10);

    print_list(head);

    // insert a node with 7 between 5 and 6
    struct node *seven = create_node(7);
    seven->next = head->next->next;
    head->next->next = seven;

    print_list(head);

    // insert 8 at the end
    append_to_list(head, 8);

    append_to_list(head, 12);
    print_list(head);


    return 0;
}

// malloc a new list node with the given data and return it
struct node *create_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

// append to the end of any list
struct node *append_to_list(struct node *head, int data) {
    struct node *new = create_node(data);

    if (head == NULL) {
        head = new;
    } else {
        struct node *curr = head;
        // find the tail
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new;
    }
    
    return head;
}