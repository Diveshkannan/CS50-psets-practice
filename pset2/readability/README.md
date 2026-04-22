# Readability Analyzer (CS50)

## Overview
This program analyzes a given text and determines its readability grade using the Coleman-Liau Index. It calculates the number of letters, words, and sentences, and then estimates the U.S. grade level required to understand the text.

This project was built as part of my learning journey through CS50, focusing on string processing, logical problem solving, and code structuring in C.

---

## How It Works

1. The program takes a string input from the user.
2. It iterates through each character to count:
   - Letters (using isalpha)
   - Words (based on spaces and next character validation)
   - Sentences (based on '.', '?', '!')
3. It calculates:
   - Average number of letters per 100 words (L)
   - Average number of sentences per 100 words (S)
4. It applies the Coleman-Liau formula:

   Index = 0.0588 * L - 0.296 * S - 15.8

5. The result is rounded and displayed as a grade level.

---

## Features

- Handles empty input safely
- Avoids out-of-bounds access using proper conditions
- Modular design with separate functions:
  - `coleman_index()` for calculation
  - `result()` for output formatting
- Uses standard C libraries for robust character handling

---

## What I Learned

- Iterating through strings efficiently
- Handling edge cases in text processing
- Avoiding common errors like out-of-bounds access
- Structuring code into reusable functions
- Understanding how real-world text analysis works

---

## Limitations

- Not designed for complex linguistic accuracy, but works well for standard inputs

---

## Future Improvements

- Improve word detection logic for better accuracy
- Handle multiple spaces and unusual formatting
- Expand punctuation handling
- Optimize logic for cleaner and more robust implementation

---

## Conclusion

This project represents a strong step in my journey from basic programming to building structured and logical solutions. While not perfect, it reflects my ability to think, iterate, and improve through practice.

More refined versions will be built as I continue learning.
