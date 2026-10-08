#include <iostream>
#include <vector>
#include "../input.h"
#include "../NumberTheory.h"

int main()
{
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            for (char k = 'A'; k <= 'Z'; k++)
            {
                std::cout << i << j << k << "\n";
            }
        }
    }
}