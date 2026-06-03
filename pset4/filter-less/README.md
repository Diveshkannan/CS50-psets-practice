## Image Filters in C (CS50 Practice)

### Overview
- This project implements basic image processing filters in C as part of my CS50 learning journey.
- It demonstrates how images are processed at the pixel level using 2D arrays and structs.
- The program applies transformations directly on RGB values of bitmap images.

---

### Features
- Written in C (CS50-style structured programming)
- Uses 2D arrays and RGBTRIPLE struct for pixel representation
- Implements four core image filters:
  - Grayscale
  - Sepia
  - Horizontal Reflection
  - Blur
- Uses safe memory handling with a copy buffer for image processing
- Handles edge cases (corners and borders) properly in blur logic

---

### Filters Implemented

- Grayscale:
  - Converts image into shades of gray by averaging RGB values of each pixel

- Sepia:
  - Applies weighted RGB transformation for warm vintage effect
  - Ensures pixel values are capped at 255

- Reflection:
  - Horizontally flips the image by swapping pixels in each row

- Blur:
  - Applies a box blur using surrounding pixels (3x3 grid)
  - Uses a copy of the image to avoid overwriting original data during calculation
  - Handles boundary pixels safely using conditional checks

---

### Key Concepts Learned
- 2D array traversal and nested loops
- Struct usage in C (RGBTRIPLE)
- Memory safety using auxiliary arrays
- Edge-case handling in grid-based problems
- Basic image processing logic at pixel level
- Algorithmic thinking for real-world data transformation

---

### Technical Notes
- Blur uses a separate copy of the image to preserve original pixel values during computation
- Boundary conditions are checked using:
  (k >= 0 && l >= 0 && k < height && l < width)
- Pixel values are accumulated and averaged using float division and rounded values

---

### Author’s Note
- Built as part of CS50 learning journey
- Focused on understanding how image filters work internally
- Emphasis on logic building, not just completing the problem
- Improved understanding of algorithms, memory handling, and structured programming
