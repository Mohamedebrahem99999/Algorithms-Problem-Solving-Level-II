#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

namespace Prime
{
    bool isPrime(int Number)
    {
        if (Number < 2)
            return false;
        for (int i = 2; i * i <= Number; i++)
        {
            if (Number % i == 0)
                return false;
        }
        return true;
    }

    void printResult(bool isPrime)
    {
        if (isPrime)
            std::cout << "The number you entered is prime\n";
        else
            std::cout << "The number you entered is not prime\n";
    }
}

std::vector<int> getDivisors(int Number)
{
    std::vector<int> Divisors;
    int i = 1;
    while (i * i <= Number)
    {
        if (Number % i == 0)
        {
            Divisors.push_back(i);
            if (!(Number / i == i))
                Divisors.push_back(Number / i);
        }
        i++;
    }
    return Divisors;
}

std::vector<int> getDigits(int Number)
{
    std::vector<int> vDigits;
    while (Number)
    {
        vDigits.push_back(Number % 10);
        Number /= 10;
    }
    return vDigits;
}

int reverseNumber(int Number)
{
    std::vector<int> digits = getDigits(Number);
    int n = digits.size();
    int remainder = 0, result = 0;

    while (Number)
    {
        remainder = Number % 10;
        Number /= 10;
        result = result * 10 + remainder;
    }
    return result;
}

bool isPalindrome(int Number)
{
    int ReversedNumber = reverseNumber(Number);
    return Number == ReversedNumber;
}

int getFreqinNumber(std::vector<int> Digits, int Search)
{
    int Freq = 0;
    for (int Digit : Digits)
    {
        if (Digit % 10 == Search)
            Freq++;
    }
    return Freq;
}

bool isOdd(int Number)
{
    return Number%2 != 0;
}

bool isEven(int Number)
{
    return Number%2 == 0;
}

bool isPositive(int Number)
{
    return Number > 0;
}

bool isNegative(int Number)
{
    return Number < 0;
}

double Abs(double Number)
{
    return (Number < 0)? Number * -1:Number;
}

double getFractionPart(double Num)
{
    return Num - int(Num);
}

int myRoundTwo(double Num)
{
    int IntPart = int(Num);
    double FractionPart = getFractionPart(Num);
    if (Abs(FractionPart) >= .5)
    {
        if (Num > 0)
            return ++IntPart;
        return --IntPart;
    }
    return IntPart; 
}

int myRound(double Num)
{
    if (Num > 0)
        return int(Num + .5);
    return int(Num - .5);
}

int myFloor(double Num)
{
    double FractionPart = getFractionPart(Num);
    if (Abs(FractionPart) > 0)
    {
        if (Num < 0)
            return Num -1;
    }
    return Num;
}

int myCeil(double Num)
{
    if (Abs(getFractionPart(Num)) > 0)
    {
        if (Num > 0)
            return int(Num) + 1;
    }
    return int(Num);
}

double getSqrt(double Num)
{
    return pow(Num,.5);
}