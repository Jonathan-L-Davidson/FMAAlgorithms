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

    std::cout << "\n\nSorting...\n";
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (list[i] > list[j]) {
                int val = list[i];
                list[i] = list[j];
                list[j] = val;
            }
        }
    }

    std::cout << "\n\nStarting...\n";

    for (int i = 0; i < 10; i++) {
        std::cout << input << " vs " << list[i] << "\n";
        if (input < list[i]) {
            std::cout << "Cannot Find Number";
            break;
        }

        if (input == list[i]) {
            std::cout << "Found " << input << " which is the " << i + 1 << "th number." << "\n\n";
            break;
        }
    }


}
