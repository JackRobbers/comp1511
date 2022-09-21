---
marp: true
theme: uncover
paginate: true
---

# Tute 03
## COMP1511 22T3
### Jack Robbers

---

# content

* while loops
* enums and structs

---

# 1D while loops

---

# 2D while loops

---

# enums and structs

```C
#include <stdio.h>

enum position {
    laying_down,
    sitting,
    tummy_up
};

struct pet {
    double age;
    enum position body_position;
    int height_above_ground;
};
```