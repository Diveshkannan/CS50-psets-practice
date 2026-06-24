# JPEG Recovery from Raw Memory Card Data (CS50 Recover)

## Overview

This project implements a forensic JPEG recovery program in C.

The program scans a raw memory card image block by block, identifies the beginning of JPEG files using their signature bytes, reconstructs each image, and saves the recovered files with sequential names.

The implementation works directly with binary data and demonstrates low-level file handling, pattern recognition, memory management, and digital forensics concepts.

---

## Features

* Written entirely in C
* Processes raw binary memory card data
* Detects JPEG signatures using byte-level analysis
* Recovers multiple JPEG files from a single raw image
* Handles partial final blocks correctly
* Dynamically generates filenames (`000.jpg`, `001.jpg`, ...)
* Uses block-based recovery (512-byte sectors)
* Passes CS50's official correctness tests
* Passes Valgrind memory checks with zero leaks
* Uses manual pattern matching instead of hardcoded nested conditions
* Performs in-place recovery without storing the entire memory card in memory

---

## Digital Forensics Concept

Many memory cards store data in fixed-size blocks.

When a file is deleted, its contents often remain on the storage device until overwritten.

This program:

1. Reads the memory card image in 512-byte blocks.
2. Searches for JPEG header signatures.
3. Starts a new file whenever a JPEG header is found.
4. Continues writing subsequent blocks to the current image.
5. Stops only when another JPEG header is discovered or the data ends.
6. Recovers photographs that would otherwise appear lost.

---

## Example

Input:

Raw forensic image:

card.raw

Program:

./recover card.raw

Output:

000.jpg
001.jpg
002.jpg
...
049.jpg

Recovered photographs are written directly to the working directory.

---

## Technical Skills Demonstrated

* Binary file I/O
* Block-based processing
* Dynamic memory allocation
* Memory leak prevention
* Pattern matching
* File reconstruction
* Low-level debugging
* Digital forensics fundamentals
* Defensive programming techniques

---

## Challenges Solved During Development

* Understanding how `fread()` behaves when the final block is smaller than 512 bytes
* Correctly recovering the last JPEG image
* Handling filename generation for all recovered files
* Avoiding memory leaks
* Passing Valgrind verification
* Recovering images without relying on hardcoded image counts
* Working directly with raw bytes rather than text data

---

## Author's Note

This project was completed as part of the CS50 Recover problem set.

The most valuable lesson was not recovering JPEGs, but learning how to reason about binary data, file pointers, block-based storage, and debugging complex logic step by step.

The final solution was developed through repeated testing, experimentation, and independent problem solving, resulting in a fully working forensic recovery program that passes both correctness and memory-safety verification.
