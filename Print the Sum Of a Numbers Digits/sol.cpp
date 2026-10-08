#include "../NumberTheory.h"
#include "../input.h"
#include <iostream>
#include <vector>

int getSum(int Number)
{
    int Sum = 0;
    std::vector<int> Digits =  getDigits(Number);
    for (const int &Digit : Digits)
    {
        Sum += Digit;
    }
    return Sum;
}

void printSum(int Sum)
{
    std::cout << "The sum of the Digits = " << Sum << "\n";
}

int main()
{
    printSum(getSum(readNumber()));
}