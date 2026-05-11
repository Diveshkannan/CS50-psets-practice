WAV Audio Volume Modifier in C

Overview

This program modifies the volume of a ".wav" audio file by scaling each audio sample using a user-provided factor. Built in C as part of Harvard’s CS50 Week 4 (Memory), the project introduces low-level file handling, binary data processing, buffers, and memory-based file manipulation.

The program reads the original WAV file, copies its header, processes every 16-bit audio sample, adjusts the volume, and writes the modified audio into a new output file.

---

Features

- Built entirely in C
- Works with ".wav" audio files
- Reads and writes binary file data using "fread()" and "fwrite()"
- Uses buffers for efficient memory-based processing
- Supports increasing or decreasing audio volume
- Command-line based execution
- Demonstrates low-level memory and file manipulation concepts

---

How It Works

1. Opens the original WAV audio file.
2. Reads the 44-byte WAV header.
3. Copies the header into a new output file.
4. Reads audio samples one at a time using a buffer.
5. Multiplies each sample by a scaling factor.
6. Writes modified samples into the output file.
7. Produces a new WAV file with adjusted volume.

---

Concepts Used

- Binary file I/O
- Buffers
- Memory addresses and pointers
- Arrays and byte-level manipulation
- "uint8_t" and "int16_t"
- Command-line arguments
- File streaming

---

Example Usage

./volume input.wav output.wav 2.0

- "2.0" → doubles the volume
- "0.5" → reduces volume by half

---

Technologies

- Language: C
- Compiler: clang / gcc
- Concepts: Memory, File Handling, Audio Processing

---

Author's Note

This project was built during my CS50 learning journey while exploring how computers handle memory and binary files internally. It helped me understand buffers, pointers, file streams, and low-level data processing through a real-world audio manipulation problem.