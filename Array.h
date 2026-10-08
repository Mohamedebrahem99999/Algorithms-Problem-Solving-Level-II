#pragma once // compiler directive
#include <iostream>
#include <cstdlib>
#include "input.h"
#include "random.h"
#include "NumberTheory.h"
#include <limits.h>

void swap(int &Num1, int &Num2)
{
    int temp = Num1;
    Num1 = Num2;
    Num2 = temp;
}

class Array
{
    int _Size;
    int _Length;
    int *_Items;

    void _Resize()
    {
        if (_Length == _Size)
        {
            int NewSize = (_Size == 0)? 1 : _Size * 2;
            int * NewItem = new int[NewSize];
            for (int i = 0; i < _Length; i++)
            {
                NewItem[i] = _Items[i];
            }
            delete[] _Items;
            _Items = NewItem;
            _Size = NewSize;
        }
    }
  
public:
    /*__________ Building the constructor of the Array Class ____________*/
    Array(int Size = 0)
    {
        _Size = Size;
        _Length = 0;
        _Items = new int[_Size];
    }

    // =================================================================
    // 💡 [ADDED]: Rule of Three - Element 1: Copy Constructor
    // Handles deep copy when creating a new object from an existing one
    // =================================================================
    Array(const Array &other)
    {
        _Size = other._Size;
        _Length = other._Length;
        _Items = new int[_Size];
        for (int i = 0; i < _Length; i++)
        {
            _Items[i] = other._Items[i];
        }
    }

    // =================================================================
    // 💡 [ADDED]: Rule of Three - Element 2: Copy Assignment Operator
    // Handles deep copy when assigning an existing object to another
    // =================================================================
    Array& operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] _Items;
            _Size = other._Size;
            _Length = other._Length;
            _Items = new int[_Size];
            for (int i = 0; i < _Length; i++)
            {
                _Items[i] = other._Items[i];
            }
        }
        return *this;
    }

    // =================================================================
    // 💡 Rule of Three - Element 3: Destructor
    // =================================================================
    ~Array()
    {
        delete[] _Items;
    }

    /*___________ Encapsulate the Size Property with a Getter ___________*/
    int getSize() const
    {
        return _Size;
    }

    /*___ Encapsulate the Length Property with a Getter and a Setter  ___*/
    void setLength(int Length )
    {
        _Length = Length;
    }

    int getLength() const
    {
        return _Length;
    }

    /*_______________ Fill Array With User input elements _______________*/
    void fillArray()
    {
        for (int i = 0; i < _Length; i++)
        {
            std::cout << "Enter Element " << i + 1 << std::endl;
            std::cin >> _Items[i];
        }
    }

    /*_______ Fill Array With Random Numbers in some range method _______*/
    void fillArray(int To, int From)
    {
        for (int i = 0; i < _Length; i++)
        {
            _Items[i] = generateRandomNumberInRange(To, From);
        }
    }

    /*_______ Fill Array With Random Numbers in some range method _______*/
    void fillArray(std::initializer_list<int> list)
    {
        for (int val : list)
        {
            Append(val);
        }
    }

    /*_________________ Print the array elements method _________________*/
    void Print() const
    {
        std::cout << "Array elements\n\n";
        for (int i = 0; i < _Length; i++)
        {
            std::cout << _Items[i] << "\t";
        }
        std::cout << "\n\n";
    }

    /*___________________ Search for an Element Method __________________*/
    int Search(int Element) const
    {
        for (int i = 0; i < _Length; i++)
        {
            if (_Items[i] == Element)
                return i;
        }
        return -1;
    }

    /*_______________ Check if an Element is in the Array _______________*/
    bool checkMembership(int Element) const
    {
        return Search(Element) != -1;
    }

    /*_______________________ Shuffle Array Method ______________________*/
    void Shuffle()
    {
        for (int i = 0; i < _Length; i++)
        {
            int j = generateRandomNumberInRange(i, 0);
            swap(_Items[i], _Items[j]);
        }
    }

    /*__________________ Reverse Array Elements Method __________________*/
    void Reverse()
    {
        for (int i = 0; i < _Length / 2; i++)
        {
            swap(_Items[_Length - 1 - i], _Items[i]);
        }
    }

    /*______________________ Access Element Method ______________________*/
    int getElement(int Index)const
    {
        return _Items[Index];
    }

    /*_______________ Copy Prime Elements to Array Method _______________*/
    void copyPrimeArr(const Array &arr)
    {
        for (int i = 0; i < arr.getLength(); i++)
        {
            if (Prime::isPrime(arr.getElement(i)))
                Append(arr.getElement(i));
        }
    }

    /*___________________ Copy Array Elements method ___________________*/
    void copyArr(const Array &arr)
    {
        for (int i = 0; i < arr.getLength(); i++)
            Append(arr.getElement(i));
    }

    /*________ Append an Element at the end of the Array ________*/
    void Append(int Element)
    {
        _Resize();
        _Items[_Length] = Element;
        _Length++;
    }

    /*______ Insert an Element at some position in the Array ______*/
     void Insert(int Element = readNumber("Enter a number to insert: "))
    {
        _Resize();
        int Index = readNumberInRange(_Length,0,"Enter the index to insert At");
        for (int i = _Length ; i > Index; i--)
        {
            _Items[i] = _Items[i - 1];
        }
        _Items[Index] = Element;
        _Length++;
    }
};

int readArrayLength(const Array &Arr, std::string prompt = "Enter the length of the array: ")
{
    std::cout << prompt << "\n";
    return readNumberInRange(Arr.getSize(), 0);
}

int getMax(const Array &Arr)
{
    int Max = INT_MIN;
    for (int i = 0; i < Arr.getLength(); i++)
    {
        if (Arr.getElement(i) > Max)
            Max = Arr.getElement(i);
    }
    return Max;
}

int getMin(const Array &Arr)
{
    int Min = INT_MAX;
    for (int i = 0; i < Arr.getLength(); i++)
    {
        if (Arr.getElement(i) < Min)
            Min = Arr.getElement(i);
    }
    return Min;
}

int getFreqInArr(const Array &Arr, int Number)
{
    int Freq = 0;
    for (int i = 0; i < Arr.getLength(); i++)
    {
        if (Arr.getElement(i) == Number)
            Freq++;
    }
    return Freq;
}

//////////////////********* Get Sum Method *********//////////////////
int getSum(const Array &Arr)
{
    int Sum = 0;
    for (int i = 0; i < Arr.getLength(); i++)
    {
        Sum += Arr.getElement(i);
    }
    return Sum;
}

//////////////////********* Get Sum Method *********//////////////////
float getAvg(const Array &Arr)
{
    return (float)getSum(Arr) / Arr.getLength();
}

void copyArray(const Array &Arr1, Array &Arr2, bool (*predicate)(int))
{
    Arr2.setLength(0);
    for (int i = 0; i < Arr1.getLength(); i++)
    {
        if (predicate(Arr1.getElement(i)))
        {
            Arr2.Append(Arr1.getElement(i));
        }
    }
}

void copyArray(const Array &Arr1, Array &Arr2)
{
    Arr2.setLength(0);
    for (int i = 0; i < Arr1.getLength(); i++)
    {
        if (getFreqInArr(Arr1,Arr1.getElement(i)) == 1)
        {
            Arr2.Append(Arr1.getElement(i));
        }
    }
}

bool AreEqual(const Array &Arr1,const Array &Arr2)
{
    if (Arr1.getLength() != Arr2.getLength())
        return false;
    for(int i = 0; i < Arr1.getLength();i++)
    {
        if(Arr1.getElement(i) != Arr2.getElement(i))
            return false;
    }
    return true;
}

bool isPalindrome(const Array &Arr)
{
    Array CopiedArr(0);
    CopiedArr.copyArr(Arr);
    CopiedArr.Reverse();
    return (AreEqual(Arr,CopiedArr));
}

int count(const Array &Arr,bool (*Predicate)(int))
{
    int Count = 0;
    for (int i = 0; i < Arr.getLength();i++)
    {
        if (Predicate(Arr.getElement(i)))
            Count++;
    }
    return Count;
}