## 💳 Credit Card Validator (CS50 Practice)

This program validates credit card numbers using the Luhn algorithm and identifies the card type (AMEX, VISA, or MASTERCARD). It ensures that the number entered by the user is structurally valid before classifying it.

## 📜 Description

- Prompts the user to enter a card number.

- Applies the Luhn algorithm to check validity:

- Doubles every other digit starting from the second-to-last.

- Adds the sum of digits to the untouched digits.

- Valid if the total modulo 10 equals zero.

- Determines card type based on length and starting digits:

- AMEX → 15 digits, starts with 34 or 37.

- VISA → 13 or 16 digits, starts with 4.

- MASTERCARD → 16 digits, starts with 51–55.

- Prints the card type or INVALID if checks fail.

## 💻 Example Run

Card number: 378282246310005
AMEX

Card number: 4111111111111111
VISA

Card number: 5105105105105100
MASTERCARD

Card number: 1234567890
INVALID

## ✍️ Author’s Comments

This program is part of my CS50 mastery journey. I am doing this to master programming fundamentals and sharpen my ability to solve real-world problems with code. It strengthened my understanding of:

🔹 Input validation and error checking.

🔹 Implementing the Luhn algorithm step by step.

🔹 Using string operations to classify card types.

I enjoyed building this because:

It combined mathematical logic with string analysis.

It gave me confidence in handling both numbers and text in C.

It showed me how algorithms can be applied to everyday systems like banking.

⚖️ License

This project is licensed under the MIT License — you are free to use, modify, and distribute this code, provided that proper credit is given and the license terms are respected.