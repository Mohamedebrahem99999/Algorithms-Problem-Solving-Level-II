#include "../NumberTheory.h"
#include "../Array.h"
#include <vector>
#include <cmath>

int main()
{
    Array MyArr(readPositiveNumber("Enter the size of the array: "));
    MyArr.setLength(readArrayLength(MyArr));
    MyArr.fillArray();
    MyArr.Print();
    std::cout << getFreqInArr(MyArr, readNumber("Enter a number To get Frequency in the array"));
}