Caesar Cipher (CS50)

Overview

This program implements a Caesar cipher, a simple encryption technique that shifts each letter in a given text by a specified key. The program takes a numeric key as a command-line argument and applies it to the user’s input text while preserving the case and non-alphabetical characters.

This project was built as part of my CS50 journey, focusing on command-line arguments, string manipulation, input validation, and clean logical structuring in C.

---

How It Works

1. The program expects exactly one command-line argument:
   
   - A positive integer key.

2. It validates the key:
   
   - Ensures all characters in the argument are digits.
   - Converts the argument to an integer.
   - Ensures the key is greater than 0.

3. The key is normalized:
   
   - "k = key % 26" to handle large values efficiently.

4. The program takes plaintext input from the user.

5. It iterates through each character of the text:
   
   - If uppercase → shifts within "'A'" to "'Z'"
   - If lowercase → shifts within "'a'" to "'z'"
   - If non-alphabetical → leaves unchanged

6. The encrypted result (ciphertext) is printed.

---

Features

- Validates command-line input strictly (digits only)
- Handles large keys using modulo optimization
- Preserves:
  - Uppercase letters
  - Lowercase letters
  - Spaces and punctuation
- Efficient iteration (no repeated "strlen" calls)
- Clean and readable conditional structure

---

What I Learned

- Working with command-line arguments ("argc", "argv")
- Validating input using "isdigit"
- Converting strings to integers using "atoi"
- Applying modular arithmetic for cyclic shifts
- Handling ASCII values for character transformation
- Writing efficient loops and avoiding redundant operations
- Refining code step-by-step for correctness and clarity

---

Limitations

- Only accepts positive integer keys (negative shifts not supported)
- Uses "atoi", which assumes prior validation (safe here but limited)
- Does not support non-English alphabets

---

Future Improvements

- Support negative keys (reverse shifting)
- Replace "atoi" with safer parsing methods
- Combine uppercase and lowercase logic for more compact code
- Extend cipher to support different character sets

---

Conclusion

This project demonstrates my ability to move beyond basic coding into structured problem solving. I started with a simple working version and iteratively improved it by adding validation, handling edge cases, and optimizing logic.

It reflects my growth in thinking, debugging, and refining code—an important step toward writing reliable and efficient programs.

More advanced and refined implementations will follow as I continue learning.