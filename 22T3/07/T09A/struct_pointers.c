#include <string.h>
#include <stdio.h>
// for malloc
#include <stdlib.h>

#define SIZE 100

struct person {
    char name[SIZE];
    int age;
};

void clone_person(struct person original, struct person *clone) {
    clone = &original;
}

struct person *clone_person_2(struct person original) {
    struct person *new = malloc(sizeof(struct person));
    new->age = original.age;
    strcpy(new->name, original.name);
    return new;
}

struct person clone_person_3(struct person original) {
    struct person new;
    new.age = original.age;
    strcpy(new.name, original.name);
    return new;
}

int main(void) {
    struct person william;
    strcpy(william.name, "william");
    william.age = 22;

    struct person jack;
    strcpy(jack.name, "jack");
    jack.age = 55;
    
    clone_person(&william, &jack);

    william.name[0] = 'b';
    william.age = 25;
    printf("result of clone: %s %d\n", jack.name, jack.age);

    struct person *anosua = clone_person_2(william);
    printf("result of clone: %s %d\n", anosua->name, anosua->age);

    struct person luca = clone_person_3(william);
    printf("result of clone: %s %d\n", luca.name, luca.age);
    return 0;
}