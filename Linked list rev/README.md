# Linked List Stack Implementation in C

## Overview

This program implements a singly linked list in C using a prepend (Stack/LIFO) insertion method. It allows users to dynamically create a list of integers through the command line and displays the elements in reverse order of input.

The implementation focuses on manual memory allocation (`malloc`) and pointer manipulation to build data structures from scratch.

---

## Features

- Written in C with a focus on core memory management concepts.
- Dynamic list size defined by the user at runtime.
- Prepend insertion logic (Last-In, First-Out behavior).
- Structural nodes built using custom user-defined `struct` types.
- Array-based snapshot caching for sequential element printing.
- Clean and beginner-friendly implementation focused on learning foundational data structures.

---

## Data Structure Concept

1. **Nodes:** Each element in the list is a structure containing an integer value (`num`) and a pointer to the next element (`next`).
2. **Prepend Insertion:** Every new node becomes the new head of the list (`list = n`), pushing previous nodes down the line.
3. **Termination:** The first entered element naturally becomes the tail of the list and points to `NULL`.

---

## Input Method

The program utilizes the standard `scanf` function to build the list:

- The user specifies the total number of elements (`N`) up front.
- Elements are collected sequentially via a `for` loop.
- Invalid or zero/negative counts safely terminate the program.

---

## Example Output

Input:
Number of elements: 4
Number: 10
Number: 20
Number: 30
Number: 40

Output:
Element - 1 : 40
Element - 2 : 30
Element - 3 : 20
Element - 4 : 10

---

##  Future Updates

- Need to free the heap memory used

---

## Author's Note

Built as part of my learning journey in low-level programming and data structures. This project focuses on mastering pointer assignment, understanding how the heap allocates memory dynamically, and implementing algorithmic traversal logic without relying on high-level abstractions.
