# CS50 Pset 7 — Movies

A collection of SQL queries completed for **CS50's Pset 7: Movies**.

This problem set focuses on working with a relational database containing information about movies, people, ratings, stars, and directors. The queries practice filtering, sorting, aggregation, and joining multiple tables.

## 📚 Concepts Practiced

* `SELECT`
* `WHERE`
* `LIKE`
* `ORDER BY`
* Multiple sorting criteria
* `ASC` / `DESC`
* `COUNT()`
* `AVG()`
* `JOIN`
* `DISTINCT`
* `IN`
* Subqueries
* `LIMIT`
* Working with relational data

---

## 🗂️ Database Tables

The queries work with tables including:

* `movies`
* `people`
* `ratings`
* `stars`
* `directors`

The relationships between these tables allow information such as movie titles, actors, directors, ratings, and birth years to be connected.

---

# 🔎 Queries

## 1. Movies from 2008

Finds the titles of all movies released in 2008.

```sql
SELECT title
FROM movies
WHERE year = 2008;
```

**Concepts:** `SELECT`, `WHERE`

---

## 2. Birth Year of Emma Stone

Finds the birth year of Emma Stone.

```sql
SELECT birth
FROM people
WHERE name = "Emma Stone";
```

**Concepts:** Filtering rows with `WHERE`

---

## 3. Movies Since 2018

Lists all movie titles released from 2018 onward in alphabetical order.

```sql
SELECT title
FROM movies
WHERE year >= 2018
ORDER BY title ASC;
```

**Concepts:** Comparison operators, `ORDER BY`, alphabetical sorting

---

## 4. Movies with a 10.0 Rating

Counts the number of movies that received a rating of exactly `10.0`.

```sql
SELECT COUNT(*)
FROM movies
JOIN ratings
    ON movies.id = ratings.movie_id
WHERE rating = 10.0;
```

**Concepts:** `JOIN`, `COUNT()`, filtering joined data

---

## 5. Harry Potter Movies

Finds Harry Potter movies and lists them chronologically.

```sql
SELECT title, year
FROM movies
WHERE title LIKE "Harry Potter and the%"
ORDER BY year ASC;
```

**Concepts:** `LIKE`, wildcard `%`, chronological sorting

---

## 6. Average Rating in 2012

Calculates the average rating of movies released in 2012.

```sql
SELECT AVG(rating)
FROM ratings
JOIN movies
    ON ratings.movie_id = movies.id
WHERE year = 2012;
```

**Concepts:** `AVG()`, `JOIN`, filtering

---

## 7. Movies and Ratings from 2010

Lists movies released in 2010 with their ratings.

Movies are ordered by rating from highest to lowest. If two movies have the same rating, their titles are ordered alphabetically.

```sql
SELECT title, rating
FROM movies
JOIN ratings
    ON movies.id = ratings.movie_id
WHERE movies.year = 2010
ORDER BY ratings.rating DESC, movies.title ASC;
```

**Concepts:** Multiple `ORDER BY` criteria, descending and ascending sorting, `JOIN`

The second sorting criterion acts as a **tie-breaker** when two movies have the same rating.

---

## 8. Actors in Toy Story

Lists the names of people who starred in *Toy Story*.

```sql
SELECT name
FROM people
JOIN stars
    ON people.id = stars.person_id
JOIN movies
    ON stars.movie_id = movies.id
WHERE movies.title = "Toy Story";
```

**Concepts:** Multiple `JOIN`s, relational connections

---

## 9. Actors in Movies from 2004

Lists the IDs and names of people who starred in movies released in 2004, ordered by birth year.

```sql
SELECT DISTINCT people.id, people.name
FROM people
JOIN stars
    ON people.id = stars.person_id
JOIN movies
    ON stars.movie_id = movies.id
WHERE movies.year = 2004
ORDER BY people.birth ASC;
```

**Concepts:** `DISTINCT`, multiple `JOIN`s, sorting

---

## 10. Directors of Highly Rated Movies

Lists directors who directed at least one movie with a rating of `9.0` or higher.

```sql
SELECT DISTINCT name
FROM people
JOIN directors
    ON people.id = directors.person_id
JOIN ratings
    ON directors.movie_id = ratings.movie_id
WHERE rating >= 9.0;
```

**Concepts:** Multiple `JOIN`s, `DISTINCT`, comparison operators

---

## 11. Highest Rated Chadwick Boseman Movies

Finds the five highest-rated movies in which Chadwick Boseman starred.

```sql
SELECT title
FROM movies
JOIN stars
    ON movies.id = stars.movie_id
JOIN people
    ON stars.person_id = people.id
JOIN ratings
    ON movies.id = ratings.movie_id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;
```

**Concepts:** Multiple `JOIN`s, `ORDER BY DESC`, `LIMIT`

---

## 12. Movies Featuring Both Jennifer Lawrence and Bradley Cooper

Finds movies in which Jennifer Lawrence starred and whose movie ID also appears among movies starring Bradley Cooper.

```sql
SELECT title
FROM movies
JOIN stars
    ON movies.id = stars.movie_id
JOIN people
    ON stars.person_id = people.id
WHERE people.name = "Jennifer Lawrence"
  AND movies.id IN (
      SELECT id
      FROM movies
      JOIN stars
          ON movies.id = stars.movie_id
      JOIN people
          ON stars.person_id = people.id
      WHERE people.name = "Bradley Cooper"
  );
```

**Concepts:** Subqueries, `IN`, `JOIN`, combining conditions

---

## 13. People Who Starred with Kevin Bacon

Finds people who starred in a movie that Kevin Bacon also starred in.

```sql
SELECT name
FROM people
JOIN stars
    ON people.id = stars.person_id
JOIN movies
    ON stars.movie_id = movies.id
WHERE movies.id IN (
    SELECT id
    FROM movies
    JOIN stars
        ON movies.id = stars.movie_id
    JOIN people
        ON stars.person_id = people.id
    WHERE people.name = "Kevin Bacon"
);
```

**Concepts:** Subqueries, `IN`, multiple `JOIN`s, relational reasoning

---

# 🧠 What I Learned

This problem set helped me understand that SQL is not just about writing individual commands. The important part is understanding how information is related inside a database.

Some of the key connections I practiced were:

```text
Tables
   ↓
Relationships through IDs
   ↓
JOIN
   ↓
Filter / aggregate / sort
   ↓
Useful information
```

I also practiced thinking about a query as a sequence of decisions:

```text
What information do I need?
        ↓
Which table contains it?
        ↓
Which tables must be connected?
        ↓
What rows should be included?
        ↓
Does the result need filtering?
        ↓
Does it need sorting?
        ↓
Does it need aggregation or a subquery?
```

One useful concept I encountered was that `ORDER BY` can use **multiple criteria**. The first criterion determines the primary ordering, while later criteria can resolve ties.

---

# 🚀 Takeaway

Pset 7 gave me more practice working with relational data and helped me become more comfortable reasoning about how multiple tables connect.

Rather than treating SQL queries as isolated syntax, I'm trying to understand the underlying structure:

**data → relationships → conditions → operations → result**

This is another step toward becoming more comfortable with databases and eventually using SQL inside real applications.

---

## 📌 Technologies

* SQL
* SQLite
* CS50
* Relational Databases

## 🎓 Course

**CS50x — Introduction to Computer Science**

Harvard University / CS50

---

## 📁 Problem Set

**Pset 7 — Movies**

This repository contains my practice and solutions while working through the problem set.
