struct node *copy(struct node *old_head) {
    if (old_head == NULL) {
        return NULL;
    }
    struct node *new_head = create_node(old_head->data);

    // new_prev keeps track of the previous node before the new one
    struct node *new_prev = new_head;
    // old_curr keeps track of the data from the old linked list we want to copy
    struct node *old_curr = old_head->next;

    while (old_curr != NULL) {
        struct node *new = create_node(old_curr->data);
        new_prev->next = new;
        new_prev = new_prev->next;
        old_curr = old_curr->next;
    }

    return new_head;
}

struct node *list_append(struct node *first_list, struct node *second_list) {
    if (first_list == NULL) {
        return copy(second_list);
    }

    struct node *first_copy = copy(first_list);
    struct node *second_copy = copy(second_list);
    
    struct node *curr = first_copy;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = second_copy;

    return first_copy;
}

int identical(struct node *first_list, struct node *second_list) {
    struct node *first_curr = first_list;
    struct node *second_curr = second_list;

    while (first_curr != NULL && second_curr != NULL) {
        if (first_curr->data != second_curr->data) {
            return NOT_IDENTICAL;
        }
        first_curr = first_curr->next;
        second_curr = second_curr->next;
    }

    if (first_curr != NULL || second_curr != NULL) {
        return NOT_IDENTICAL;
    }

    return IDENTICAL;
}

// given two lists in strictly increasing order,
// return a new linked list (in strictly increasing order) of the elements
// in both set1 and set2
struct node *set_intersection(struct node *first_list, struct node *second_list) {
    struct node *head = NULL;

    // Loop through both lists at the same time.
    // We're not going to be at exactly the same place
    // in both lists, we might move asymetrically
    // based on which numbers are higher in which list.
    struct node *first_curr = first_list;
    struct node *second_curr = second_list;
    // We don't need to check if either is NULL because that means there are extra
    // hanging elements which aren't a part of either.
    while (first_curr != NULL && second_curr != NULL) {
        if (first_curr->data < second_curr->data) {
            // Since the data from the first list is less than the data from
            // the second list, we need to move it along
            first_curr = first_curr->next;
        } else if (second_curr->data < first_curr->data) {
            // Since the data from the second list is less than the data from
            // the first list, we need to move it along
            second_curr = second_curr->next;
        } else {
            // The last case is if both first_curr and second_curr hold the same
            // data which is when we add it and then increment them both
            head = add_last(head, first_curr->data);
            first_curr = first_curr->next;
            second_curr = second_curr->next;
        }
    }

    return head;
}
