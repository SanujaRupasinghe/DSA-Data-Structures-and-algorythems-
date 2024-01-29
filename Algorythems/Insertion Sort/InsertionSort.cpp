#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate an array of 10 random integers
void generateRandomArray(int unsortedArr[], int size) {
    // The srand function sets the seed value for the random number generator. If you use the same seed value, 
    // you will get the same sequence of random numbers. By using the current time as the seed, you introduce an element of randomness, 
    // ensuring that the sequence of random numbers generated will be different each time the program is run.
    srand(time(0)); 

    for (int i = 0; i < size; ++i) {
        unsortedArr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }
}

// Function to print the elements of an array
void printArray(int numbers[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl;
}

// Function to perform insertion sort on an array
void insertionSort(int unsortedArr[], int size) {
    for (int i = 1; i < size; i++){
        int currentVal = unsortedArr[i];
        int j = i - 1;
        
        while (j >= 0 && unsortedArr[j] > currentVal){
            unsortedArr[j+1] = unsortedArr[j];
            j--;
        }
        unsortedArr[j + 1] = currentVal;
    }
}


int main() {
    const int size = 10;
    int numbers[size] = {0};

    // Generate random array
    generateRandomArray(numbers, size);

    std::cout << "Before sorting: " << std::endl;
    printArray(numbers, size);

    // Perform insertion sort
    insertionSort(numbers, size);

    std::cout << "After sorting: " << std::endl;
    printArray(numbers, size);

    return 0;
}
