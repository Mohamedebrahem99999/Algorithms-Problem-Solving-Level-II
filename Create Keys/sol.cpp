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

int main()
{
    srand((unsigned)time(NULL));
    int NumberOfKeys = readPositiveNumber("Enter the number of keys: ");
    int Syllables = readPositiveNumber("Enter the number of Syllables: ");
    int SyllableLength = readPositiveNumber("Enter the length of each syllable: ");
    for (int i = 0; i < NumberOfKeys; i++)
        std::cout << "Key [" << i + 1 << "]: " << createKey(Syllables, SyllableLength) << "\n";
}