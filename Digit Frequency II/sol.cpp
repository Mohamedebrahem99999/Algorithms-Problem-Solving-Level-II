#include "../NumberTheory.h"
#include <vector>
#include <cmath>

void printAllFreq(int Number)
{
    std::vector<int> Digits = getDigits(Number);
    for (int Digit : std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
    {
        int Freq = getFreqinNumber(Digits, Digit);
        if (Freq)
            std::cout << "The Frequency of the " << Digit << " is " << Freq << "\n";
    }
}

int main()
{
    int Number;
    std::cout << "Enter a number: \n";
    std::cin >> Number;
    printAllFreq(Number);
}