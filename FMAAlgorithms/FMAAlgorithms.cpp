// FMAAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Enter the temperature in F:\n\n";

    int fahrenheit;
    std::cin >> fahrenheit;

    int celcius = ((fahrenheit - 32) * 5) / 9;
    
    if (celcius >= 10) {
        std::cout << "\n\nIt's warm.";
    }
    else {
        std::cout << "\n\nIt's cold";
    }

}
