# CS50 Pset 6 — Credit

## Description

This repository contains a Python implementation of the **CS50 Credit** problem.

The program:

* Accepts a credit-card number as input.
* Validates that the input is non-empty and numeric.
* Applies **Luhn's algorithm** to check the card number.
* Counts the number of digits.
* Examines the leading digits to identify the card type.
* Prints `AMEX`, `VISA`, or `MASTERCARD` when the card matches the required rules.
* Reports invalid numbers or unsupported card types.

## How It Works

The program processes the card number in two stages.

### 1. Input Validation

The number is kept as a string initially so that its individual digits can later be accessed directly.

```python
if len(number) == 0:
    print("Number must be entered!")
    continue

if number.isnumeric():
    break
```

This ensures that an empty input is rejected and that only numeric input is accepted.

### 2. Luhn's Algorithm

The program converts the string to an integer and processes its digits from **right to left**.

```python
card = int(number)
```

The last digit is treated as the check digit, so `count` begins at `1`.

```python
count = 1
```

Every second digit from the right is doubled:

```python
if count % 2 == 0:
    temp = 2 * (card % 10)
```

If doubling produces two digits, the digits are added individually:

```python
while temp > 0:
    product += temp % 10
    temp = temp // 10
```

The remaining digits are added normally.

Finally:

```python
sum = add + product

if sum % 10 == 0:
    valid = True
```

A number is considered valid by the Luhn checksum when the total is divisible by 10.

## Card Identification

After the checksum succeeds, the program uses the digit count and leading digits to determine the card type.

### American Express

* 15 digits
* Starts with `34` or `37`

### VISA

* 13 or 16 digits
* Starts with `4`

### MasterCard

* 16 digits
* Starts with a number from `51` through `55`

If the checksum is valid but none of these card types match, the program prints:

```text
No card matched
```

## Concepts Practiced

* Python strings
* `input()`
* `isnumeric()`
* `len()`
* Integer conversion
* `while` loops
* `if` / `elif` / `else`
* Modulo `%`
* Integer division `//`
* Digit extraction
* Luhn's algorithm
* Input validation
* Card-prefix checking
* `sys.exit()`
* Algorithmic reasoning

## Key Learning

This exercise was particularly useful for understanding how the **same number can be represented differently depending on the task**.

The program keeps the original input as a string because strings make it easy to inspect the leading digits:

```python
number[0]
number[1]
```

It then creates an integer copy because integer arithmetic makes it easy to process digits from right to left:

```python
card % 10
card // 10
```

The program therefore uses both representations for different purposes.

## Complexity

The program processes each digit of the card number once, with a small additional loop when a doubled digit contains two digits.

The overall time complexity is approximately **O(n)**, where `n` is the number of digits in the card number.

## Example

A valid card number matching the required rules will produce one of:

```text
AMEX
```

```text
VISA
```

```text
MASTERCARD
```

An invalid Luhn checksum produces:

```text
INVALID
```

A number with a valid checksum but an unsupported card type produces:

```text
No card matched
```

## CS50

This project is part of my **CS50 Pset 6 — Python** work and focuses on implementing an existing algorithm, manipulating digits, validating input, and using numerical patterns to identify card types.
