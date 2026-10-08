#include "../NumberTheory.h"
#include "../input.h"
#include "../Array.h"
#include <vector>
#include <cmath>

int main()
{
    srand((unsigned)time(NULL));
    Array MyArr(readPositiveNumber("Enter the size of the array: "));
    MyArr.setLength(readArrayLength(MyArr));

    MyArr.fillArray(100, 1);
    // Printing the original array elements
    std::cout << "Original Array\n";
    MyArr.Print();

    Array CopyArr(MyArr.getSize());
    CopyArr.copyArr(MyArr);
    // Printing the copy array elements
    std::cout << "Copy Arr \n";
    CopyArr.Print();
}