#include <iostream>
#include <cstdlib>
#include "../input.h"
#include "../random.h"

int main()
{
    srand((unsigned)time(NULL));

    std::cout << "Random Small Letter\n";
    std::cout << (char)generateRandomNumberInRange('z', 'z') << "\n";

    std::cout << "Random Capital Letter\n";
    std::cout << (char)generateRandomNumberInRange('Z','A') << "\n";

    std::cout << "Random Special Character\n";
    std::cout << (char)generateRandomNumberInRange(47, 33) << "\n";

    std::cout << "Random one Digit\n";
    std::cout << (char)generateRandomNumberInRange(57, 48) << "\n";
}