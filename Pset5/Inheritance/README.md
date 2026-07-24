# CS50x Week 5 – Inheritance

## Overview

This project is my solution to **CS50x Week 5: Inheritance**. The objective was to simulate the inheritance of blood type alleles across multiple generations of a family using **recursive data structures**, **dynamic memory allocation**, and **recursive memory deallocation** in C.

Each family member is represented as a `person` structure containing:

* Two parent pointers.
* Two blood type alleles (`A`, `B`, or `O`).

The program recursively creates a family tree, randomly assigns alleles to the oldest generation, and models inheritance by passing one random allele from each parent to the child.

---

## Concepts Practiced

* Recursive data structures
* Recursion
* Dynamic memory allocation (`malloc`)
* Memory management (`free`)
* Pointer manipulation
* Tree traversal
* Structs in C
* Randomized inheritance simulation

---

## Implementation

### `create_family()`

The family tree is created recursively.

* Memory is allocated for each new family member.
* If the current generation is not the oldest generation, two parent nodes are recursively created.
* Parent pointers are assigned.
* One allele is randomly inherited from each parent.
* The oldest generation receives randomly generated alleles.

### `free_family()`

Memory is released recursively.

* Parent nodes are freed before the current node.
* Every dynamically allocated `person` is properly deallocated.
* The implementation passes Valgrind with no memory leaks.

---

## What I Learned

This assignment helped me understand:

* How recursive tree structures are created.
* How recursion can naturally model family relationships.
* How pointers connect related structures together.
* The importance of freeing dynamically allocated memory correctly.
* How to think recursively instead of iteratively.

One of the biggest takeaways from this project was learning how recursion is used not only to build complex data structures but also to safely destroy them without leaking memory.

---

## Result

* Passed all `check50` tests.
* Passed all inheritance rule checks.
* Passed Valgrind memory leak detection.
* Successfully completed the CS50x Week 5 Inheritance problem.
