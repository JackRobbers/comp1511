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

# Tute 08
## COMP1511 22T3
### Jack Robbers

---

# content

* malloc
* linked lists

---

# malloc

what would you write to malloc the following: 

* an `int`
* a `char`
* an `int` array of size 5

---

# malloc summary

* allocates memory, that is persistent (unlike normal variables which are thrown away when a function ends)
* the parameter is how many bytes you want (sizeof is useful here!)
* since how much memory you get is dynamic, it's useful when you don't know how big something is when writing the program.
* returns a pointer to the memory

---

# linked lists

sequential data that must be accessed sequentially

---

# linked list activity



---
# linked list tips 
#### 3 positions to think about

* at the start
* in the middle
* at the end

#### 3 lengths of list to think about

* the empty list
* a list with 1 element
* a list with many (> 1) elements

