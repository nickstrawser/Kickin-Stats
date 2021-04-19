// Kickin Stats Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Radix Sort.h"

void radixSort(int arr[], int arrsize) {
    // 
    int maxValue = 0;

    for (int i = 0; i < arrsize; i++) {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }


    int pTen = 0; // Keeps track of what power of ten is being used to get the digit for countSort
    while (maxValue > 0) {
        countSort(arr, arrsize, pTen);

        maxValue /= 10;
        pTen++;
    }
}
void countSort(int arr[], int arrsize, int pTen) {

    // Frequency array will store the frequency of each digit in base 10 (0-9) in the input array
    int frequency[10] = { };

    // If the values are already 0-9 inside the array
    // May need to pass in what power of 10 to take arr[i] % (power of 10) and increase the frequency there
    int modValue = pow(10, pTen);
    // Loop through input array size, increment the frequency of the digit at current array index in the frequency array
    for (int i = 0; i < arrsize; i++) {
        frequency[(arr[i] / modValue) % 10]++;
    }
    //printArray(frequency, 10);

    // SET EACH VALUE TO THE CUMULATIVE FREQUENCY
    int runningSum = 0;
    for (int i = 0; i < 10; i++) {
        frequency[i] = runningSum + frequency[i];
        runningSum = frequency[i];
    }

    cout << endl;
    //printArray(frequency, 10);

    // SHIFT THE ARRAY TO THE RIGHT BY 1 INDEX
    for (int i = 8; i >= 0; i--) {
        frequency[i + 1] = frequency[i];
    }
    frequency[0] = 0;

    cout << endl << endl;

    //printArray(frequency, 10);

    int outputarr[100000] = {};
    for (int i = 0; i < arrsize; i++) {
        outputarr[frequency[(arr[i] / modValue) % 10]] = arr[i];
        frequency[(arr[i] / modValue) % 10]++;
    }
    cout << endl;


    for (int i = 0; i < arrsize; i++) {
        arr[i] = outputarr[i];
    }
}

int getRand(unsigned int min, unsigned int max) {
    unsigned int diff = max - min;
    return rand() % diff + min;
}

void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        cout << i << ": " << arr[i] << endl;
    }
}

