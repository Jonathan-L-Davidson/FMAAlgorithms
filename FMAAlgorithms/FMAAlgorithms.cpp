// FMAAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Enter 10 numbers\n\n";

    int list[10];

    for (int i = 0; i < 10; i++) {
        std::cout << " ";
        std::cin >> list[i];
    }

    std::cout << "\n\nEnter a number to find\n";
    int input;
    std::cin >> input;

    std::cout << "\n\nStarting...\n";

    for (int i = 0; i < 10; i++) {
        int value = list[i];
        if (value == input) {
            std::cout << "Found " << input << " which is the " << i + 1 << "th number." << "\n\n";
            break;
        }
    }

}
