#include <iostream>
#include <string>
enum enOperationType {Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

int readNumber(std::string message)
{
    int Number;
    std::cout << message << "\n";
    std::cin >> Number;
    return Number;
}

enOperationType readOperator()
{
    char OperationType;
    std::cout << "Enter the operator type (+, -, *, /) ?\n";
    std::cin >> OperationType;
    return (enOperationType) OperationType;
}


float getResult(float Number1, float Number2, enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Subtract:
        return Number1 - Number2;
    case enOperationType::Multiply:
        return Number1*Number2;
    case enOperationType::Divide:
        return Number1/Number2;
    default:
        return -1;
    }
}

int main()
{
    std::cout << (int)'-' << "\n";
    std::cout << (int)'+' << "\n";
    std::cout << (int)'/' << "\n";
    std::cout << (int)'*' << "\n";
    std::cout << (char)44 << "\n";
}