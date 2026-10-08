#include "../NumberTheory.h"
#include "../Array.h"
#include <vector>
#include <cmath>

int main()
{
    srand((unsigned)time(NULL));
    Array MyArr(readPositiveNumber("Enter the size of the array: "));
    MyArr.setLength(readArrayLength(MyArr));
    MyArr.fillArray(100, 1);
    std::cout << "Array Before Shuffling \n";
    MyArr.Print();
    MyArr.Shuffle();
    std::cout << "Array After Shuffling \n";
    MyArr.Print();
}