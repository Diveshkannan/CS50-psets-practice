# 🕵️ CS50 Fiftyville — SQL Investigation

This directory contains my work for **CS50’s Fiftyville problem**, where I used SQL queries to investigate the theft of the CS50 duck.

The goal was to determine:

* 🕵️ **Who was the thief?**
* ✈️ **Which city did the thief escape to?**
* 📞 **Who was the accomplice?**

The investigation took place around a theft reported on **July 28, 2025, at Humphrey Street Bakery**.

---

## 🔎 Investigation Process

Instead of trying to identify the thief directly, I gradually reduced the number of possible suspects by connecting information from different tables.

The investigation followed roughly this path:

```text
Crime Scene
    ↓
Witness Interviews
    ↓
ATM Transactions
    ↓
Bakery Security Logs
    ↓
Phone Calls
    ↓
Flights & Passengers
    ↓
Car Timing
    ↓
Accomplice
```

The main idea was to use each clue to eliminate possibilities until only the consistent suspect remained.

---

## 1. Crime Scene

I started by searching the `crime_scene_reports` table using the street name:

```sql
SELECT *
FROM crime_scene_reports
WHERE street = "Humphrey Street";
```

This established that the theft happened at **10:15 AM** at Humphrey Street Bakery and that three witnesses had given interviews.

---

## 2. Witness Interviews

I then searched the interviews mentioning the bakery:

```sql
SELECT *
FROM interviews
WHERE transcript LIKE "%bakery%";
```

The witnesses provided three important clues:

* **Ruth:** the thief got into a car in the bakery parking lot within about 10 minutes.
* **Eugene:** the thief was seen withdrawing money from an ATM on Leggett Street.
* **Raymond:** the thief was talking to an accomplice and wanted to take the earliest flight out of Fiftyville the next day.

These clues became the foundation for the rest of the investigation.

---

## 3. ATM Transactions

Next, I searched ATM withdrawals from Leggett Street on the day of the theft:

```sql
SELECT *
FROM people
JOIN bank_accounts
  ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2025
      AND month = 7
      AND day = 28
      AND atm_location = "Leggett Street"
      AND transaction_type = "withdraw"
);
```

This reduced the possible suspects from the entire city to **eight people**.

---

## 4. Bakery Security Logs

I then connected the ATM suspects with the bakery security logs.

This reduced the eight suspects to **five people** who had cars leaving the bakery during the relevant time period.

The remaining names were:

```text
Iman
Taylor
Luca
Diana
Bruce
```

---

## 5. Short Phone Calls

The witness said the thief had been speaking with an accomplice.

I therefore looked for short phone calls involving the remaining suspects:

```sql
SELECT *
FROM phone_calls
WHERE caller IN (...)
  AND year = 2025
  AND month = 7
  AND day = 28
  AND duration < 60;
```

This reduced the possible thief to three people:

```text
Taylor
Diana
Bruce
```

---

## 6. Flights

The next clue was the thief wanting the **earliest flight out of Fiftyville the following day**.

I searched the passengers on flights leaving Fiftyville on July 29:

```sql
SELECT *
FROM passengers
WHERE flight_id IN (
    SELECT flights.id
    FROM flights
    JOIN airports
      ON flights.origin_airport_id = airports.id
    WHERE airports.city = "Fiftyville"
      AND flights.year = 2025
      AND flights.day = 29
      AND flights.month = 7
);
```

The relevant suspects were connected to flights going to:

```text
New York City
Boston
```

Diana took the Boston flight at **4:00 PM**, while Taylor and Bruce were on **flight 36 to New York City at 8:20 AM**.
Because the clue specifically mentioned the earliest flight, I excluded Diana and continued investigating Taylor and Bruce.

---

## 7. Comparing Car Exit Times

At this point, I compared the bakery security logs for Taylor and Bruce.

The records showed two relevant car exits:

* One car left at **10:18 AM**, only three minutes after the theft.
* The other left more than 20 minutes after the theft.

I then checked the two suspects individually.

Bruce's car matched the relevant timing:

```sql
SELECT *
FROM bakery_security_logs
WHERE year = 2025
  AND month = 7
  AND day = 28
  AND hour = 10
  AND activity = "exit"
  AND license_plate IN (
      SELECT license_plate
      FROM people
      WHERE name IN ("Bruce")
  );
```

The result matched the timing clue, leading me to identify **Bruce as the thief**.

Taylor's car did not match the required timing, so I excluded Taylor.

---

## 8. Finding the Accomplice

Finally, I searched for the person Bruce contacted in a short phone call:

```sql
SELECT name
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE caller = (
        SELECT phone_number
        FROM people
        WHERE name = "Bruce"
    )
    AND month = 7
    AND day = 28
    AND year = 2025
    AND duration < 60
);
```

The result identified **Robin** as the accomplice.

---

# 🧩 Final Solution

| Question       | Answer            |
| -------------- | ----------------- |
| 🕵️ Thief      | **Bruce**         |
| ✈️ Escape City | **New York City** |
| 📞 Accomplice  | **Robin**         |

These are the final answers recorded in my investigation log.

---

# 🧠 What I Learned

The biggest part of Fiftyville for me wasn't memorizing SQL syntax.

It was learning how to **turn clues into database questions**.

The investigation followed a pattern:

```text
Clue
 ↓
Question
 ↓
SQL Query
 ↓
Smaller Set of Possibilities
 ↓
New Clue
 ↓
New Query
```

I practiced working with:

* `SELECT`
* `WHERE`
* `JOIN`
* `IN`
* Subqueries
* Filtering
* String matching
* Date/time conditions
* Sorting and narrowing results
* Connecting information across multiple tables

More importantly, I learned to think of SQL as a **tool for reducing uncertainty** rather than just retrieving rows.

---

## 📁 Files

```text
.
├── README.md
├── log.sql
└── ...
```

The investigation log contains the SQL queries and reasoning used throughout the case.

---

## 🎓 Course

**CS50 — Introduction to Computer Science**

This project was part of my continued practice with **SQL, databases, relational data, and problem solving**.

## Status

**CASE CLOSED 🕵️**

Thief identified.
Escape city identified.
Accomplice identified.
