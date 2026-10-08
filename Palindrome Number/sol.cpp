#include "../NumberTheory.h"
#include "../input.h"
#include <iostream>
#include <vector>

int main()
{
    long long Number = readNumber("Enter a Number: ");
    
    if (isPalindrome(Number))
        std::cout << "Palindrome\n";
    else
        std::cout << "Not Palindrome\n";
}