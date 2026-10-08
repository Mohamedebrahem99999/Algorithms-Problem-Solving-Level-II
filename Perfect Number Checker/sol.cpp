#include "../NumberTheory.h"
#include "../input.h"
#include <iostream>
#include <vector>

enum enPerfect
{
    Perfect,
    NotPerfect
};

int getSumOfDivisors(int Number)
{
    int SumOfDivisors = 0;
    for (int &Divisor : getDivisors(Number))
    {
        if (Divisor != Number)
            SumOfDivisors += Divisor;
    }
    return SumOfDivisors;
}

enPerfect isPerfect(int Number)
{
    if (Number == getSumOfDivisors(Number))
        return enPerfect::Perfect;
    return enPerfect::NotPerfect;
}

void printResult(enPerfect IsPerfect)
{
    if (IsPerfect == enPerfect::Perfect)
        std::cout << "Perfect" << std::endl;
    else
        std::cout << "Not Perfect" << std::endl;
}

int main()
{
    int Number = readPositiveNumber("Enter a positive number ");
    printResult(isPerfect(Number));
}