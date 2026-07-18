# Sorted Singly Linked List in C

## Overview

This program implements a sorted singly linked list in C using dynamic memory allocation. Instead of appending elements in the order they are entered, every new node is inserted into its correct position so that the linked list remains sorted in ascending order throughout execution.

The project focuses on understanding pointer manipulation, linked list traversal, dynamic memory management, and insertion algorithms without using arrays for sorting.

---

## Features

* Written in C using structures and pointers
* Dynamic memory allocation using `malloc()`
* Maintains the linked list in ascending order
* Handles insertion at the beginning, middle, and end of the list
* Traverses the linked list to display the sorted elements
* Demonstrates pointer manipulation without using built-in sorting algorithms
* Beginner-friendly implementation focused on learning data structures

---

## Algorithm Concept

For every new element entered:

1. Allocate memory for a new node.
2. Store the input value.
3. If the list is empty, make the new node the head.
4. If the new value is smaller than the head node, insert it at the beginning.
5. Otherwise, traverse the linked list until the correct insertion point is found.
6. Insert the new node by updating the appropriate pointers.
7. Repeat until all elements have been inserted.

Since each element is placed into its correct position during insertion, the linked list remains sorted without requiring a separate sorting step.

---

## Data Structure

Each node consists of:

* An integer value (`num`)
* A pointer to the next node (`next`)

```c
typedef struct turn
{
    int num;
    struct turn *next;
} turn;
```

---

## Example

### Input

```
Number of elements: 6

40
10
60
20
50
30
```

### Output

```
Element - 1 : 10
Element - 2 : 20
Element - 3 : 30
Element - 4 : 40
Element - 5 : 50
Element - 6 : 60
```

---

## Time Complexity

* Best Case: **O(n)** (elements not arrived in sorted order)
* Worst Case: **O(n²)** (elements already arrive in sorted order)

---

## Concepts Practiced

* Structures in C
* Pointers
* Dynamic memory allocation (`malloc`)
* Singly linked lists
* Sorted insertion algorithm
* Linked list traversal
* Pointer reassignment
* Heap and stack memory interaction
* Maintaining sorted data without array-based sorting

---

## Author's Note

Built as part of my CS50 learning journey to strengthen my understanding of linked lists and pointer manipulation. This project focuses on implementing sorted insertion manually by maintaining the linked list in ascending order as each new node is added, providing hands-on experience with dynamic memory management and fundamental data structure algorithms without relying on built-in sorting techniques.
