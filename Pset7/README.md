# CS50 Pset 7 — SQL

This directory contains my work for **CS50's SQL problem set (Pset 7)**.

The problem set gave me practical experience working with databases and SQL, including retrieving data, filtering results, sorting records, aggregating information, and combining related tables.

More importantly, it helped me start thinking about **how databases can be used as part of larger software systems**, rather than viewing SQL as only a collection of commands.

---

## What I Practiced

Across the problems in this problem set, I worked with concepts including:

* `SELECT`
* `WHERE`
* `AND`
* `OR`
* Comparison operators
* `ORDER BY`
* `ASC` and `DESC`
* `LIMIT`
* `LIKE`
* Aggregate functions such as `AVG()`
* `JOIN`
* Foreign-key relationships
* Filtering data across related tables
* Working with structured datasets
* Thinking about how data can be represented and queried

---

## Problems

This directory contains my solutions and work for the CS50 SQL problem set:

```text
Pset7/
├── Fiftyville/
├── Movies/
├── Songs/
└── ...
```

Each problem focuses on a different aspect of querying or reasoning about relational data.

### Fiftyville

A database investigation problem that requires using SQL queries to follow clues and identify information hidden across multiple related tables.

### Movies

A collection of SQL questions involving a movie database.

I practiced retrieving information, filtering records, sorting results, calculating aggregates, and joining related tables.

### Songs

A music database problem set focused on querying song and artist information and working with audio-related attributes.

I practiced queries involving:

* Song names
* Tempo
* Duration
* Danceability
* Energy
* Valence
* Artists
* Pattern matching
* Average values
* Relationships between songs and artists

---

# `answer.txt` — Audio Aura Exploration

Alongside the required SQL work, I used `answer.txt` to document an **initial idea for a possible future development** based on the Songs database.

The idea is to explore whether a user's listening history could be used to determine their **two most prominent moods** by analyzing their most-listened-to songs.

The initial concept involves:

```text
Listening history
       ↓
Top 100 songs
       ↓
Audio features
       ↓
Average / analysis
       ↓
Russell's Circumplex Model
       ↓
Audio Aura
```

I considered different ways of representing listening counts, storing user-specific records, calculating audio-feature averages, and eventually storing an Audio Aura result.

This is **not a completed feature or implementation**.

It is simply an early design exploration that came from thinking about how the SQL concepts I was learning could eventually be connected to a real application.

There is much more to develop and test before this could become a proper implementation.

---

# What I Learned

One of the biggest things I took away from Pset 7 is that SQL is not just about writing individual queries.

The queries made me think about the different operations involved in working with data:

**retrieve → filter → sort → aggregate → join → reason about the data → design**

I also started thinking about the difference between:

* Data that describes an object
* Data that describes a relationship
* Temporary calculations
* Persistent information
* Query correctness
* Query efficiency
* Database structure

The Audio Aura exploration in `answer.txt` is my first attempt to take those ideas beyond the required questions and think about how they might fit into a larger software system.

---

## Repository Structure

```text
Pset7/
│
├── Fiftyville/
│   └── SQL investigation files
│
├── Movies/
│   └── SQL queries
│
├── Songs/
│   ├── SQL queries
│   └── answer.txt
│
└── README.md
```

> The exact files may vary depending on the CS50 problem-set structure and my uploaded solutions.

---


## License

This repository is maintained for educational and learning purposes.
