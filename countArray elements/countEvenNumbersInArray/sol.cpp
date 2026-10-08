#include "../../NumberTheory.h"
#include "../../Array.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

int main()
{
    srand((unsigned)time(NULL));
    Array MyArr(readPositiveNumber("Enter the size of the array: "));
    MyArr.fillArray(100, 1);
    MyArr.Print();
    
    std::cout << "The Number of Even Numbers in this array is " << count(MyArr,isEven) << "\n ";
}