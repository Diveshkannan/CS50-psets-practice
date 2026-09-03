# DNA Profiling

A Python implementation of a DNA profiling program that identifies an individual by comparing the number of consecutive **Short Tandem Repeats (STRs)** found in a DNA sequence against a database of known DNA profiles.

This project was completed as part of **CS50's Introduction to Computer Science — Week 6**.

## How It Works

The program takes two command-line arguments:

1. A **CSV database file** containing people's names and their STR counts.
2. A **DNA sequence text file** containing the DNA sample to identify.

The program:

1. Reads the DNA database using Python's `csv` module.
2. Reads the DNA sequence from the provided text file.
3. Identifies the STR sequences listed in the database.
4. Calculates the longest consecutive run of each STR in the DNA sequence.
5. Compares the calculated STR counts with every person's profile in the database.
6. Prints the name of the matching individual.
7. Prints `No match found` if no profile matches.

## Requirements

* Python 3
* A DNA database in CSV format
* A DNA sequence in a text file

## Input Format

### Database CSV

The first row contains the column names. The first column must be `name`, followed by the STR sequences.

Example:

```csv
name,AGAT,AATG,TATC
Alice,28,42,14
Bob,17,22,19
Charlie,36,18,25
```

Each person's row contains the expected number of consecutive repeats for each STR.

### DNA Sequence

The DNA sequence should be stored in a text file containing a sequence made up of:

```text
A
T
G
C
```

For example:

```text
AGATAGATAGAT...
```

## Running the Program

Run the program from the terminal with:

```bash
python dna.py <database.csv> <sequence.txt>
```

Example:

```bash
python dna.py databases/small.csv sequences/1.txt
```

The program will print the matching person's name if the STR profile matches.

If there is no matching profile:

```text
No match found
```

## Project Structure

```text
dna/
├── dna.py
├── databases/
│   ├── small.csv
│   └── large.csv
└── sequences/
    ├── 1.txt
    ├── 2.txt
    └── ...
```

## Functions

### `main()`

Handles:

* Command-line arguments
* Reading the database
* Reading the DNA sequence
* Calculating STR counts
* Comparing DNA profiles
* Printing the result

### `count(data, sequence)`

Searches through the DNA sequence and determines the longest consecutive run of a particular STR.

### `check(sequence)`

Checks whether a string consists only of valid DNA bases:

* `A` — Adenine
* `T` — Thymine
* `G` — Guanine
* `C` — Cytosine

## What I Practiced

This project gave me practice with:

* Python functions
* Command-line arguments with `sys.argv`
* CSV processing with `csv.reader`
* Dictionaries
* Lists
* Nested loops
* `while` loops
* String processing
* Type conversion
* Program control flow
* Breaking a larger problem into smaller functions
* Debugging an independently designed solution

## Learning Note

I intentionally developed my own approach to the problem before comparing it with the CS50 implementation.

The goal was not just to get the correct output, but to practice **thinking through the problem and designing the algorithm myself**.

## Course

**CS50's Introduction to Computer Science — Week 6**

Topic: Python and DNA Profiling
