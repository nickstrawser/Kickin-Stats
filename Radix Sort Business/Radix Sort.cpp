// Kickin Stats Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include "Radix Sort.h"
#include "Data Gen/getPlayerData.h"
#include "Data Gen/RandomCSVGen.h"
#include "Data Gen/Player.h"

void radixSort(Player* players, int arrsize, int stat) {
    // 
    int maxValue = 0;

    for (int i = 0; i < arrsize; i++) {
        if (players[i].stats[stat] > maxValue)
            maxValue = players[i].stats[stat];
    }

    

    int pTen = 0; // Keeps track of what power of ten is being used to get the digit for countSort
    while (maxValue > 0) {
        countSort(players, arrsize, stat, pTen);

        maxValue /= 10;
        pTen++;
    }
}
void countSort(Player* players, int arrsize, int stat, int pTen) {

    // Frequency array will store the frequency of each digit in base 10 (0-9) in the input array
    int frequency[10] = { };

    // If the values are already 0-9 inside the array
    // May need to pass in what power of 10 to take arr[i] % (power of 10) and increase the frequency there
    int modValue = pow(10, pTen);
    // Loop through input array size, increment the frequency of the digit at current array index in the frequency array
    for (int i = 0; i < arrsize; i++) {
        frequency[(players[i].stats[stat] / modValue) % 10]++;
    }
    //printArray(frequency, 10);

    // SET EACH VALUE TO THE CUMULATIVE FREQUENCY
    int runningSum = 0;
    for (int i = 0; i < 10; i++) {
        frequency[i] = runningSum + frequency[i];
        runningSum = frequency[i];
    }

    
    //printArray(frequency, 10);

    // SHIFT THE ARRAY TO THE RIGHT BY 1 INDEX
    for (int i = 8; i >= 0; i--) {
        frequency[i + 1] = frequency[i];
    }
    frequency[0] = 0;

    

    //printArray(frequency, 10);

    Player* outputarr = new Player[100000];
    for (int i = 0; i < arrsize; i++) {
        outputarr[frequency[(players[i].stats[stat] / modValue) % 10]] = players[i];
        frequency[(players[i].stats[stat] / modValue) % 10]++;
    }
    


    for (int i = 0; i < arrsize; i++) {
        players[i] = outputarr[i];
    }
}

