#include <iostream>
#include <cmath>
#include "../NumberTheory.h"
#include "../input.h"

int main()
{
    double Num;
    std::cout << "Enter a Number: ";
    std::cin >> Num;
    std::cout << "My Floor Result is " << myFloor(Num) << "\n";
}