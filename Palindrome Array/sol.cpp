#include "../NumberTheory.h"
#include "../input.h"
#include "../Array.h"
#include <iostream>
#include <vector>


void printResult(bool IsPalindrome)
{
    if (IsPalindrome)
    {
        std::cout << "Yes array is Palindrome\n";
    }
    else
    {
        std::cout << "The array is not Palindrome\n";
    }
}
int main()
{
    Array MyArr;
    MyArr.fillArray({10,20,30,20,10});
    MyArr.Print();
    printResult(isPalindrome(MyArr));
}