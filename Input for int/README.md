C Input Validation using "scanf()" and "getchar()"

Overview

This small C program demonstrates how to safely handle invalid user input while taking integers from the user.

When using "scanf("%i", &number)", entering characters like letters can leave invalid data inside the input buffer, causing unexpected behavior or infinite loops.

This program fixes that problem using:

- "scanf()"
- "getchar()"
- buffer clearing logic
- loops and conditions

---

What I Learned

- How "scanf()" works internally
- Why invalid input crashes or breaks programs
- How the input buffer stores leftover characters
- How "getchar()" can clear invalid input
- Basic input validation techniques in C

---

Program Features

- Accepts only valid integer input
- Detects invalid input
- Clears invalid characters from the input buffer
- Re-prompts the user until correct input is given

---


Example Output

Number:abc
It's invalid
Number:45
Number:45

---

Concepts Used

- Variables
- Loops
- Conditions
- Input validation
- Standard input/output
- Buffer handling

---

Notes

This project was created while learning C through CS50 and experimenting with input validation and error handling.
