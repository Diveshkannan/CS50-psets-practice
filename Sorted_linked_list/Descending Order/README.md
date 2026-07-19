# Sorted Singly Linked List in C (Descending Order)

## Overview

This project implements a **Sorted Singly Linked List** in C using dynamic memory allocation. Instead of storing elements in the order they are entered, each new node is inserted directly into its correct position, ensuring that the linked list remains sorted in **descending order** throughout execution.

The project focuses on understanding linked list operations, pointer manipulation, dynamic memory management, and algorithmic thinking without using built-in sorting algorithms.

---

## Features

* Written in C using structures and pointers
* Dynamic memory allocation using `malloc()`
* Maintains the linked list in descending order during insertion
* Handles insertion at:

  * Beginning of the list
  * Middle of the list
  * End of the list
* Traverses the linked list to display the sorted elements
* Properly releases allocated memory using `free()`
* Beginner-friendly implementation emphasizing core data structure concepts

---

## Algorithm Concept

For every element entered by the user:

1. Allocate memory for a new node.
2. Store the input value.
3. If the linked list is empty, make the new node the head.
4. Otherwise, traverse the linked list to locate the correct insertion point.
5. Insert the new node before the first node containing a smaller value.
6. Continue until all elements have been inserted.

Because every node is inserted into its correct position immediately, the linked list remains sorted in descending order throughout the program.

---

## Data Structure

Each node consists of:

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

### Output

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

Each insertion may require traversing part or all of the linked list to determine the correct insertion position, resulting in quadratic time complexity in the worst case.

---

## Concepts Practiced

* Structures in C
* Pointers
* Dynamic memory allocation (`malloc`)
* Memory deallocation (`free`)
* Singly Linked Lists
* Sorted insertion
* Head insertion
* Middle insertion
* Tail insertion
* Linked list traversal
* Pointer manipulation
* Heap and stack memory concepts
* Algorithm design
* Edge-case handling

---

## Learning Outcomes

Through this project, I gained practical experience with:

* Building a linked list using dynamic memory allocation.
* Maintaining descending order through insertion instead of sorting after input.
* Updating pointers safely when inserting at the beginning, middle, or end of the list.
* Traversing linked lists efficiently to access stored data.
* Debugging pointer-related logic through manual tracing and careful reasoning.
* Properly managing heap memory by freeing every allocated node.

---

## Author's Note

Built as part of my CS50 learning journey to strengthen my understanding of linked lists, pointer manipulation, and dynamic memory management in C. This project demonstrates how maintaining sorted order during insertion can eliminate the need for a separate sorting step while reinforcing core computer science concepts through hands-on implementation.
