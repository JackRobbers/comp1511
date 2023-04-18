#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data, struct node *next);
struct node *reverse_list(struct node *head);
void print_list(struct node *head);

int main(void) {

    struct node *head = create_node(1, create_node(2, create_node(3, create_node(4, NULL))));
    print_list(head);
    head = reverse_list(head);
    print_list(head);
    return 0;
}

struct node *create_node(int data, struct node *next) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = next;
    return new;
}

// iterative solution 
/*
struct node *reverse_list(struct node *head) {

    struct node *prev = NULL;
    struct node *curr = head;

    while (curr != NULL) {
        struct node *next = curr->next;
        curr->next = prev;
        
        if (next == NULL) {
            head = curr;
        }

        prev = curr;
        curr = next;
    }
    return head;
}
*/

struct node *reverse_list(struct node *head) {
    if (head == NULL || head->next == NULL)  {
        return head;
    }

    struct node *new_head = reverse_list(head->next);

    head->next->next = head;
    head->next = NULL;
    return new_head;
}



void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}














































/*
struct node *reverse_list(struct node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct node *new = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return new;
}*/