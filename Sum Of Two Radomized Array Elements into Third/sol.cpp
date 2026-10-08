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
    MyArr.Print();
    std::cout << "Sum Of Array Elements = " << getSum(MyArr) << "\n ";
}