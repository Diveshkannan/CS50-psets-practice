# Mario Less — Python

## Description

A Python implementation of the CS50 Mario problem. The program asks the user for a height, validates the input, and prints a right-aligned pyramid using spaces and `#` characters.

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
    print("#" * (i + 1))
```

## Concepts Learned

* `input()` for user input
* `int()` for converting input to an integer
* `try` / `except` for handling invalid input
* `else` with exception handling
* `while True` for repeated input validation
* `break` for exiting the validation loop
* `range()` for iteration
* String multiplication for generating repeated spaces and `#` characters
* `end=""` for controlling output formatting
* Nested program logic and loops

## Input Validation

The program accepts heights from **2 through 7**.

If the user enters something that cannot be converted to an integer, the program catches the `ValueError` and asks again.

## Example

```text
Height: abc
Only integers.
Height: 8
Height: 4
Height:  4
   #
  ##
 ###
####
```

## Key Learning

This implementation showed how Python's **string operations can simplify repeated output** compared with manually printing each character inside nested loops.

## Purpose

This exercise practices Python input validation, exception handling, loops, string manipulation, and formatted console output.
