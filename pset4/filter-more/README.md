## CS50 Filter More – Image Processing in C


---



## Overview

This project implements four fundamental image-processing filters in C as part of Harvard University's CS50 Introduction to Computer Science course. The program operates directly on BMP image data through RGB pixel manipulation and demonstrates practical applications of arrays, nested loops, image convolution, mathematical transformations, and algorithmic problem solving.
The project includes implementations of Grayscale, Reflect, Blur, and Edge Detection filters. Each filter was built by manually manipulating pixel values without relying on external image-processing libraries, providing a deeper understanding of how digital images are represented and processed at the pixel level.



---



## Features


Direct RGB pixel manipulation in C
Grayscale image conversion
Horizontal image reflection
Box blur implementation using neighboring pixels
Sobel edge detection using convolution kernels
Boundary-safe neighbor traversal
Gradient magnitude calculations using square roots
RGB value clamping to maintain valid color ranges
Image-copying strategy to preserve original pixel data during transformations
Full compatibility with CS50 Filter More automated testing



---



## Grayscale Filter



The grayscale filter converts a color image into shades of gray by averaging the red, green, and blue components of every pixel. For each pixel, the three color channels are summed, divided by three, rounded to the nearest integer, and then assigned back to all three channels. This produces a neutral grayscale image while preserving brightness information.


---



## Reflect Filter


The reflection filter mirrors the image horizontally. For every row in the image, pixels on the left side are swapped with their corresponding pixels on the right side using temporary storage variables. The process continues until the midpoint of the row is reached, resulting in a horizontally flipped image without requiring additional memory.


---



## Blur Filter


The blur filter applies a box blur effect by averaging neighboring pixels. To prevent modifications from affecting future calculations, a complete copy of the original image is created before processing begins. For every pixel, the algorithm examines the surrounding 3×3 neighborhood, sums the RGB values of all valid neighboring pixels, counts how many neighbors exist, and computes the rounded average for each color channel. Boundary checks ensure that edge and corner pixels are handled safely without accessing memory outside the image.


---


## Edge Detection Filter



The edge detection filter uses the Sobel Operator to identify areas of rapid intensity change within an image. Two convolution kernels, Gx and Gy, are applied to measure horizontal and vertical gradients respectively. For every pixel, the algorithm traverses the surrounding 3×3 neighborhood and calculates separate gradient values for the red, green, and blue channels.
After computing the horizontal and vertical gradients, the final edge strength is calculated using the gradient magnitude formula:
Magnitude = √(Gx² + Gy²)
Since Sobel calculations can produce values larger than the maximum RGB value, each result is capped at 255 before being stored. This ensures that all pixel values remain within the valid RGB range.

---



## Custom Kernel Mapping Strategy


One unique aspect of this implementation is the custom coordinate-mapping technique used during Sobel convolution. Instead of directly calculating kernel indices through the more common offset approach, neighborhood coordinates are mapped into kernel positions using the expressions:
row = abs((i - k) - 1)
column = abs((j - l) - 1)
This mapping successfully converts neighboring pixel coordinates into their corresponding Sobel kernel locations and was independently derived during development. The approach was validated through CS50's complete automated testing suite and demonstrates an alternative method for kernel indexing during convolution operations.

---



## Technical Concepts Demonstrated



This project demonstrates practical understanding of:
Two-dimensional arrays
Struct-based image representation
RGB color models
Nested loop traversal
Memory-safe boundary checking
Image copying strategies
Convolution operations
Sobel edge detection
Mathematical transformations
Algorithmic problem solving
Debugging and verification techniques


---


## Complexity Analysis
The grayscale and reflection filters operate in O(height × width) time because each pixel is processed once. The blur and edge detection filters operate in O(height × width × 9) time because each pixel requires examination of a 3×3 neighborhood. Since the neighborhood size remains constant, both filters effectively scale linearly with image size.

---


## Results  


The implementation successfully passes all CS50 Filter More tests, including grayscale conversion, horizontal reflection, blur processing, and Sobel edge detection for center, edge, and corner pixels. The project demonstrates the ability to transform mathematical image-processing concepts into working C code while maintaining correctness, efficiency, and memory safety.

---


## Author's Note


This project was built as part of my journey in learning computer science, algorithms, and low-level image processing. Through implementing these filters, I gained hands-on experience with pixel manipulation, convolution operations, memory management, mathematical modeling, and debugging complex nested-loop logic. The project represents an important step from writing simple programs toward building algorithm-driven systems that operate directly on structured data. :::