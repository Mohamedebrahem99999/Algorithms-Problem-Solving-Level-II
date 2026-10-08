#include <iostream>
#include <cmath>
#include "../NumberTheory.h"
#include "../input.h"

int main()
{
    double Num = readNumber("Enter a Number: ");
    std::cout << "My Round Result is " << myRound(Num) << "\n";
    std::cout << "C++ Round Result is " << std::round(Num) << "\n";
}