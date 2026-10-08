#include "../NumberTheory.h"
#include "../Array.h"
#include <cstdlib>

int main()
{
    srand((unsigned)time(NULL));
    Array MyArr(readPositiveNumber("Enter the size of the array: "));
    MyArr.setLength(readArrayLength(MyArr));
    MyArr.fillArray(100, 1);
    std::cout << "Array Before Reversing \n";
    MyArr.Print();
    MyArr.Reverse();
    std::cout << "Array After Reversing \n";
    MyArr.Print();
}