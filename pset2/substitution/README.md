# Substitution Cipher (CS50)

## Overview

This program implements a substitution cipher, where each letter in the plaintext is replaced with a corresponding letter from a user-provided key. Unlike the Caesar cipher, which uses a fixed shift, this approach allows for a fully customizable mapping of all 26 letters.

This project was built as part of my CS50 journey, focusing on input validation, algorithm design, and writing structured, modular C code.

---

## How It Works

1. The program expects exactly one command-line argument:
   
   - A key containing 26 unique alphabetic characters.

2. It validates the key:
   
   - Ensures the key length is exactly 26.
   - Ensures all characters are alphabetic.
   - Ensures no duplicate characters exist (case-insensitive).

3. The program takes plaintext input from the user.

4. It iterates through each character of the input:
   
   - If uppercase → maps using the key and preserves uppercase.
   - If lowercase → maps using the key and preserves lowercase.
   - If non-alphabetical → leaves unchanged.

5. The transformed text is printed as ciphertext.

---

## Features

- Strict key validation:
  - Exactly 26 characters
  - Alphabetic characters only
  - No duplicates (efficient O(n) check using boolean array)

- Preserves:
  - Uppercase letters
  - Lowercase letters
  - Spaces and punctuation

- Efficient implementation:
  - Single-pass validation
  - No unnecessary recomputation
  - Clean modular design with separate functions

---

## What I Learned

- Designing modular programs using functions (`validate_key`, `ciphertext`)
- Validating complex input conditions efficiently
- Using boolean arrays for O(n) duplicate detection
- Working with ASCII values for character mapping
- Preserving character case during transformations
- Structuring code for readability and maintainability

---

## Limitations

- Only supports English alphabet (A–Z)
- Assumes standard ASCII input
- Does not handle extended Unicode characters

---

## Future Improvements

- Support for extended character sets (Unicode)
- More compact transformation logic
- Improved error messages and user interaction
- Refactoring for even cleaner abstraction

---

## Conclusion

This project represents a step forward from simple transformations to structured problem-solving. I moved beyond basic implementation to designing a clean, modular solution with efficient validation and clear logic.

It reflects my progress in thinking, debugging, and writing maintainable C programs.

More advanced implementations will follow as I continue learning.