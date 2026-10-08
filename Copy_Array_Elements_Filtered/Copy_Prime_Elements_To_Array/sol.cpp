#include <iostream>
#include "../../input.h"
#include "../../Array.h"

int main()
{
    srand((unsigned)time(NULL));
    int ArraySize = readPositiveNumber("Enter the size of the Array: ");
    Array Arr1(ArraySize), Arr2(ArraySize);
    Arr1.setLength(readNumberInRange(ArraySize,0,"Enter the Length of the Array: "));
    

    Arr1.fillArray(100,1);
    Arr1.Print();
    copyArray(Arr1,Arr2,Prime::isPrime);
    std::cout << "Array two elements are \n";
    Arr2.Print();
}