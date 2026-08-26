# CS50 Pset 6 — Mario More (Nested Loops)

## Description

A Python implementation of the **CS50 Mario More** problem using nested loops.

The program asks the user for a pyramid height, validates the input, and prints two right-aligned pyramids separated by two spaces.

## Code

```python
while True:
    try:
        height = int(input("Height: "))

    except ValueError:
        print("Only integers.")

    else:
        if 1 < height < 8:
            print("Height: ", height)
            break

for i in range(height):
    for j in range(height - i - 1):
        print(" ", end="")

    for l in range(i + 1):
        print("#", end="")

    print("  ", end="")

    for i in range(i + 1):
        print("#", end="")

    print()
```

## Example

For a height of `4`:

```text
   #  #
  ##  ##
 ###  ###
####  ####
```

## Concepts Practiced

* `input()` and `int()`
* `while True`
* `try` / `except`
* `ValueError`
* `break`
* `for` loops
* Nested loops
* `range()`
* `print()` and `end=""`
* Input validation
* Pattern generation

## How It Works

For each row:

1. The first loop prints the required leading spaces.
2. The second loop prints the `#` characters for the left pyramid.
3. Two spaces are printed between the pyramids.
4. Another loop prints the `#` characters for the right pyramid.
5. `print()` moves to the next row.

The number of spaces decreases as the row number increases, while the number of `#` characters increases.

## Complexity

For a height of `n`, the nested loops perform work proportional to the number of characters generated across the pyramid.

The overall time complexity is **O(n²)**.

## Key Learning

This implementation demonstrates how **nested loops can be used to construct a two-dimensional output pattern character by character**.

It also provides a useful comparison with the string-multiplication implementation of Mario More, showing two different ways to express the same output logic.

## CS50

This project is part of my **CS50 Pset 6 — Python** work.
