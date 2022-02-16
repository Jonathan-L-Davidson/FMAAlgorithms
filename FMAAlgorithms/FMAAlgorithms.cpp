// FMAAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void FlaggedBubble(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        bool ValueSwapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {

                int val = array[j+1];
                array[j+1] = array[j];
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
    int key, j;
    for (int i = 0; i < size; i++) {
        key = array[i];
        j = i - 1;

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
    for (int i = 0; i < size - 1; i++) {
        int minimumVal = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minimumVal])  minimumVal = j;

            int val = array[i];
            array[i] = array[minimumVal];
            array[minimumVal] = val;
        }
    }
}
void PolyphaseShellSort(int* array, int size) {
    int ciuraGap[8] = { 701, 301, 132, 57, 23, 10, 4, 1 };

    for (int gap = 0; gap < 8; gap++) {
        for (int offset = 0; offset < gap; offset++) {
            for (int i = offset; i < size; i += gap) {
                int temp = array[i];
                int j = i;
                for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap) {
                    array[j] = array[j - gap];
                }
                array[j] = temp;
            }
        }
    }
}

int main()
{
    const int size = 10;
    int list[size];

    int input = 1;

    while (input != 0) {

        std::cout << "\nRandomly generating " << size << " numbers\n";

        for (int i = 0; i < size; i++) {
            list[i] = rand() % 100;
        }


        std::cout << "\n\nChoose the Sorting Algorithm:\n \
        1: Flagged Bubble Sort\n \
        2: Insertion Sort\n \
        3: Selection Sort\n \
        4: Polyphase Shell Sort\n \
        0: Quit\n";

        std::cin >> input;
        if (input == 0) break;

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


        std::cout << "\nSorting...\n";

        for (int i = 0; i < size; i++) {
            std::cout << list[i] << " ";
        }

        (*selectedSort)(list, size);

        std::cout << "\nSorted. Outputting...\n";
        
        for (int i = 0; i < size; i++) {
            std::cout << list[i] << " ";
        }
        std::cout << "\n\n\n";


    }


}
