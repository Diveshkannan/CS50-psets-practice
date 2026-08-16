# CS50 Speller — Hash Table Dictionary in C

## Overview

This project implements the dictionary functionality for CS50's Speller problem in C.

The program loads a large dictionary into memory using a hash table whose buckets contain linked lists. It can efficiently check words for spelling mistakes, count the number of loaded words, and safely release all dynamically allocated memory.

The project focuses on understanding hash tables, hash functions, linked lists, pointers, dynamic memory allocation, file handling, string processing, collision handling, and the practical trade-off between time and space.

---

## Features

- Written in C
- Hash table implemented using an array of linked lists
- 1,899 hash-table buckets
- Custom hash function based on word length and the first two characters
- Case-insensitive word checking using `strcasecmp()`
- Supports words containing apostrophes
- Dynamically allocates memory for dictionary nodes
- Uses separate chaining to handle hash collisions
- Inserts new nodes at the front of each linked list
- Counts all words loaded into memory
- Safely frees allocated nodes during `unload()`
- Uses `fread()` for dictionary file processing
- Handles `malloc()` failure
- Passed CS50's `check50` tests
- Passed memory-error checks with Valgrind
- Achieved fast dictionary loading and word checking

---

## Core Data Structure

Each dictionary word is stored inside a linked-list node:

    typedef struct node
    {
        char word[LENGTH + 1];
        struct node *next;
    } node;

Each node contains:

- `word` — the dictionary word
- `next` — a pointer to the next node in the same bucket

The hash table contains 1,899 bucket pointers:

    node *table[N];

Each bucket can therefore point to a linked list containing all words that produce the same hash value.

---

## Hash Table Concept

The `hash()` function maps each word to a bucket number.

The hash function considers:

- Word length
- First character
- Second character
- Apostrophe handling

For one-character words, the first character determines the bucket.

For longer words, the word length creates a region of buckets, while the first two characters determine the position within that region.

Conceptually:

    word
      |
      v
    hash()
      |
      v
    bucket number
      |
      v
    table[bucket]
      |
      v
    linked list

This allows `check()` to search only one bucket instead of scanning the entire dictionary.

---

## Collision Handling

A hash function does not necessarily give every word a unique bucket.

When multiple words map to the same bucket, the program stores them in a linked list.

This technique is called **separate chaining**.

Conceptually:

    table[500]
        |
        v
      [word]
        |
        v
      [word]
        |
        v
      [word]
        |
       NULL

When a word is checked, only this particular chain needs to be searched.

---

## Loading the Dictionary

The `load()` function:

1. Initializes every bucket to `NULL`.
2. Opens the dictionary file.
3. Reads the file character by character using `fread()`.
4. Builds each word in a temporary character array.
5. Handles alphabetic characters and apostrophes.
6. Detects the end of each word using `'\n'`.
7. Hashes the completed word.
8. Allocates a new node using `malloc()`.
9. Copies the word into the node.
10. Inserts the node into the appropriate bucket.
11. Continues until the entire dictionary has been loaded.

The dictionary contains:

    143,091 words

---

## Front Insertion

One of the most important lessons from this project was understanding how to insert a node into a bucket efficiently.

The program uses:

    n->next = table[value];
    table[value] = n;

This inserts the new node at the beginning of the linked list.

Before insertion:

    table[value]
        |
        v
      [A]
        |
        v
      [B]
        |
       NULL

After inserting `n`:

    table[value]
        |
        v
      [N]
        |
        v
      [A]
        |
        v
      [B]
        |
       NULL

This takes **O(1)** time because the program does not need to traverse the existing linked list.

---

## Why the Front-Insertion Approach Mattered

During development, I initially considered using a tail pointer to append nodes to the end of linked lists.

The problem became clear when working with a hash table containing many buckets.

A single tail pointer cannot represent the end of every bucket.

For example:

    table[100] -> A -> B -> NULL
    table[500] -> C -> D -> NULL

The tail of bucket 100 is unrelated to the tail of bucket 500.

If one global tail pointer is reused for different buckets, it can point into the wrong linked list.

The front-insertion approach avoids this completely:

    n->next = table[value];
    table[value] = n;

The bucket itself always tells us where the current first node is.

This was one of the biggest conceptual lessons of the project: **the linked list belongs to the bucket, not to the entire hash table.**

---

## Checking Words

The `check()` function:

1. Hashes the input word.
2. Uses the resulting hash value to select one bucket.
3. Traverses that bucket's linked list.
4. Compares each stored word using `strcasecmp()`.
5. Returns `true` if a match is found.
6. Returns `false` otherwise.

The important loop is:

    for (node *ptr = table[value]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
    }

Because only one bucket is searched, the program avoids scanning all 143,091 dictionary words for every word in the text.

---

## Case-Insensitive Checking

The program uses:

    strcasecmp(word, ptr->word)

This allows words to be compared without considering uppercase/lowercase differences.

For example:

    hello
    Hello
    HELLO

are treated as the same word during checking.

---

## Apostrophe Handling

The dictionary loader explicitly accepts apostrophes after at least one character:

    else if (s == '\'' && index > 0)

This allows words such as:

    can't
    don't
    world's
    foo's

to be stored and checked correctly.

---

## Counting the Dictionary

The `size()` function traverses every bucket and every linked list.

For every node encountered, the counter is incremented.

Conceptually:

    for every bucket
        for every node in that bucket
            count++

The final dictionary size is:

    143,091 words

---

## Unloading Memory

The `unload()` function releases every dynamically allocated node.

For every bucket, it walks through the linked list and frees each node.

The important pattern is:

    tmp = ptr->next;
    free(ptr);
    ptr = tmp;

The next node's address is saved **before** freeing the current node.

This prevents the program from trying to access the `next` pointer of memory that has already been freed.

---

## Memory Management

Every successful:

    malloc(sizeof(node))

creates a dynamically allocated node.

Therefore every node must eventually be released.

The overall memory lifecycle is:

    malloc()
       |
       v
    create node
       |
       v
    insert into hash table
       |
       v
    use during check()
       |
       v
    unload()
       |
       v
    free()

The program also calls `unload()` if `malloc()` fails during dictionary loading.

---

## Performance

Final measured results:

    Hash-table buckets: 1,899
    Dictionary words loaded: 143,091
    Misspelled words: 955

    Load time: 0.04 seconds
    Check time: 0.10 seconds

The implementation completed the full Speller workload in approximately:

    0.14 seconds

The exact timing can vary between machines and runs.

---

## Hash-Table Optimization Experiment

A major part of this project was experimenting with different bucket counts.

I tested multiple designs instead of simply choosing a bucket count and stopping.

### 18,279 buckets

- Very fast
- Fewer collisions
- Larger bucket-array memory usage

### 2,730 buckets

- Correct
- Slightly more collisions
- Lower bucket-array memory usage

### 1,873 buckets

- Correct
- Very fast
- More collisions than the larger designs
- Significantly smaller bucket array

### Final checkpoint

    N = 1,899

The experiment demonstrated an important real-world trade-off:

**More buckets → generally fewer collisions → potentially faster lookup, but more memory for the table.**

**Fewer buckets → smaller table → potentially more collisions and longer linked lists.**

The goal was not simply to maximize the number of buckets. The goal was to find a reasonable balance between performance and memory usage.

---

## Complexity

Let:

- `N` = number of buckets
- `L` = length of a word
- `k` = number of words in the selected bucket

### Hashing

The hash function uses the word length and first two characters.

Ignoring the cost of `strlen()`, the actual mapping work is constant:

    O(1)

### Checking

The program searches one bucket rather than the entire dictionary.

Average-case behavior depends on how evenly the hash function distributes words.

With good distribution:

    Average: approximately O(1)

In the worst case, if many words collide into one bucket:

    O(k)

where `k` is the number of words in that bucket.

### Loading

Each dictionary word is read, hashed, allocated, and inserted.

The linked-list insertion itself is:

    O(1)

### Unloading

Every allocated node is visited exactly once:

    O(number of dictionary words)

---

## CS50 Validation

The implementation passed the CS50 Speller tests, including:

- Basic dictionary handling
- One-character words
- Maximum-length words
- Apostrophe handling
- Case-insensitive checking
- Substring handling
- Large dictionaries
- Hash collisions
- Memory-error testing

This confirmed that the implementation was functionally correct for the required CS50 test cases.

---

## What I Learned

This project strengthened my understanding of:

- Hash tables
- Hash functions
- Separate chaining
- Linked lists
- Pointers
- Dynamic memory allocation
- `malloc()` and `free()`
- File handling with `FILE *`
- `fread()`
- Character processing
- `strlen()`
- `strcasecmp()`
- Collision handling
- Time complexity
- Space complexity
- Memory leaks
- Pointer lifetime
- Data-structure design
- Performance measurement
- Space-time trade-offs

More importantly, I learned that understanding the **structure behind the code** matters more than memorizing a standard implementation.

---

## The Struggle Behind the Project

Speller was one of the harder CS50 problems for me.

There were multiple moments where the code worked, but my mental model did not.

I experimented with different hash functions and bucket counts, measured the performance, changed the design, broke assumptions, and rebuilt it.

One particularly important struggle was the linked-list insertion.

I initially thought about maintaining a tail pointer and appending nodes at the end. Eventually I understood why that approach becomes complicated across multiple buckets and why inserting at the front is naturally tied to the bucket itself.

The final insertion:

    n->next = table[value];
    table[value] = n;

looks simple, but understanding **why those two lines work** was much more valuable than simply writing them.

---

## Personal Learning Note

I did not arrive at every idea instantly.

There were failures, inefficient designs, wrong assumptions, and moments where I had to step away and think through the data structure again.

I also received a clue to consider reverse/front insertion during the process.

The important lesson was not pretending that every idea came from nowhere.

The important lesson was taking the clue, understanding it, testing it, and eventually being able to explain:

- Why the tail-pointer approach was problematic
- Why buckets need their own linked-list structure
- Why front insertion is O(1)
- How collisions are handled
- How the hash function determines the bucket
- How the bucket count affects memory and lookup performance

That is the part of the project I want to carry forward.

---

## Author's Note

Built as part of my CS50 learning journey.

This project was a major exercise in moving from simply writing C syntax to thinking about **data structures, memory, performance, and design decisions**.

The biggest takeaway from Speller was:

> **Making the program work is only the first step. Understanding why the design works is the real learning.**

Speller is now a completed checkpoint in my CS50 journey, while hash functions and hash-table design remain topics I plan to revisit and explore more deeply.
