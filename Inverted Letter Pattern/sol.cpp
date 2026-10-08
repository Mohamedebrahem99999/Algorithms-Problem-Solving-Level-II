#include <iostream>
#include "../input.h"
#include "../NumberTheory.h"

int main()
{
    int Number = readPositiveNumber("Enter a positive number: ");
    for (int i = Number; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
            std::cout << char(i + 64);
        std::cout << "\n";
    }
}