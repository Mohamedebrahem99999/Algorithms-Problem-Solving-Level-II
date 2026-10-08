
# Problem: Floor Numbers (My Floor)

Write a custom function to find the floor of a floating-point number without using C++ built-in `std::floor` function.

---

### Definition

The **floor** of a number is the largest integer less than or equal to that number:

- For positive numbers: truncating the decimal part is sufficient.
- For negative numbers (with a fraction): truncating rounds towards zero, so we must subtract `1` to move to the smaller integer.

---

### Examples

#### Example 1:

- **Input:** `10.7`
- **Output:**
  ```
  My MyFloor Result : 10
  C++ floor Result   : 10
  ```

### Example 2:

**Input:** 10.3

**Output:**

```
My MyFloor Result : 10
C++ floor Result   : 10
```

### Example 3:

**Input:** -10.3

**Output:**

```Plaintext
My MyFloor Result : -11
C++ floor Result   : -11
```
