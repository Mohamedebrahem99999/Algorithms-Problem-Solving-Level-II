#include <iostream>
#include "../input.h"
#include "../random.h"

void fillArrayWithRandomNumbers(int arr[100],int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        arr[i] = generateRandomNumberInRange(100,1);
    }
}

void copyArrayElements(int Arr1[100], int Arr2[100],int ArrayLength)
{
    for (int i = 0; i < ArrayLength;i++)
        Arr2[i] = Arr1[i];
}

void printArrayElement(int Arr[100], int ArrayLength)
{
    std::cout << "Array ELements: \n";
    for (int i = 0; i < ArrayLength; i++)
        std::cout << Arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));
    int ArrayLength = readNumberInRange(100,1);
    int Arr1[100];
    int Arr2[100];
    fillArrayWithRandomNumbers(Arr1,ArrayLength);
    copyArrayElements(Arr1,Arr2,ArrayLength);
    printArrayElement(Arr1,ArrayLength);
    printArrayElement(Arr2,ArrayLength);
}
