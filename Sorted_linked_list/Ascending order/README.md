# Sorted Singly Linked List in C (Ascending Order)

## Overview

This project implements a **Sorted Singly Linked List** in C using dynamic memory allocation. Instead of storing elements in the order they are entered, each new node is inserted into its correct position, ensuring that the linked list remains sorted in **ascending order** throughout execution.

The project focuses on developing a strong understanding of pointers, dynamic memory allocation, linked list traversal, and sorted insertion without relying on arrays or built-in sorting algorithms.

---

## Features

* Written in C using structures and pointers
* Dynamic memory allocation using `malloc()`
* Maintains the linked list in ascending order during insertion
* Handles insertion at:

  * Beginning of the list
  * Middle of the list
  * End of the list
* Traverses the linked list to display the sorted elements
* Properly releases allocated memory using `free()`
* Beginner-friendly implementation emphasizing fundamental data structure concepts

---

## Algorithm Concept

For every element entered by the user:

1. Allocate memory for a new node.
2. Store the input value in the node.
3. If the list is empty, make the new node the head.
4. Otherwise, traverse the linked list to locate the correct insertion position.
5. Insert the new node by updating the required pointers.
6. Repeat until all elements have been inserted.

Since each element is placed directly into its correct position, the linked list remains sorted throughout the entire execution without requiring a separate sorting algorithm.

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
10
20
30
40
50
60
```

---

## Time Complexity

* **Best Case:** O(n)
* **Worst Case:** O(n²)

Each insertion may require traversing the linked list to find the correct position, making the overall worst-case complexity quadratic.

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
* Edge-case handling

---

## Learning Outcomes

Through this project, I learned how to:

* Build a linked list from scratch using dynamic memory allocation.
* Maintain sorted order during insertion rather than sorting after all elements are inserted.
* Correctly update pointers when inserting at the beginning, middle, and end of a linked list.
* Traverse linked lists efficiently to access stored data.
* Debug pointer-related issues through careful tracing and reasoning.
* Manage dynamically allocated memory responsibly by freeing every allocated node.

---

## Author's Note

Built as part of my CS50 learning journey to strengthen my understanding of linked lists, pointers, and dynamic memory management in C. This project emphasizes algorithmic thinking by maintaining a sorted linked list through pointer manipulation alone, reinforcing fundamental computer science concepts without relying on built-in sorting functions or higher-level abstractions.
