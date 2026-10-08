#include <iostream>
#include <cmath>
#include "../NumberTheory.h"
#include "../input.h"

int main()
{
    double Num;
    std::cout << "Enter a Number: ";
    std::cin >> Num;
    std::cout << "My Ceil Result is " << myCeil(Num) << "\n";
    std::cout << "C++ Ceil Result is " << std::ceil(Num) << "\n";
}