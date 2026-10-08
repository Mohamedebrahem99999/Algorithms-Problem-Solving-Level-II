# Print Prime Numbers From 1 to N

## Problem Statement

Write a program that prompts the user to enter a positive number `N`, then prints **all prime numbers from 1 to N** (inclusive), each on a new line.

### Requirements

- The program must keep asking for input until the user enters a **positive number** (numbers ≤ 0 are rejected and the prompt repeats).
- A number is **prime** if it is greater than 1 and has no divisors other than 1 and itself.
- The program should print every prime number in the range `[1, N]`, one per line.

### Example

**Input:**
```
Enter a number to stop at
20
```

**Output:**
```
2
3
5
7
11
13
17
19
```

### Notes

- 0 and 1 are **not** prime numbers.
- An efficient primality check only needs to test divisors up to `√Number` (i.e., loop while `i * i <= Number`), instead of checking all the way up to `Number`.
