#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data);
struct node *create_node_prepend(int data, struct node *next);
struct node *create_node_append(int data, struct node *head);
void print_list(struct node *head);

int main(void) {

    struct node *head = create_node(1);

    // create a node with data 5
    struct node *five = create_node(5);

    // join 1->5
    head->next = five;

    struct node *ten = create_node(10);

    five->next = ten;
    // create a node with data 3
    struct node *three = create_node(3);
    ten->next = three;

    three->next = NULL;

   
    print_list(head);
    
    // remove 5, but only using head.

    // head->next->next is 10
    struct node *next = head->next->next;
    
    // head->next is 5
    free(head->next);

    // we wouldn't be able to do this with storing next, because we can't do head->next->next
    head->next = next;

    print_list(head);

    struct node *head2 = create_node_prepend(9, create_node_prepend(6, create_node_prepend(3, NULL)));

    print_list(head2);

    struct node* head3 = create_node_append(1, NULL);

    int i = 0;
    while (i < 10) {
        create_node_append(i, head3);
        i++;
    }
   

    print_list(head3);
}

struct node *create_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    return new;
}

struct node *create_node_prepend(int data, struct node *next) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = next;
    return new;
}

// adds a node to the end of a list. if it's empty - the new node is the head
struct node *create_node_append(int data, struct node *head) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if (head == NULL) {
        return new;
    }

    // stops at the tail
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new;
    return head;
}

void print_list(struct node *head) {
    // like i = 0;
    struct node *current = head; 
    while (current != NULL) { // like i < SIZE
        printf("%d -> ", current->data);
        current = current->next; // like i++
    }
    printf("NULL\n");
}