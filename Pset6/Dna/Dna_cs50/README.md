# DNA Profiling — CS50

A Python implementation of the **DNA Profiling** problem from Harvard University's CS50.

The program analyzes a DNA sequence, calculates the number of consecutive repetitions of each Short Tandem Repeat (STR), and compares the resulting DNA profile against a database of known profiles.

> **Note:** The `longest_match()` function in this implementation is the function provided by CS50. The DNA database processing, profile construction, and matching logic use the structure of the CS50 problem.

## Overview

The program takes two command-line arguments:

1. A CSV database containing people's names and STR counts.
2. A text file containing a DNA sequence.

It then:

* Reads the database.
* Reads the DNA sequence.
* Calculates the longest consecutive run of each STR.
* Stores those calculated values in a dictionary.
* Compares the calculated profile against every person in the database.
* Prints the matching person's name or `No match found`.

## How It Works

### 1. Command-Line Arguments

The program expects two input files:

```bash
python dna.py database.csv sequence.txt
```

The first argument is the DNA database, while the second argument is the DNA sequence being analyzed.

### 2. Reading the Database

The CSV file is loaded using Python's built-in `csv` module:

```python
with open(sys.argv[1]) as f_dna:
    dna = list(csv.reader(f_dna))
```

Each row represents a person, while the columns contain the person's name and their STR counts.

### 3. Reading the DNA Sequence

The target DNA sequence is read from the second file:

```python
with open(sys.argv[2]) as f_person:
    seq = f_person.read()
```

### 4. Building the STR Profile

The program creates a dictionary containing each STR and its longest consecutive run in the target DNA sequence:

```python
database = dict()

for i in range(1, col):
    database[dna[0][i]] = longest_match(seq, dna[0][i])
```

Conceptually, the dictionary looks like:

```text
STR → longest consecutive run

AGAT → 4
AATG → 2
TATC → 3
```

### 5. Finding a Matching Person

The calculated STR profile is compared against every person's profile in the database.

```python
if int(dna[i][j]) != database[dna[0][j]]:
    break
```

If every STR count matches, the program returns that person's name.

If no profile matches:

```text
No match found
```

## The `longest_match()` Function

The `longest_match()` function determines the longest consecutive sequence of a particular STR within the DNA sequence.

For example:

```text
DNA:      AAAAAA
STR:      AA

AA → 1
AA → 2
AA → 3
```

Therefore, the longest run is:

```text
3
```

### Attribution

The `longest_match()` function is **provided by CS50** and is not my own implementation.

My focus in this version was understanding how the supplied function fits into the larger DNA-profiling algorithm—reading the files, constructing the STR profile, storing the results, and comparing that profile against the database.

## Technologies

* Python
* CSV file processing
* Dictionaries
* Functions
* Loops
* String indexing
* File handling
* Command-line arguments

## Concepts Practiced

This problem reinforced:

* Command-line arguments
* Reading CSV files
* File input
* Dictionaries
* Nested loops
* String manipulation
* Algorithmic thinking
* Profile comparison
* Breaking a problem into smaller functions

## Project Structure

```text
.
├── dna.py
├── database.csv
├── sequence.txt
└── README.md
```

## Running the Program

```bash
python dna.py database.csv sequence.txt
```

Example output:

```text
Alice
```

If no profile matches:

```text
No match found
```

## Learning Reflection

This problem helped me understand how a relatively small program can be divided into separate responsibilities.

The supplied `longest_match()` function handles the STR-searching problem, while the main program handles reading the data, building the calculated profile, and comparing it against the database.

A key lesson was understanding the difference between **using a provided function** and **understanding how that function fits into the overall algorithm**.

The goal was not simply to produce the correct output, but to understand the flow:

```text
DNA database
      ↓
STR sequences
      ↓
longest_match()
      ↓
Calculated DNA profile
      ↓
Compare with database
      ↓
Matching person
```

## Credits

This project was completed as part of **Harvard University's CS50** course.

The `longest_match()` function is provided as part of the CS50 DNA problem.
