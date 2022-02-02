// FMAAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Enter a positive number:\n\n";

    int input;
    std::cin >> input;

    while (input != 1) {
        if (input % 2) {
            input *= 3;
            input += 1;
        }
        else {
            input /= 2;
        }

        std::cout << "\n\n";
        std::cout << input;
    }

}
