#include "../NumberTheory.h"
#include <vector>
#include <cmath>
#include "../input.h"

int main()
{
    long long Number = readNumber("Enter a number to reverse: ");
    std::cout << reverseNumber(Number) << "\n";
}