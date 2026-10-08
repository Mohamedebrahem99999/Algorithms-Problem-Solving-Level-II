#include <iostream>
#include <string>

std::string Tabs(int NumberOfTabs)
{
    std::string Tabs = "";
    for (int i = 0; i < NumberOfTabs; i++)
    {
        Tabs = Tabs + "\t";
    }
    return Tabs;
}