#include <iostream>
#include <cstdlib>
#include "../input.h"

int generateRandomNumberInRange(int To, int From)
{
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}

int main()
{
    srand((unsigned)time(NULL));
    int Number = readPositiveNumber("Enter the number of random numbers to generate\n");
    for (int i = 0; i < Number; i++)
        std::cout << generateRandomNumberInRange(10, 1) << std::endl;
}