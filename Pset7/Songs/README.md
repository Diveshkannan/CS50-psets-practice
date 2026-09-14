# CS50 — Songs Database

This directory contains my work for the **CS50 SQL Songs problem set**, where I practiced writing SQL queries against a music database.

The main focus of this problem set was learning how to retrieve, filter, sort, aggregate, and combine data using SQL.

## What I Practiced

Through the problem set, I worked with:

* `SELECT`
* `WHERE`
* `ORDER BY`
* `LIMIT`
* `LIKE`
* Comparison operators
* `AND`
* Aggregate functions such as `AVG()`
* `JOIN`
* Table relationships through foreign keys
* Filtering data across multiple related tables

## Queries I Completed

### 1. List all songs

```sql
SELECT name FROM songs;
```

Retrieves the names of all songs in the database.

### 2. Sort songs by tempo

```sql
SELECT name FROM songs
ORDER BY tempo ASC;
```

Retrieves song names ordered from the lowest tempo to the highest tempo.

### 3. Find the five longest songs

```sql
SELECT name FROM songs
ORDER BY duration_ms DESC
LIMIT 5;
```

Sorts songs by duration in descending order and returns the five longest songs.

### 4. Find highly danceable, energetic, and positive songs

```sql
SELECT name
FROM songs
WHERE danceability > 0.75
  AND energy > 0.75
  AND valence > 0.75;
```

Filters songs using multiple audio-feature conditions.

### 5. Calculate average song energy

```sql
SELECT AVG(energy)
FROM songs;
```

Uses an aggregate function to calculate the average energy value across the songs.

### 6. Find songs by Post Malone

```sql
SELECT songs.name
FROM songs
JOIN artists
  ON songs.artist_id = artists.id
WHERE artists.name = "Post Malone";
```

This introduced an important concept: **joining related tables**.

Instead of assuming that artist information exists directly inside every song record, the query connects `songs` with `artists` using their relationship.

### 7. Calculate Drake's average song energy

```sql
SELECT AVG(energy)
FROM songs
JOIN artists
  ON songs.artist_id = artists.id
WHERE artists.name = "Drake";
```

Combines:

* `JOIN`
* `WHERE`
* `AVG()`

to calculate an aggregate value for songs belonging to a particular artist.

### 8. Find songs containing "feat"

```sql
SELECT name
FROM songs
WHERE name LIKE "%feat%";
```

Uses pattern matching with `LIKE` to find song titles containing `feat`.

---

# My `answer.txt` — Audio Aura Exploration

In `answer.txt`, I explored a possible **future development** based on the song data.

This is **not a completed implementation** of Audio Aura.

It is an attempt to think beyond the required CS50 questions and connect the SQL concepts with a possible application feature.

## Audio Aura — Initial Idea

The idea is to determine the user's **two most prominent moods** by looking at their **top 100 most-listened songs**.

The possible mood classification would use Spotify-style audio features such as:

* `energy`
* `valence`
* `danceability`

and then use the **Russell's Circumplex Model of Affect** as a conceptual basis for classifying the resulting mood.

## Initial Approach

One approach I considered was adding a `count` value to represent how many times a user listened to each song.

The most-listened songs could then be selected using an ordering such as:

```sql
ORDER BY count DESC
LIMIT 100
```

The audio features of those songs could then be used to calculate averages and determine an Audio Aura.

## Alternative Data Model

I also considered separating listening information from the original song information by using another table such as `records`.

The general idea was:

```text
User
  ↓
Listening records
  ↓
Songs
  ↓
Audio features
  ↓
Audio Aura
```

For a larger application, separating these concepts would likely provide a cleaner foundation because a song's properties and an individual user's listening history represent different kinds of information.

## Future Development

The Audio Aura idea is currently only a **conceptual exploration**.

Need to develop the idea and work on it .

The purpose of `answer.txt` at this stage is therefore not to claim that I built Audio Aura, but to document an idea that came from working with SQL and thinking about how the database could be extended into a real application.

---

# What I Learned

This problem set helped me understand that SQL is more than simply retrieving data.

I practiced thinking about:

**retrieving → filtering → sorting → aggregating → joining → designing**

The required questions gave me the foundation, while the Audio Aura exploration in `answer.txt` gave me an opportunity to think about how those individual SQL concepts could eventually become part of a larger system.

This is still an early idea, and there is much more to develop before it could become a real feature.

---

## Files

```text
.
├── answer.txt
├── [SQL problem files]
└── README.md
```

`answer.txt` contains my **initial exploration of the Audio Aura idea and possible future development**, rather than a completed implementation.

---

## Status

**Completed:** Required SQL practice questions
**Exploration:** Audio Aura concept
**Future:** Database design, listening history, mood classification, optimization, and implementation

---

# License

This repository is for educational and learning purposes.
