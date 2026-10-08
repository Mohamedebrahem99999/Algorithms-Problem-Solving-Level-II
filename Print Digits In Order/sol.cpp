#include "../NumberTheory.h"
#include "../input.h"
#include <iostream>
#include <vector>

void printDigits(int Number)
{
    do{
        std::cout << Number % 10 << "\n";
        Number /= 10;
    }while (Number);
}

int main()
{
    printDigits(reverseNumber(readNumber("Enter a Number: ")));
}