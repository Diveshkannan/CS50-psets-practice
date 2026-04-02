## 🎲 Scrabble Word Scorer (CS50 Practice)

This program simulates a simplified version of Scrabble. Two players enter words, 
the program calculates their scores based on Scrabble letter values, and declares 
the winner.

## 📜 Description
- Prompts Player 1 and Player 2 to enter words.
- Computes the score of each word using Scrabble rules:
  • Each letter has a predefined point value (A = 1, B = 3, Z = 10, etc.).
  • Non-alphabetic characters are ignored.
  • Case-insensitive scoring (uppercase and lowercase letters are treated the same).
- Compares the scores:
  • Prints "Player 1 wins!!" if Player 1 has the higher score.
  • Prints "Player 2 wins!!" if Player 2 has the higher score.
  • Prints "Tie!!" if both scores are equal.

## 💻 Example Run
Player 1: Hello
Player 2: World
Player 2 wins!!

Player 1: Cat
Player 2: Dog
Tie!!

## ✍️ Author’s Comments
This program is part of my CS50 learning journey. It helped me strengthen my 
understanding of:
🔹 Arrays and indexing.
🔹 String manipulation and iteration.
🔹 Using `ctype.h` functions like `isalpha()` and `toupper()`.
🔹 Implementing game logic with conditionals.

I enjoyed building this because:
- It connects programming with a real-world game I already know.
- It showed me how simple logic can create fun, interactive programs.
- It gave me confidence in handling both text and numeric data in C.

## ⚖️ License
This project is licensed under the MIT License — you are free to use, modify, 
and distribute this code, provided that proper credit is given and the license 
terms are respected.
