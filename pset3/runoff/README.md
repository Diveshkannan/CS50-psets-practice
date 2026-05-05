# 🗳️ Runoff Voting System (CS50 Project)

A complete implementation of a **ranked-choice runoff voting system** written in C.  
This program simulates real-world elections where voters rank candidates by preference, and candidates are eliminated in rounds until a winner is determined.

---

## 📌 Overview

This project implements the **Runoff Voting Algorithm**, where:

- Each voter ranks candidates in order of preference
- Votes are counted in rounds
- If no candidate wins outright (>50%), the lowest candidate(s) are eliminated
- Votes are redistributed based on next preferences
- Process repeats until a winner is found

---

## ⚙️ How It Works

### 🧾 Step-by-step Process

1. Voters rank candidates
2. First-choice votes are counted
3. If no winner (>50%),:
   - Find candidate(s) with the fewest votes
   - Eliminate them
   - Redistribute their votes to next preferred non-eliminated candidate
4. Repeat until a winner exists

---

## 🧠 Key Features

- 📊 Ranked-choice voting system
- 🔁 Multiple rounds of vote tabulation
- ❌ Candidate elimination logic
- 🏆 Automatic winner detection (>50%)
- 🔄 Vote redistribution based on preferences
- 🧩 Efficient structured C implementation

---

## 🏗️ Data Structures Used

```c
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

name → Candidate name

votes → Current round vote count

eliminated → Status in election



---

## 📥 Input Format

Command-line candidates:

./runoff Alice Bob Charlie

Voter input:

Each voter enters ranked preferences:

Rank 1: Alice  
Rank 2: Charlie  
Rank 3: Bob


---

## 📤 Output Example

Number of voters: 3

Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Alice


---

## 🔁 Core Functions

vote() → Records voter preferences

tabulate() → Counts votes each round

print_winner() → Checks majority winner

find_min() → Finds lowest vote count

is_tie() → Checks if all remaining candidates are tied

eliminate() → Removes lowest candidates



---

## 🧩 Core Logic (Tabulation)

Votes are assigned like this:

Each voter’s top non-eliminated candidate gets 1 vote

If eliminated, system moves to next preference

Only one vote per voter per round



---

## 🎯 Learning Outcomes

This project helped reinforce:

Arrays & 2D arrays in C

Struct usage

Election algorithm logic

Problem decomposition

Real-world simulation modeling



---

## 🚀 Future Improvements

Add graphical UI

Support dynamic candidate resizing

Store election results in files

Visualize voting rounds



---

## 👨‍💻 Author

Built as part of the CS50 problem set (Runoff Voting)
Focused on understanding algorithms, data structures, and real-world voting systems.


---

## 📜 License

 MIT liscense

For educational purposes only.

--