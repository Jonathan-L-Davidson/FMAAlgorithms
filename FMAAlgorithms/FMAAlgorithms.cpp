// FMAAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void FlaggedBubble(int* array, int size) {
    for (int i = 0; i < size; i++) {
        bool ValueSwapped = false;
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int val = array[i];
                array[i] = array[j];
                array[j] = val;
                ValueSwapped = true;
            }
        }

        if (!ValueSwapped) {
            break;
        }
    }
}

void InsertionSort(int* array, int size) {
    for (int i = 0; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        // while j is more than or equal to 0
        // and higher than key ( array[i] )
        while (j >= 0 && array[j] > key) {
            // the value ahead on j is equal to j.
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void SelectionSort(int* array, int size) {
}
void PolyphaseShellSort(int* array, int size) {
}

int main()
{
    const int size = 10;
 
    std::cout << "Randomly generating" << size << " numbers\n\n";
    
    int list[size];

    for (int i = 0; i < size; i++) {
        list[i] = rand() % 100;
        
        std::cout << list[i] << "\n";
    }

    std::cout << "Choose the Sorting Algorithm:\n \
        1: Flagged Bubble Sort\n \
        2: Insertion Sort\n \
        3: Selection Sort\n \
        4: Polyphase Shell Sort\n";

    int input;
    std::cin >> input;

    void (*selectedSort)(int*, int) { &FlaggedBubble };

    switch (input) {
        case(1):
            selectedSort = &FlaggedBubble;
            break;
        case(2):
            selectedSort = &InsertionSort;
            break;
        case(3):
            selectedSort = &SelectionSort;
            break;
        case(4):
            selectedSort = &PolyphaseShellSort;
            break;
    }

    std::cout << "\n\nSorting...\n";
    
    (*selectedSort)(list, size);

    std::cout << "\n\nSorted. Outputting...\n\n";

    for (int i = 0; i < size; i++) {
        std::cout << list[i] << "\n";
    }



}
