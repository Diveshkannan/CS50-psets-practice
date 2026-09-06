# DNA Profiling — CS50

A Python implementation of the **DNA Profiling** problem from Harvard's CS50.

The program reads a DNA database containing people's STR (Short Tandem Repeat) counts, analyzes a target DNA sequence, and determines which person matches the calculated STR profile.

## Overview

The program takes two command-line arguments:

1. A CSV file containing the DNA database.
2. A text file containing the DNA sequence to analyze.

It then:

* Reads the DNA database.
* Identifies the STR sequences in the database.
* Calculates the longest consecutive run of each STR in the target DNA.
* Stores the calculated STR counts in a dictionary.
* Compares the calculated profile against every person's profile.
* Prints the matching person's name or `No match found`.

## How It Works

### 1. Command-Line Arguments

The program expects exactly two arguments:

```bash
python dna.py database.csv sequence.txt
```

If the required arguments are missing, the program exits with an error.

### 2. Reading the Files

The database is read using Python's `csv` module:

```python
with open(sys.argv[1]) as f_dna:
    read = list(csv.reader(f_dna))
```

The target DNA sequence is read from the second file:

```python
with open(sys.argv[2]) as f_person:
    data = f_person.read()
```

File errors are handled with `try`/`except`.

### 3. Identifying STR Sequences

The `check()` function determines whether a string contains only DNA bases:

```python
def check(sequence):
    for i in sequence:
        if i not in 'ATGC':
            return False
    return True
```

This allows the program to distinguish DNA STR sequences from the person's name and other database information.

### 4. Calculating STR Repetitions

The `count()` function searches the DNA sequence for consecutive repetitions of a particular STR.

It keeps track of:

* The current number of consecutive repetitions.
* The STR length.
* The positions being examined.
* The completed repetition counts.

When a mismatch occurs, the current run is stored. At the end, the maximum run is returned.

For example:

```text
DNA:      AAAAAA
STR:      AA

AA → 1
AA → 2
AA → 3
```

The longest consecutive repetition is therefore:

```text
3
```

### 5. Building the DNA Profile

The calculated STR counts are stored in a dictionary:

```text
STR sequence → longest consecutive repetition
```

Conceptually:

```text
{
    "AGAT": 4,
    "AATG": 2,
    "TATC": 3
}
```

This makes it possible to compare the calculated profile against each person's database row.

### 6. Finding a Match

The program loops through each person in the database and compares their STR counts with the calculated DNA profile.

If every STR count matches, the person's name is printed.

If no profile matches:

```text
No match found
```

## Technologies

* Python
* `csv`
* `sys`
* Dictionaries
* File handling
* Loops
* Functions
* String processing
* Command-line arguments

## Key Concepts Practiced

This project helped reinforce several important programming concepts:

* Reading and processing CSV files
* Command-line arguments
* Exception handling
* Dictionaries
* Nested loops
* String indexing
* Function decomposition
* Algorithmic reasoning
* Searching for consecutive patterns
* Comparing structured data

## Project Structure

```text
.
├── dna.py
├── database.csv
├── sequence.txt
└── README.md
```

## Running the Program

Run the program from the terminal:

```bash
python dna.py database.csv sequence.txt
```

Example output:

```text
Alice
```

or:

```text
No match found
```

## Learning Reflection

The main challenge in this problem was not reading the files—it was designing the logic for finding the **longest consecutive STR repetition**.

Rather than directly copying the reference implementation, I worked through the problem by building my own approach using a dictionary, a DNA-validation function, and a custom STR-counting algorithm.

The process helped me understand that solving a programming problem is not only about getting the correct output. It is also about being able to **trace the algorithm, identify edge cases, simplify unnecessary state, and understand why the code works**.

## Credits

This project was completed as part of **Harvard University's CS50** course.

The problem is based on DNA profiling using Short Tandem Repeats (STRs).
