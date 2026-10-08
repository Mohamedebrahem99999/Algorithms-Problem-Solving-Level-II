#include "../NumberTheory.h"
#include "../input.h"
#include <vector>
#include <cmath>

int getFreq(int Number, int Search)
{
    int Freq = 0;
    while (Number)
    {
        if (Number % 10 == Search)
            Freq++;
        Number /= 10;
    }

    return Freq;
}

int main()
{
    int Number;
    std::cout << "Enter a number: \n";
    std::cin >> Number;
    short Search = readPositiveNumber("Enter a number to get frequency: ");
    int Freq = getFreq(Number, Search);
    std::cout << "The Frequency of " << Search << " = " << Freq << std::endl;
}