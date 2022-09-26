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
    font-size: 18px;
  }
---

# Tute 03
## COMP1511 22T3
### Jack Robbers

---

# content

* while loops
* enums and structs
* variable names

---

# 1D while loops

easiest to look at https://cgi.cse.unsw.edu.au/~cs1511/22T3/tut/03/questions

---

# 2D while loops

<div class="columns small">
<div>

```C
void a(void) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (row == col) {
                printf("O");
            } else {
                printf("X");

            }
            col++;
        }
        row++;
        printf("\n");
    }
}
```
	
```c
void b(void) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (col % 2 == 0) {
                printf("O");
            } else {
                printf("X");

            }
            col++;
        }
        row++;
        printf("\n");
    }
}
```

</div>
<div>

```c
void c(void) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (col != 1 && row != 1) {
                printf("O");
            } else {
                printf("X");

            }
            col++;
        }
        row++;
        printf("\n");
    }
}
```
	
```c
void d(void) {
    int row = 0;
    while (row < SIZE) {
        printf("X");
        int col = 1;
        while (col < 3) {
            if (row == 0 || row == 3) {
                printf("X");
            } else {
                printf("O");
            }
            col++;
        }
        printf("X");
        row++;
        printf("\n");
    }
}
```

</div>
</div>

---

<div class="columns">
<div>

```
OXXX
XOXX
XXOX
XXXO
```
```
OXOX
OXOX
OXOX
OXOX
```
</div>
<div>

```
OXOO
XXXX
OXOO
OXOO
```
```
XXXX
XOOX
XOOX
XXXX
```

</div>
</div>

---

# enums and structs

```C

struct person {
    int shoe_size;
    double height;
    char first_name_initial;
};

enum opal_card_type {
    ADULT,
    STUDENT,
    CONCESSION
};
```

---

# variable names

In your groups come up with at least 5 variable names of which some are:
* valid
* invalid
* bad style
* good style

