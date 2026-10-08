#include <iostream>
#include <vector>
#include "../input.h"
#include "../NumberTheory.h"
#include <string>

std::string getPassword()
{
    std::string Password;
    while (true)
    {
        std::cout << "Enter 3-character Password\n";
        std::cin >> Password;
        bool isCorrect = true;
        if (Password.length() != 3)
            continue;
        for (int i = 0; i < 3; i++)
        {
            if (!isalpha(Password[i]))
            {
                isCorrect = false;
                break;
            }
            Password[i] = toupper(Password[i]);
        }

        if (isCorrect)
            return Password;
    }
}

void printAllWords(std::string Password)
{
    std::string Word = "";
    bool isMatch = true;
    int cnt = 0;
    for (char i = 65; i < (65 + 26); i++)
    {
        for (char j = 65; j < (65 + 26); j++)
        {
            for (char k = 65; k < (65 + 26); k++)
            {
                cnt++;
                Word = Word + i;
                Word = Word + j;
                Word = Word + k;
                // Word = std::string(1, i) + std::string(1, j) + std::string(1, k);
                for (int l = 0; l < 3; l++)
                {
                    if (Word[l] != Password[l])
                    {
                        isMatch = false;
                    }
                }

                std::cout << "Trial [" << cnt << "] : " << Word << "\n";
                if (isMatch)
                {
                    std::cout << "\n";
                    std::cout << "Password is " << Word << std::endl;
                    std::cout << "Found after " << cnt << " Trial(s)\n";
                    return;
                }
                isMatch = true;
                Word = "";
            }
        }
    }
}

int main()
{
    printAllWords(getPassword());
}