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

void printResult(int Number, enPerfect IsPerfect)
{
    if (IsPerfect == enPerfect::Perfect)
        std::cout << Number << std::endl;
}

int main()
{
    int Number = readPositiveNumber("Enter a positive number ");
    for (int i = 1; i <= Number; i++)
    {
        printResult(i, isPerfect(i));
    }
}