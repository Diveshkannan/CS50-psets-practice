# CS50 Pset 6 — Cash

## Description

A Python implementation of the CS50 **Cash** problem.

The program asks the user how much change is owed, converts the amount into cents, and calculates the minimum number of coins needed using quarters, dimes, nickels, and pennies.

## Code

```python
dollars = 0
cents = 0
coins = 0

while True:
    try:
        dollars = float(input("Change owed: "))
    except ValueError:
        print("Only floats.")

    else:
        cents = int(dollars * 100)

        if cents >= 0:
            break

quarters = cents // 25
coins += quarters
cents -= 25 * quarters

dimes = cents // 10
coins += dimes
cents -= 10 * dimes

nickels = cents // 5
coins += nickels
cents -= 5 * nickels

pennies = cents // 1
coins += pennies
cents -= pennies

print(coins)
```

## How It Works

The program uses a **greedy approach**:

1. Convert the dollar amount into cents.
2. Take as many quarters as possible.
3. Take as many dimes as possible from the remaining cents.
4. Take as many nickels as possible.
5. Take the remaining pennies.
6. Add all the coins together.

For example, if the remaining amount is `41` cents:

```text
41 // 25 → 1 quarter
16 // 10 → 1 dime
 6 //  5 → 1 nickel
 1 //  1 → 1 penny

Total = 4 coins
```

## Concepts Practiced

* `input()`
* `float()`
* `int()`
* `try` / `except`
* `ValueError`
* `while True`
* `break`
* Integer division with `//`
* Arithmetic operators
* Variables and counters
* Greedy algorithms
* Input validation

## Key Learning

This exercise introduced the idea of a **greedy algorithm**: at each step, choose the largest denomination that can be used, then continue with the remaining amount.

It also provided practice breaking a problem into smaller, repeatable operations.

## Note

The coin-counting logic operates on an integer number of cents, avoiding floating-point calculations after the initial conversion.

## CS50

This project is part of my **CS50 Pset 6 — Python** work and focuses on Python fundamentals, arithmetic, input validation, and introductory algorithmic thinking.
