#include <iostream>
#include "../input.h"
#include "../NumberTheory.h"
#include <cmath>

int main()
{
    int Number = readNumber("Enter a Number: ");
    int MyAbsNumber = Abs(Number);
    int CPPAbsNumber = std::abs(Number);
    std::cout << "My abs Result : " << MyAbsNumber << "\n";
    std::cout << "C++ abs Result : " << CPPAbsNumber << "\n";
}