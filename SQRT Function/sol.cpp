#include <iostream>
#include <cmath>
#include "../NumberTheory.h"
#include "../input.h"

int main()
{
    int Num;
    std::cout << "Enter a Number: ";
    std::cin >> Num;
    std::cout << "My Round Result is " << getSqrt(Num) << "\n";
    std::cout << "C++ sqrt Result is " << std::sqrt(Num) << "\n";
}