---
marp: true
theme: uncover
paginate: true
style: |
  .columns {
    display: grid;
    grid-template-columns: repeat(2, minmax(0, 1fr));
    gap: 1rem;
  }
  .small {
    font-size: 15px;
  }
  .code-small {
    font-size: 25px;
  }
---

# Tute 07
## COMP1511 22T3
### Jack Robbers

---

# content

* pointers
* scanning in a loop (again)

---

# assignment 1

* what did we learn
* any tips to yourself or others

---

# pointers

recap

---

* declaration: `type *ptr`
* referencing: `ptr = &variable`
* accessing/deferencing: `*ptr`
* `struct_ptr->field` is equivalent to `(*struct_ptr).field`    

the `*` is used both to indicate the type is a pointer and for derefere ncing (and multiplication as well!)

---

# pointers

exercise on tute page

https://cgi.cse.unsw.edu.au/~cs1511/22T3/tut/07/questions

---

# pointers live-coding

```c
struct person {
    char character_name[100];
    int num;
};

// copies the values from one person to another
void clone_person(struct person original, struct person clone) {
}
```

---

# scanning in loops

```c
// this code scans character by character
// how would it be different for line by line?

#include <stdio.h>

#define MAX_LETTERS 100

int main (void) {
    char my_var;
    while (scanf(" %c", &my_var) == 1) {
        printf("Input: %c\n", my_var);
    }

    return 0;
}
```