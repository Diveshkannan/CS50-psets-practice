## Plurality Voting System in C

## Overview

This program implements a **plurality voting system** in C, inspired by CS50’s Problem Set 3. In a plurality election, the candidate(s) with the most votes win. If multiple candidates tie with the highest vote count, all tied candidates are declared winners. The program uses a `struct` to store candidate names and vote counts, processes votes from users, and prints the winner(s) at the end.

---

## Features

- Written in standard C with the CS50 library for input handling  
- Supports up to **9 candidates** (`MAX` defined in code)  
- Validates votes and flags invalid entries  
- Handles ties by printing all candidates with the maximum votes  
- Prints “No winners” if no votes are cast  
- Demonstrates use of arrays, structs, loops, conditionals, and string comparison  
- Modular design with separate functions for voting and printing results  

---

## Algorithm Concept

1. Initialize candidates with names and zero votes.  
2. Prompt for the number of voters.  
3. For each voter, accept a candidate name and update the vote count if valid.  
4. Track the highest vote count across all candidates.  
5. Print the names of all candidates whose votes equal the maximum.  
6. If no votes were cast, print “No winners.”  

---

## Example Output

```
$ ./plurality Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Bob

Bob
```

**Tie Example:**

```
$ ./plurality Alice Bob Charlie
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Charlie

Alice
Bob
Charlie
```

---

## Author's Note

Developed as part of CS50’s Problem Set 3 to explore data structures and algorithms in C. This project reinforces concepts such as arrays, structs, string manipulation, and modular programming while simulating a real-world election system. It is a practical exercise in building reliable, fair, and clear logic for handling votes and determining winners.
