// FMAAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter a number between 1 and 9\n";
    int input;
    std::cin >> input;

    input *= 9;
    input = input / 10 + input % 10;
    input += 3;
    input /= 2;

    std::cout << "\nResult:\n\n";
    std::cout << input;
    std::cout << "\n";
}