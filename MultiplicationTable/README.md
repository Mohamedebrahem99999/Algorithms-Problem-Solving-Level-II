# Problem #1: Multiplication Table from 1 to 10

## **Solution Steps**

1. **Include Necessary Libraries:** Start by including the `<iostream>` library for input/output operations and use the standard namespace to simplify the code.
2. **Print Table Header:** Create a function (e.g., `PrintTableHeader`) to print the table's title and the horizontal column headers from 1 to 10, followed by a separator line.
3. **Format Column Separators:** Implement a helper function (e.g., `ColumSperator`) to return a formatted string that acts as a divider between the row number and the data; this function should adjust spacing for single-digit versus two-digit numbers to keep columns aligned.
4. **Implement Nested Loops for Multiplication:** Create a main printing function (e.g., `PrintMultiplicationTable`) that:
    * Calls the header function.
    * Uses an outer loop to iterate through rows 1 to 10.
    * Uses an inner loop to iterate through columns 1 to 10, calculating the product ($i \times j$) for each cell.
    * Prints the row index, the separator, and then the calculated products for that row before moving to a new line.
5. **Execute via Main:** Call the multiplication table function inside the `main()` function to run the program and return 0 upon successful completion.

---

### **C++ Implementation**

```cpp
#include <iostream>
#include <string>

using namespace std;

// Function to handle alignment of the vertical separator
string ColumnSeparator(int i) {
    if (i < 10)
        return "  |";
    else
        return " |";
}

// Function to print the table header and column numbers
void PrintTableHeader() {
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";
    cout << "\t";
    for (int i = 1; i <= 10; i++) {
        cout << i << "\t";
    }
    cout << "\n___________________________________________________________________________________\n";
}

// Main function to print the table using nested loops
void PrintMultiplicationTable() {
    PrintTableHeader();
    for (int i = 1; i <= 10; i++) {
        cout << " " << i << ColumnSeparator(i) << "\t";
        for (int j = 1; j <= 10; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

int main() {
    PrintMultiplicationTable();
    return 0;
}
