#include <iostream>
#include <cstdlib>
#include "../input.h"
#include "../random.h"

std::string createKey(int Syllables, int SyllableLength)
{
    std::string Key = "";
    for (int i = 0; i < Syllables; i++)
    {
        Key = Key + generateRandomWord(SyllableLength);
        if (i != Syllables - 1)
            Key = Key + "-";
    }
    return Key;
}

void fillArraysWithKeys(std::string Arr[100], int ArrLength, int Syllables, int SyllableLength)
{
    for (int i = 0; i < ArrLength; i++)
        Arr[i] = createKey(Syllables, SyllableLength);
}

int main()
{
    srand((unsigned)time(NULL));

    std::string Arr[100];
    std::cout << "Enter the number of keys\n";
    int ArrLength = readNumberInRange(100,1);
    int Syllables = readPositiveNumber("Enter the number of Syllables: ");
    int SyllableLength = readPositiveNumber("Enter the length of each syllable: ");

    fillArraysWithKeys(Arr, ArrLength, Syllables, SyllableLength);

    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr[i] << "\n";
}