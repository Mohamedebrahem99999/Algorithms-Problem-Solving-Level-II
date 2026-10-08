# Problem: Ceil Numbers (My Ceil)

Write a custom function to find the ceil of a floating-point number without using C++ built-in `std::ceil` function.

---

### Definition

The **ceil** of a number is the smallest integer greater than or equal to that number:

- For positive numbers with a fraction: we must add `1` to move to the next larger integer.
- For negative numbers (or any numbers without a fraction): truncating the decimal part via standard integer casting is sufficient (e.g., `int(-10.7)` yields `-10`).

---

#### Examples

##### Example 1:

- **Input:** `10.7`
- **Output:**
  ```text
  My MyCeil Result : 11
  C++ Ceil Result   : 11
  ```

##### Example 2:

**Input:**

```
Input: -10.7
```

**Output:**

```Plaintext
My MyCeil Result : -10
C++ Ceil Result   : -10
```
