#include <iostream>
#include <cstdlib>
#include "../input.h"
#include "../random.h"
#include "../Array.h"


int main()
{
    srand((unsigned)time(NULL));

    Array MyArr(readPositiveNumber("Enter the Array Size: "));
    int cnt = MyArr.getSize() + 1;
    while (cnt--)
    {
        MyArr.Append(readNumber("Please Enter a number: "));
        if (cnt == 1)
        {
            std::cout << "Array is already full of elements, You can not add more\n";
            break;
        }
        if (!getBinaryChoice("Do you want to add more numbers:\n 1 if yes 0 otherwise "))
            break;
        std::cout << "\n";
    }
    std::cout << "Array Length = " << MyArr.getLength() << "\n";
    MyArr.Print();
}