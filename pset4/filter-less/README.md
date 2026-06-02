# Image Filter Practice (CS50-inspired)

## This project implements several image-processing filters in C:

- Grayscale
- Sepia
- Horizontal Reflection
- Blur

## Concepts practiced:
- 2D arrays
- Structs
- Memory handling
- Nested loops
- Edge-case handling
- Image processing fundamentals

One challenge I faced was implementing blur correctly. Initially I modified pixels directly, which caused later calculations to use already-modified values. I solved this by creating a copy of the original image before applying the blur calculations.
