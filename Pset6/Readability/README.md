# CS50 Pset 6 — Readability

## Description

A Python implementation of the CS50 **Readability** problem.

The program asks the user to enter a text passage, counts its letters, words, and sentences, and then uses the **Coleman–Liau index** to determine the approximate reading grade level.

## Code

```python
from sys import exit


def main():

    text = input("Text: ")
    length = len(text)

    if length == 0:
        print("We need text to grade !!!")
        exit(1)

    letters = 0
    words = 0
    sentences = 0

    for i in range(length):
        if text[i].isalpha():
            letters += 1

        if (i > 0) and (text[i] == " " and text[i - 1].isalpha()):
            words += 1

        if (i > 0) and (
            (text[i] == "." or text[i] == "?" or text[i] == "!")
            and text[i - 1].isalpha()
        ):
            sentences += 1
            words += 1

    index = coleman(letters, words, sentences)

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Grade less than 1")
    else:
        print("Grade", index)


def coleman(l, w, s):
    L = (l / w) * 100
    S = (s / w) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index


main()
exit(0)
```

## How It Works

The program processes the input text character by character.

### 1. Count Letters

Alphabetic characters are detected using:

```python
text[i].isalpha()
```

Each alphabetic character increases the `letters` counter.

### 2. Count Words

The implementation considers a word completed when it encounters a space after an alphabetic character.

It also accounts for the final word of a sentence when `.`, `?`, or `!` is encountered after an alphabetic character.

### 3. Count Sentences

A sentence is counted when the program encounters:

* `.`
* `?`
* `!`

after an alphabetic character.

### 4. Calculate the Reading Grade

The `coleman()` function calculates:

* `L` — average number of letters per 100 words
* `S` — average number of sentences per 100 words
* `index` — Coleman–Liau readability index

The resulting index is then converted into a grade-level output.

## Output

The program reports one of three results:

```text
Grade 16+
```

```text
Grade less than 1
```

or a specific grade:

```text
Grade 8
```

## Concepts Practiced

* Functions
* `main()`
* User input with `input()`
* `len()`
* `for` loops
* Character-by-character string processing
* `.isalpha()`
* Conditional statements
* Boolean conditions
* Counters
* `exit()`
* Arithmetic calculations
* Implementing a mathematical formula
* Basic algorithm design

## Algorithm

```text
Input text
    ↓
Check for empty input
    ↓
Scan every character
    ↓
Count letters
    ↓
Detect word boundaries
    ↓
Count sentences
    ↓
Calculate Coleman–Liau index
    ↓
Convert index to grade
    ↓
Print result
```

## Current Approach

The word-counting logic uses character boundaries rather than simply splitting the entire string.

For example, when a sentence-ending punctuation mark follows an alphabetic character, the implementation treats that point as the completion of a word as well as a sentence.

This is the current approach used in this implementation.

## Future Improvements

Potential edge cases and alternative approaches can be explored later, including different punctuation patterns, spacing, apostrophes, and other text structures.

## CS50

This project is part of my **CS50 Pset 6 — Python** work and focuses on Python functions, string processing, input handling, counters, and translating a mathematical formula into a working program.
