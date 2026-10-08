# Problem: Search in Array

Write a program to fill an array with a max size of 100 with random numbers from 1 to 100. Read a number and return its index in the array if found, otherwise return -1.

## Example 1

**Input:**

```
10
```

**Output:**

```
Array 1 elements:
80 79 12 80 81 29 3 37 25 91

Please enter a number to search for?
12

Number you are looking for is: 12
The number found at position: 2
The number found its order: 3
```

## Example 2

**Input:**

```
10
```

**Output:**

```
Array 1 elements:
80 79 12 80 81 29 3 37 25 91

Please enter a number to search for?
55

Number you are looking for is: 55
The number is not found :-(
```

## Notes

- The array size is entered by the user (max 100).
- Array elements are random numbers between 1 and 100.
- **Position** is the 0-based index.
- **Order** is the 1-based position (index + 1).
- If the number is not found, print `The number is not found :-(` and return -1.
