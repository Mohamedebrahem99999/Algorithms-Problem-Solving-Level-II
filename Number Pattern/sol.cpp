#include <iostream>
#include "../input.h"
#include "../NumberTheory.h"

int main()
{
    int Number = readPositiveNumber("Enter a positive number: ");
    for (int i = 1; i <= Number; i++)
    {
        for (int j = i; j > 0; j--)
            std::cout << i;
        std::cout << "\n";
    }
}