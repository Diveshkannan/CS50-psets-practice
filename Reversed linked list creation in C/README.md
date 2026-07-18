# Reverse Linked List in C

## Overview

This program implements a singly linked list in C using dynamic memory allocation and inserts every new node at the beginning of the list. By always inserting at the head, the final linked list stores the elements in reverse order of the user's input.

The project focuses on understanding pointers, dynamic memory allocation, linked list construction, and traversal without relying on arrays for storage.

---

## Features

* Written in C using structures and pointers
* Dynamic memory allocation using `malloc()`
* Head insertion technique for linked list construction
* Automatically reverses the input order
* Traverses the linked list to display all elements
* Beginner-friendly implementation for understanding linked lists
* Demonstrates manual memory management concepts

---

## Algorithm Concept

1. Create an empty linked list (`list = NULL`).
2. Read the total number of elements.
3. For each element:

   * Allocate memory for a new node.
   * Store the input value.
   * Make the new node point to the current head.
   * Update the head pointer to the new node.
4. Traverse the linked list from the head to print every element.

Since every new node is inserted at the beginning, the linked list becomes the reverse of the input sequence.

---

## Data Structure

Each node contains:

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
Number of elements: 5

10
20
30
40
50
```

### Output

```
Element - 1 : 50
Element - 2 : 40
Element - 3 : 30
Element - 4 : 20
Element - 5 : 10
```

---

## Concepts Practiced

* Structures in C
* Pointers
* Dynamic memory allocation (`malloc`)
* Singly linked lists
* Head insertion
* Linked list traversal
* Heap and stack memory interaction

---

## Author's Note

Built as part of my CS50 learning journey to strengthen my understanding of linked lists, pointers, and dynamic memory management. Instead of following a ready-made implementation, this project focuses on understanding how inserting nodes at the head naturally reverses the order of a linked list and reinforces core data structure concepts through hands-on programming.
