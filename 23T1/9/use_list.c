#include "list.h"
#include <stdlib.h>

int main(void) {
    struct node *head = add_last(NULL, 1);
    print_list(head);
}