Tideman Voting System in C

Overview

This project implements the Tideman voting algorithm in C, a ranked-choice voting system designed to determine the most preferred candidate without creating cycles in the final graph structure.

The program allows voters to rank candidates by preference, records pairwise victories, sorts candidates by strength of victory, and constructs a directed acyclic graph to determine the winner accurately.

This implementation was built completely from scratch with a strong focus on recursion, graph traversal, cycle detection, and algorithmic reasoning.

---

Features

- Written entirely in C
- Implements the Tideman ranked-choice voting algorithm
- Dynamic voter ranking system
- Pairwise preference recording
- Victory strength comparison and sorting
- Recursive cycle detection using Depth-First Search (DFS)
- Directed graph construction using locked pairs
- Winner determination using graph source detection
- Memory-efficient implementation using adjacency matrices
- Beginner-friendly structure with modular functions

---

Core Concepts Used

Ranked Voting

Each voter ranks candidates in order of preference instead of choosing only one candidate.

Pairwise Comparison

Candidates are compared head-to-head to determine which candidate is preferred over another.

Graph Theory

The election result is represented as a directed graph:

- Nodes represent candidates
- Directed edges represent victories

Cycle Detection

Before locking a new edge, the program recursively checks whether adding that edge would create a cycle.

Depth-First Search (DFS)

A recursive DFS traversal is used to explore graph paths and propagate recursive return values correctly.

---

Algorithm Workflow

1. Collect voter rankings
2. Record pairwise preferences
3. Generate winning candidate pairs
4. Sort pairs by strength of victory
5. Lock pairs while preventing cycles
6. Build a directed acyclic graph
7. Find the source node (candidate with no incoming edges)
8. Declare the winner

---

Recursive Cycle Detection Logic

The project uses recursive path searching to prevent cycles in the locked graph.

If a path already exists from:
Loser → Winner

then adding:
Winner → Loser

would create a cycle.

The recursive function propagates return values upward through previous recursive calls, allowing proper cycle detection across deep graph paths.

---

Winner Detection Logic

The winner is determined by finding the source of the directed graph:

- A candidate with zero incoming locked edges
- Meaning the candidate never appears as a loser in any locked pair

This represents the strongest overall candidate according to ranked preferences.

---

Example Flow

Input Rankings:
Alice > Bob > Charlie

Possible Locked Graph:
Alice → Bob
Alice → Charlie
Bob → Charlie

Winner:
Alice

Because Alice has no incoming edges.

---

Technical Highlights

- Recursive DFS implementation
- Recursive return propagation
- Graph traversal reasoning
- Adjacency matrix representation
- Algorithm optimization through early recursion termination
- Strong emphasis on logical problem-solving over memorization

---

Learning Outcome

This project significantly strengthened understanding of:

- recursion,
- graph algorithms,
- DFS traversal,
- cycle prevention,
- ranked voting systems,
- and algorithmic debugging.

The implementation was developed through deep reasoning, tracing recursive calls manually, and understanding how information propagates through recursive functions.

---

Author's Note

Built as part of my computer science and algorithms learning journey through CS50 and it took 5 days for me to finish this perfectly on my own . This project represents a major breakthrough in understanding recursion, graph theory, and algorithmic thinking through hands-on implementation and debugging.

Rather than memorizing solutions, the focus was on fully understanding how recursive propagation, graph locking, and cycle prevention work internally.