# CS50 Pset 6 — Mario Less

## Description

This repository contains two Python implementations of the **CS50 Mario Less** problem.

Both programs:

* Ask the user for a pyramid height.
* Validate the input.
* Accept heights from **2 through 7**.
* Handle invalid non-integer input using `try` / `except`.
* Print a right-aligned pyramid using spaces and `#` characters.

The two implementations solve the same problem using different approaches.

## Implementation 1 — Nested Loops

The first implementation builds the pyramid character by character using nested loops.

It explicitly controls:

* The number of spaces in each row.
* The number of `#` characters in each row.
* The transition to the next row.

### Complexity

The output grows with the size of the pyramid, giving an overall **O(n²)** amount of work.

## Implementation 2 — String Multiplication

The second implementation uses Python's string multiplication:

```python
" " * number_of_spaces
"#" * number_of_hashes
```

This makes the code shorter and more readable while producing the same pyramid.

### Important Note

Although this version has only one visible `for` loop, that does **not** make the overall algorithm O(n).

Creating strings of increasing lengths still requires work proportional to the number of characters produced. Therefore, the total work remains **O(n²)** with respect to the pyramid height.

## Example Output

For a height of `4`:

```text
   #
  ##
 ###
####
```

## Concepts Practiced

* Python input and output
* Variables
* `while True`
* `try` / `except`
* `ValueError`
* `break`
* `else`
* `for` loops
* Nested loops
* `range()`
* String multiplication
* `print()` and `end=""`
* Pattern generation
* Basic time-complexity reasoning

## Key Learning

The main purpose of having both implementations is to compare **two different ways of expressing the same logic**.

The nested-loop version makes the individual operations explicit, while the string-multiplication version uses Python's built-in string operations to express the same idea more concisely.

This exercise helped reinforce an important programming habit:

> **Don't judge an algorithm's complexity only by how many loops you can see. Consider the work performed inside those operations.**

## Files

```text
.
├── mario.py
├── mario_nested.py
└── README.md
```

## CS50

This project is part of my **CS50 Pset 6 — Python** work and focuses on building fluency with Python syntax, input validation, loops, strings, and basic algorithmic reasoning.
