#include <iostream>
#include "../input.h"
#include "../NumberTheory.h"

int main()
{
    int End = readPositiveNumber("Enter a number to stop at\n");
    std::cout << 2 << "\n";
    for (int i = 3; i <= End; i+=2)
    {
        if (Prime::isPrime(i))
            std::cout << i << "\n";
    }
}