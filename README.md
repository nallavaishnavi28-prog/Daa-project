# 🔍 KMP String Matching Algorithm in C++

This project implements the **Knuth-Morris-Pratt (KMP) Algorithm** for efficient pattern searching in a given text. It avoids redundant comparisons by using a preprocessing step called the **LPS (Longest Prefix Suffix) array**.

---

## 📌 Features

- Efficient pattern searching using KMP algorithm
- Preprocessing with LPS (Longest Prefix Suffix) table
- Handles text and pattern with spaces
- Displays:
  - LPS table
  - All matching indices of pattern in text

---

## 🧠 Algorithm Used

### 1. LPS Array
- Computes the longest proper prefix which is also a suffix
- Helps in skipping unnecessary comparisons

### 2. KMP Search
- Uses LPS array to perform pattern matching in **O(n + m)** time complexity

---

## 🛠️ Technologies Used
- C++
- STL (Standard Template Library)

- C++
- STL (Standard Template Library)
