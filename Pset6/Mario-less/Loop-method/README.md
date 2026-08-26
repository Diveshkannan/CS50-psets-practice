# Mario Less — Python

## Description

A Python implementation of the CS50 Mario problem that validates the user's height and prints a right-aligned pyramid using **nested loops**.

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

    print()
```

## Concepts Learned

* `input()` and `int()` for receiving and converting user input
* `try` / `except` for handling `ValueError`
* `while True` for repeated input validation
* `break` for exiting the loop
* `range()` for controlled iteration
* **Nested `for` loops**
* Using `print(..., end="")` to keep output on the same line
* Building a pattern one character at a time
* Controlling spaces and `#` characters mathematically

## How the Pyramid Works

For each row:

1. The first inner loop prints the required number of spaces.
2. The second inner loop prints the required number of `#` characters.
3. `print()` moves to the next line.

For a height of `4`:

```text
   #
  ##
 ###
####
```

The number of spaces decreases by one each row, while the number of `#` characters increases by one.

## Complexity

The program uses nested loops to generate the output.

For a height of `n`, the total number of characters printed is proportional to:

**O(n²)**

This is because the program produces a two-dimensional pyramid pattern whose total output grows approximately with `1 + 2 + ... + n`.

## Key Learning

This version demonstrates how **nested loops can directly model a two-dimensional pattern**: the outer loop represents rows, while the inner loops control what appears inside each row.
