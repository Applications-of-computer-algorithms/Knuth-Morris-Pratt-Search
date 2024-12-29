# Knuth-Morris-Pratt (KMP) Algorithm for Pattern Matching

## Overview
This program implements the **Knuth-Morris-Pratt (KMP)** string matching algorithm in C++. The KMP algorithm efficiently searches for occurrences of a "pattern" string within a larger "text" string. By utilizing a precomputed "failure function" (the KMP "next" array), it minimizes unnecessary comparisons, making it an optimal choice for text search problems.

### How It Works
1. **Failure Function Calculation:**
   The failure function ("next" array) is calculated for the pattern. This helps the algorithm determine how much to shift the pattern when a mismatch occurs.

2. **Pattern Matching:**
   The algorithm traverses the text, comparing the pattern to substrings of the text. If a mismatch occurs, it uses the failure function to skip unnecessary comparisons.

3. **Output:**
   - The program outputs the "next" array for debugging purposes.
   - It outputs the starting indices of all matches of the pattern in the text.

---

## Input and Output

### Input
The program requires **two parameters** passed as command-line arguments:
1. **Pattern to Search:** The string pattern to search for in the text.
2. **File Name:** The name of the file containing the text to search within. This file must be in the same directory as the program.

#### Example Input File (`example_text.txt`):
```text
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
```

### Output
1. The **next array** (failure function) is written to `out.txt`.
2. The **starting indices** of the matches in the text are also written to `out.txt`.

#### Example Output (`out.txt`):
For the pattern `dolor`:
```text
-1 0 0 0 0
12 84
```
- The first line is the "next" array.
- The second line contains the indices where the pattern `dolor` is found in the text.

---

## How to Use

### Compilation
Use any C++ compiler to compile the program. For example, with `g++`:
```bash
g++ -o kmp KMP.cpp
```

### Running the Program
Run the compiled program with the following command-line arguments:
1. The pattern to search for (enclosed in quotes if it contains spaces).
2. The name of the input text file.

Example:
```bash
./kmp dolor example_text.txt
```

### Output Location
The results are written to a file named `out.txt` in the same directory as the program.

---

## Program Structure
- **`readInputText` Function:** Reads the input file and returns its contents as a string.
- **`outputKMPNextArray` Function:** Writes the KMP "next" array to `out.txt`.
- **`KMP` Function:** Implements the Knuth-Morris-Pratt algorithm to find matches and output their starting indices.
- **`main` Function:** Handles input arguments, reads the file, and executes the KMP algorithm.

---

## Debugging and Errors
1. **Error Codes:**
   - `-1`: Incorrect number of command-line arguments.
   - `-2`: Failed to open the output file.
2. **Common Issues:**
   - Ensure the input text file exists in the same directory as the program.
   - Verify that the correct file name is provided as the second argument.

---

## Theory: Knuth-Morris-Pratt Algorithm
The KMP algorithm solves the problem of finding all occurrences of a pattern in a text by avoiding redundant comparisons. It achieves this by precomputing a **failure function** (`next` array):
- The `next` array indicates the length of the longest prefix of the pattern that is also a suffix for each position in the pattern.
- During a mismatch, the `next` array determines the next alignment of the pattern, ensuring that no unnecessary comparisons are made.

### Time Complexity
- **Preprocessing (Failure Function):** O(m), where `m` is the length of the pattern.
- **Pattern Matching:** O(n), where `n` is the length of the text.

This makes the overall complexity O(n + m).

---

## Example Walkthrough

### Input
- **Pattern:** `dolor`
- **Text File:** Contains the sentence:
  ```text
  Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
  ```

### Execution
1. Precompute the failure function (`next` array) for `dolor`: `[-1, 0, 0, 0, 0]`.
2. Scan the text for matches:
   - Found match at index `12`.
   - Found match at index `84`.

### Output
```text
-1 0 0 0 0
12 84
```

---

## Additional Notes
- The program is case-sensitive. To perform a case-insensitive search, convert the text and pattern to lowercase.
- Extendable to handle large files and patterns by optimizing memory usage or using alternative file handling techniques.
