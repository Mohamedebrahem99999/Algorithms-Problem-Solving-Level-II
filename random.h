#pragma once
#include <cstdlib>
#include <string>

int generateRandomNumberInRange(int To, int From)
{
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}

std::string generateRandomWord(int Len)
{
    std::string Word = "";
    for (int i = 0; i < Len; i++)
    {
        Word = Word + (char)generateRandomNumberInRange(90, 65);
    }
    return Word;
}
