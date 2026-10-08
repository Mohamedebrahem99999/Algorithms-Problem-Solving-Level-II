#include <iostream>
#include <iomanip>

void printTableHeader()
{
    std::cout << "\t\tMultiplication Table From 1 to 10\n\n";
    std::cout << "        ";
    for(int i = 1; i <=10;i++)
        std::cout << std::setw(5) << i;
    std::cout << "\n";
    
    for (int i = 0; i < 65;i++)
        std::cout << "_";
    std::cout << "\n";
    
}

void printMultiplicationTable(int Number)
{
    for (int i = 1; i <= 10; i++)
    {
        int Result = Number * i;
        std::cout << std::setw(5)<< Result;
    }
}

void printAllTables()
{
    printTableHeader();
    for(int i = 1; i <=10;i++ )
    {
        std::cout << std::setw(5) << i << " | ";
        printMultiplicationTable(i);
        std::cout << "\n";
    }
}

int main() {   

   printAllTables();
    return 0;
}