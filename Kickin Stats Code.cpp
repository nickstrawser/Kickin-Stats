// Kickin Stats Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void countSort(int arr[], int arrsize);
void printArray(int arr[], int size);
int getRand(unsigned int min, unsigned int max);


int main()
{
    int bar[100000] = {};
    for (int i = 0; i < 100000; i++) {
        bar[i] = getRand(0, 10);
    }
    //int foo[10] = {2,5,2,3,9,1,5,8,9,4 };

    //countSort(foo);
    countSort(bar,100000);
    printArray(bar, 100000);
}


void countSort(int arr[], int arrsize) {

    // Frequency array will store the frequency of each digit in base 10 (0-9) in the input array
    int frequency[10] = { };

    // If the values are already 0-9 inside the array
    // May need to pass in what power of 10 to take arr[i] % (power of 10) and increase the frequency there

    // Loop through input array size, increment the frequency of the digit at current array index in the frequency array
    for (int i = 0; i < arrsize; i++) {
        frequency[arr[i]]++;
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
        outputarr[frequency[arr[i]]] = arr[i];
        frequency[arr[i]]++;
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
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
