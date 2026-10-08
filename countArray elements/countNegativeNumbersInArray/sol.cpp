#include "../../NumberTheory.h"
#include "../../Array.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

int main()
{
    srand((unsigned)time(NULL));
    Array MyArr(readPositiveNumber("Enter the size of the array: "));
    MyArr.fillArray(100, -100);
    MyArr.Print();
    
    std::cout << "The Number of Negative Numbers in this array is " << count(MyArr,isNegative) << "\n ";
}