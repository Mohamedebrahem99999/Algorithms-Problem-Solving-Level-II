#include "../input.h"
#include <iostream>
#include <string>

std::string Encrypt(std::string text, int steps)
{
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = text[i] + steps;
    }

    return text;
}

std::string Decrypt(std::string text, int steps)
{
    return Encrypt(text, -steps);
}

int main()
{
    std::string text = getText("Enter a text to encrypt and decrypt\n");
    int steps;
    std::cout << "Enter steps by which the text must be encrypted\n";
    std::cin >> steps;
    std::cout << "Text Before Encryption: " << text << std::endl;
    std::cout << "Text After Encryption: " << Encrypt(text, steps) << std::endl;
    std::cout << "Text After Decryption: " << Decrypt(Encrypt(text, steps), steps) << std::endl;
}