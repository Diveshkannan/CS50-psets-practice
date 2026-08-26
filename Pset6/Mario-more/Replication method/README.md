# CS50 Pset 6 — Mario More

## Description

A Python implementation of the **CS50 Mario More** problem.

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
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1))
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
* `range()`
* String multiplication
* `print()` and `end=""`
* Input validation
* Pattern generation

## How It Works

For each row:

1. Print the required leading spaces.
2. Print the left pyramid's `#` characters.
3. Print two spaces between the pyramids.
4. Print the right pyramid's `#` characters.
5. Move to the next line.

The two pyramids grow together as the row number increases.

## Key Learning

This problem builds on the **Mario Less** exercise by adding a second pyramid and requiring more careful control of spaces and output formatting.

It also provides practice expressing a visual pattern using Python's string operations rather than printing every character individually.

## CS50

This project is part of my **CS50 Pset 6 — Python** work.
