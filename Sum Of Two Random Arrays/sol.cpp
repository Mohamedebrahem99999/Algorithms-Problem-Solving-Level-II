#include "../NumberTheory.h"
#include "../Array.h"
#include <vector>
#include <cmath>

Array fillThirdArrayWithSum(Array &Arr1, Array &Arr2)
{
    Array Arr3(Arr1.getSize());
    for (int i = 0; i < Arr1.getLength(); i++)
    {
        Arr3.Append(Arr1.getElement(i) + Arr2.getElement(i));
    }
    std::cout << Arr3.getLength() << "\n";
    return Arr3;
}

int main()
{
    srand((unsigned)time(NULL));
    int ArraySize = readPositiveNumber("Enter the size of the array: ");

    Array MyArr(ArraySize);
    int ArrayLength = readArrayLength(MyArr);
    MyArr.setLength(ArrayLength);
    MyArr.fillArray(100, 1);
    MyArr.Print();

    Array Arr2(ArraySize);
    Arr2.setLength(ArrayLength);
    Arr2.fillArray(100, 2);
    Arr2.Print();

    Array Arr3 = fillThirdArrayWithSum(MyArr, Arr2);
    Arr3.Print();
}