# CS50 Pset 6 — Mario More

## Description

This repository contains **two Python implementations** of the CS50 **Mario More** problem.

Both implementations:

* Ask the user for a pyramid height.
* Validate the input.
* Accept heights from **2 through 7**.
* Handle invalid non-integer input with `try` / `except`.
* Print two right-aligned pyramids separated by two spaces.

The two versions use different approaches to generate the same output.

## Implementation 1 — String Multiplication

This version uses Python's string multiplication to create the spaces and `#` characters.

```python
print(" " * (height - i - 1), end="")
print("#" * (i + 1), end="")
print("  ", end="")
print("#" * (i + 1))
```

This makes the implementation concise and readable.

## Implementation 2 — Nested Loops

This version builds the same pattern character by character using nested loops.

It explicitly controls:

* Leading spaces
* Left pyramid blocks
* The gap between pyramids
* Right pyramid blocks

This makes the underlying pattern-generation process more explicit.

## Example Output

For a height of `4`:

```text
   #  #
  ##  ##
 ###  ###
####  ####
```

## Concepts Practiced

* User input with `input()`
* Integer conversion with `int()`
* `try` / `except`
* `ValueError`
* `while True`
* `break`
* `for` loops
* Nested loops
* `range()`
* String multiplication
* `print()` and `end=""`
* Input validation
* Pattern generation
* Comparing different implementations

## Complexity

Both implementations ultimately generate a pyramid whose total output grows with the number of rows.

Although the string-multiplication version has fewer visible loops, the strings being created grow with the row size. Therefore, the overall work remains **O(n²)** with respect to the pyramid height.

## Key Learning

The two implementations solve the same problem at different levels of abstraction:

**Nested loops**

> Explicitly build the pattern character by character.

**String multiplication**

> Use Python's built-in string operations to express the same pattern more concisely.

Comparing both approaches helps develop the habit of asking not only **“Does this work?”**, but also:

> **“How else could I express the same logic, and what does each approach actually cost?”**

## CS50

This project is part of my **CS50 Pset 6 — Python** work and focuses on Python fundamentals, input validation, loops, strings, pattern generation, and basic algorithmic reasoning.
