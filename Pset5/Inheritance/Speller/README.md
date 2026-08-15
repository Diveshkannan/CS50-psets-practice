# CS50 Speller — Hash Table Dictionary in C

Overview

This project implements the dictionary functionality for CS50's Speller problem in C. It loads a large dictionary into memory using a hash table, checks words efficiently for spelling mistakes, counts the number of words loaded, and safely unloads all dynamically allocated memory.

The project focuses on understanding hash tables, linked lists, pointers, dynamic memory allocation, file handling, string comparison, and algorithmic performance.

---

Features

- Written in C
- Hash table implementation using an array of linked lists
- 1,899 hash-table buckets
- Case-insensitive word checking using "strcasecmp()"
- Supports words containing apostrophes
- Dynamically allocates memory for every dictionary word
- Inserts new nodes at the front of each linked list
- Counts all loaded dictionary words
- Safely frees every allocated node during unload
- Handles hash collisions using separate chaining
- Uses "fread()" for dictionary file processing
- Includes memory-error handling
- Passed CS50's check50 tests
- Passed Valgrind memory checks
- Optimized for fast dictionary loading and word checking

---

Core Data Structure

Each dictionary word is stored inside a linked-list node:

- "word" stores the actual dictionary word.
- "next" stores the address of the next node in the same bucket.

The hash table contains 1,899 bucket pointers.

Each bucket can therefore point to a linked list containing all words that produce the same hash value.

---

Hash Table Concept

The program converts each word into a bucket number using the "hash()" function.

The hash function considers:

- Word length
- First character
- Second character
- Apostrophe handling

Short words and longer words are distributed across different regions of the hash table.

This reduces the number of words that "check()" has to search inside a bucket.

The program uses separate chaining to handle collisions.

---

Loading the Dictionary

The "load()" function:

1. Initializes every hash-table bucket to "NULL".
2. Opens the dictionary file.
3. Reads the dictionary character by character using "fread()".
4. Builds each word inside a temporary character array.
5. When a newline is reached, the completed word is hashed.
6. Memory is allocated for a new node using "malloc()".
7. The word is copied into the node.
8. The node is inserted into the beginning of the appropriate bucket.
9. The process continues until the entire dictionary is loaded.

The key linked-list insertion is:

    n->next = table[value];
    table[value] = n;

This inserts the new node at the front of the bucket's linked list.

---

Why Insert at the Front?

An important part of this project was understanding why inserting at the front is useful.

Initially, I considered keeping a "tail" pointer and appending every new word to the end of a linked list.

The problem was that one global tail pointer does not represent every bucket. Different words can hash to different buckets, so the tail for one bucket cannot safely be used for another bucket.

Front insertion avoids this problem.

For every new node:

    n->next = table[value];
    table[value] = n;

The current first node becomes the second node, and the new node becomes the first.

This takes constant time, O(1), without traversing the entire linked list.

This became one of the most important linked-list lessons from the project.

---

Checking Words

The "check()" function:

1. Hashes the word.
2. Uses the resulting value to select one bucket.
3. Traverses only that bucket's linked list.
4. Compares the input word against each stored word using "strcasecmp()".
5. Returns "true" if a match is found.
6. Returns "false" otherwise.

This avoids scanning all 143,091 dictionary words for every word in the text.

---

Collision Handling

Different words can produce the same hash value.

Instead of overwriting an existing node, the program stores colliding words in a linked list inside the same bucket.

Conceptually:

    table[100]
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

This technique is called separate chaining.

---

Counting the Dictionary

The "size()" function traverses every bucket and every linked list.

For every node encountered, the counter increases by one.

This allows the program to report the total number of words loaded into memory.

---

Unloading Memory

The "unload()" function prevents memory leaks.

For every bucket:

1. Start at the first node.
2. Save the address of the next node.
3. Free the current node.
4. Move to the saved next node.
5. Continue until the linked list is empty.

The important pattern is:

    tmp = ptr->next;
    free(ptr);
    ptr = tmp;

The next pointer must be saved before freeing the current node because accessing a freed node would be invalid.

---

Performance

Final implementation:

- Hash table buckets: 1,899
- Dictionary words loaded: 143,091
- Misspelled words: 955
- Load time: approximately 0.03 seconds
- Check time: approximately 0.06 seconds
- Total time: approximately 0.10 seconds

The implementation achieved fast performance while using significantly fewer buckets than some earlier versions.

---

Optimization Experiment

During development, I experimented with different numbers of buckets.

    18,279 buckets
    - Very fast
    - Fewer collisions
    - More memory used by the bucket array

    2,730 buckets
    - Correct
    - Slightly more collisions
    - Less bucket-array memory

    1,873 buckets
    - Correct
    - Very fast
    - More collisions than the larger table
    - Much smaller bucket array

    Final version: 1,899 buckets

The experiment helped demonstrate the real trade-off between space and time in hash-table design.

More buckets generally reduce collisions, but the hash-table array itself consumes more memory.

Fewer buckets reduce the table's memory usage but can create longer linked lists, increasing the amount of work required by "check()".

---

Memory Management

The project uses dynamic memory allocation for dictionary nodes.

Every successful "malloc()" creates a node that must eventually be released.

The program therefore provides a complete allocation/deallocation cycle:

    malloc()
       ↓
    store word
       ↓
    insert into hash table
       ↓
    use during check()
       ↓
    unload()
       ↓
    free()

The implementation also attempts to clean up allocated nodes if a memory allocation fails while loading.

---

Error Handling

The program checks whether the dictionary file was successfully opened.

It also checks whether "malloc()" successfully allocated memory.

If memory allocation fails, the program calls "unload()" before returning failure, helping prevent memory leaks.

---

CS50 Validation

The implementation passed the CS50 Speller check50 tests, including:

- Basic dictionary handling
- One-character words
- Maximum-length words
- Apostrophe handling
- Case-insensitive checking
- Substring handling
- Large dictionaries with hash collisions
- Memory-error testing with Valgrind

This confirmed that the implementation was not only fast, but also functionally correct for the required test cases.

---

What I Learned

This project strengthened my understanding of:

- Hash tables
- Hash functions
- Separate chaining
- Linked lists
- Pointers
- Pointer-to-pointer relationships
- Dynamic memory allocation
- malloc() and free()
- Dangling-pointer risks
- File handling with FILE*
- fread()
- Character processing
- String comparison
- Collision handling
- Time complexity
- Space complexity
- Memory leaks
- Data-structure design
- Optimization trade-offs

Most importantly, I learned that a data structure is not just about making code work. The way data is organized directly affects both runtime and memory usage.

---

Personal Learning Note

One of the hardest parts of this project was not writing the syntax itself, but developing the mental model for how the hash table and linked lists interact.

I initially tried using a tail pointer to append nodes at the end of a bucket. Later, I realized that a single tail pointer could not represent multiple different buckets correctly.

I then learned the front-insertion approach:

    n->next = table[value];
    table[value] = n;

I did not initially think of this reverse/front-insertion approach completely on my own and received a clue to consider it. However, the important part was understanding why it works, why the earlier tail approach failed, and how every bucket maintains its own linked-list structure.

That became a major lesson in thinking about data structures rather than simply memorizing an implementation.

---

Author's Note

Built as part of my CS50 learning journey.

This project was one of my deeper exercises in understanding how hash tables, linked lists, pointers, dynamic memory, file handling, and algorithmic optimization work together in a real C program.

The biggest takeaway was that debugging was not just about fixing individual lines of code. It was about building the correct mental model of the data structure, finding where my assumptions were wrong, and then redesigning the implementation around that understanding.
