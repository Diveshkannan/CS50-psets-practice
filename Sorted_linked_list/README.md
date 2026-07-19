# Sorted Singly Linked List in C (Ascending & Descending)

## Overview

This project implements a **Sorted Singly Linked List** in C using dynamic memory allocation. Instead of inserting elements in the order they are entered, each new node is inserted into its correct position, ensuring that the linked list remains sorted throughout execution.

The same insertion algorithm can be used for both **ascending** and **descending** order by simply changing the comparison condition during insertion.

This project was built to strengthen my understanding of pointers, linked lists, dynamic memory allocation, and pointer manipulation without using arrays or built-in sorting algorithms.

---

## Features

* Written in C using structures and pointers
* Dynamic memory allocation using `malloc()`
* Maintains the linked list in sorted order during insertion
* Supports both **Ascending** and **Descending** ordering
* Handles insertion at:

  * Beginning of the list
  * Middle of the list
  * End of the list
* Traverses the linked list to display all elements
* Properly frees dynamically allocated memory
* Focuses on understanding data structures rather than using library functions

---

## Algorithm Concept

For every new element entered by the user:

1. Allocate memory for a new node.
2. Store the input value.
3. If the list is empty, make the new node the head.
4. Traverse the linked list to find the correct insertion position.
5. Insert the node by updating the required pointers.
6. Continue until all elements have been inserted.

Since every node is inserted into its correct position, the linked list remains sorted at all times.

---

## Ascending vs Descending

The algorithm remains identical for both versions.

Only the comparison operator changes.

### Ascending Order

Insert before the first node whose value is larger.

Example:

```text
10 → 20 → 30 → 40 → 50
```

### Descending Order

Insert before the first node whose value is smaller.

Example:

```text
50 → 40 → 30 → 20 → 10
```

This demonstrates how a small modification in comparison logic changes the ordering while the underlying linked list algorithm remains the same.

---

## Data Structure

Each node contains:

* An integer value (`number`)
* A pointer to the next node (`next`)

```c
typedef struct node
{
    int number;
    struct node *next;
} node;
```

---

## Example

### Input

```text
40
10
60
20
50
30
```

### Ascending Output

```text
10
20
30
40
50
60
```

### Descending Output

```text
60
50
40
30
20
10
```

---

## Time Complexity

* **Best Case:** O(n)
* **Worst Case:** O(n²)

Since each insertion may require traversing the linked list, the overall complexity for inserting **n** elements is quadratic in the worst case.

---

## Concepts Practiced

* Structures in C
* Pointers
* Dynamic memory allocation (`malloc`)
* Memory deallocation (`free`)
* Singly Linked Lists
* Sorted insertion algorithm
* Head insertion
* Middle insertion
* Tail insertion
* Linked list traversal
* Pointer manipulation
* Heap and stack memory interaction
* Algorithm design
* Edge-case handling

---

## Learning Outcomes

Through this project, I gained practical experience with:

* Designing linked list algorithms from scratch
* Maintaining sorted order during insertion
* Updating pointers without losing existing nodes
* Handling different insertion scenarios safely
* Debugging pointer-related logic through manual tracing
* Understanding how a small change in comparison logic can produce different sorting behaviors

---

## Author's Note

Built as part of my CS50 learning journey to deepen my understanding of linked lists and low-level memory management. Rather than sorting data after insertion, this project focuses on maintaining a sorted linked list through pointer manipulation alone. It reinforced the importance of algorithmic thinking, careful pointer updates, and systematic debugging while working with dynamic data structures in C.
