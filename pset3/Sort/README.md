Sorting Algorithms Identification (CS50 - pset3)

Overview

This project focuses on identifying sorting algorithms based on their runtime behavior rather than directly inspecting their implementation. By analyzing how different algorithms perform under various input conditions, the program deduces whether a given sort corresponds to Bubble Sort, Selection Sort, or Merge Sort.

This exercise strengthens algorithmic intuition, time complexity understanding, and analytical thinking—key skills for deeper computer science problem solving.

---

Algorithms Identified

Bubble Sort
Selection Sort
Merge Sort

Each algorithm exhibits distinct performance characteristics, which were used to classify them accurately.

---

Methodology

Instead of reading the algorithm code, the identification was done by observing:

1. Execution time across different input types:
   
   - Random order
   - Reverse order
   - Already sorted

2. Variation in performance:
   
   - Large variation → inefficient comparisons/swaps (Bubble Sort)
   - Consistent performance → predictable iteration (Selection Sort)
   - Fast and consistent → divide and conquer (Merge Sort)

---

Analysis & Reasoning

sort1 → Bubble Sort

- Takes significantly more time compared to others
- Shows large variation between random and reverse inputs
- Performs unnecessary comparisons even when already sorted

Conclusion: Behavior matches Bubble Sort’s inefficiency and sensitivity to input order.

---

sort2 → Merge Sort

- Fastest among all
- Performance remains consistent across all input types
- Efficient even for already sorted arrays

Conclusion: Matches Merge Sort’s divide-and-conquer efficiency with O(n log n) complexity.

---

sort3 → Selection Sort

- Moderate execution time
- Performance remains nearly the same regardless of input order
- Does fixed number of comparisons

Conclusion: Matches Selection Sort’s predictable O(n²) behavior.

---

Key Concepts Learned

- Time complexity analysis through observation
- Difference between O(n²) and O(n log n) algorithms
- Input sensitivity vs algorithm stability
- Identifying algorithms without direct code access
- Strengthening logical reasoning over memorization

---

Why This Matters

This project goes beyond implementation. It trains the ability to:

- Recognize patterns in algorithm behavior
- Think like a problem solver rather than a code copier
- Build intuition for performance optimization

These skills are essential for advanced topics like system design, competitive programming, and technical interviews.

---

Example Insight

- If execution time varies significantly with input → likely Bubble Sort
- If execution time is constant but slow → likely Selection Sort
- If execution time is consistently fast → likely Merge Sort

---

Author's Note

This work was completed through independent analysis without external help. Instead of relying on predefined answers, the approach was to observe, hypothesize, and verify.

This reflects a shift from passive learning to active problem solving—an important step in becoming a strong programmer.

More refined and deeper algorithmic explorations will follow as part of continuous learning.