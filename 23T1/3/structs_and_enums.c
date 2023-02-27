#include <stdio.h>

struct person {
    int shoe_size;
    double height;
    char first_name_initial;
    enum opal_card_type card;
};

enum opal_card_type {
    ADULT,
    STUDENT,
    CONCESSION
};

// create a struct person and return it.
struct person new_person(int shoe_size, double height, char first_name_initial);
void print_person(struct person to_print);

int main(void) {
    struct person jack = new_person(32, 172.0, 'j');

    struct person arpita = new_person(30, 200.0, 'a');

    print_person(jack);

    return 0;
}

struct person new_person(int shoe_size, double height, char first_name_initial) {
    // if (first_name_initial < 'a' || first_name_initial > 'z') {
    //     printf("invalid initial\n");
    //     // means there is no value, will cover this in more detail later
    //     return NULL;
    // }
    struct person new;
    new.shoe_size = shoe_size;
    new.height = height;
    new.first_name_initial = first_name_initial;
    new.card = STUDENT;
    return new;
}

void print_person(struct person to_print) {
    printf(
        "This persons height is %lf, shoe size is %d, and their first initial is %c\n", 
        to_print.height, 
        to_print.shoe_size, 
        to_print.first_name_initial
    );
}