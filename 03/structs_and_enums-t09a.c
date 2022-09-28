#include <stdio.h>

struct person {
    int shoe_size;
    int age;
    double height;
    char first_name_initial;
    enum opal_card_type type;
};

enum opal_card_type {
    ADULT,
    STUDENT,
    CONCESSION
};

void print_person(struct person person) {
    printf("%c %d %lf\n", person.first_name_initial, person.shoe_size, person.height);
}

struct person create_person(int shoe_size, int height, char first_name_initial) {
    struct person new;
    new.shoe_size = shoe_size;
    new.height = height;
    new.first_name_initial = first_name_initial;
    new.type = STUDENT;
    return new;
}

int main(void) {
    
    struct person jack = create_person(10, 172.0, 'j');

    return 0;
}