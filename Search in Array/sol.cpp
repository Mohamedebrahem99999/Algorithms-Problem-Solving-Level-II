#include <iostream>
#include <cstdlib>
#include "../input.h"
#include "../random.h"
#include "../Array.h"

void printSearchResult(int SearchNumber, int SearchResult)
{
    if (SearchResult == -1)
    {
        std::cout << "Number you are looking for is: " << SearchNumber << "\n";
        std::cout << "The number is not found :-(\n";
    }
    else
    {
        std::cout << "Number you are looking for is: " << SearchNumber << "\n";
        std::cout << "The number found at position: " << SearchResult << "\n";
        std::cout << "The number found its order: " << SearchResult + 1 << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    Array MyArr(readPositiveNumber("Enter the Array Size: "));
    MyArr.setLength(readNumberInRange(MyArr.getSize(), 0, "Enter the Array Length: "));

    MyArr.fillArray(100, 1);

    int SearchNumber = readNumberInRange(100, 1, "Enter a number between 1 and 100 to search in the array: ");
    int SearchResult = MyArr.Search(SearchNumber);

    printSearchResult(SearchNumber, SearchResult);
}