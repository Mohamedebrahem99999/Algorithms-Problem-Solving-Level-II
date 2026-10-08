#include <iostream>
#include <cstdlib>
#include "../input.h"
#include "../random.h"
#include "../Array.h"

void printSearchResult(int SearchNumber, bool SearchResult)
{
    if (SearchResult)
    {
        std::cout << "Number you are looking for is: " << SearchNumber << "\n";
        std::cout << "Yes, The number is found :-)\n";
    }
    else
    {
        std::cout << "Number you are looking for is: " << SearchNumber << "\n";
        std::cout << "No, The number is not found :-(\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    Array MyArr(readPositiveNumber("Enter the Array Size: "));
    MyArr.setLength(readNumberInRange(MyArr.getSize(), 0, "Enter the Array Length: "));

    MyArr.fillArray(100, 1);

    int SearchNumber = readNumberInRange(100, 1, "Enter a number between 1 and 100 to check if it is in the array: ");
    bool SearchResult = MyArr.checkMembership(SearchNumber);

    printSearchResult(SearchNumber, SearchResult);
}