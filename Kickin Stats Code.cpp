// Kickin Stats Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include "Data Gen/Player.h"
#include "Radix Sort.h"
#include "Data Gen/getPlayerData.h"
#include "Data Gen/RandomCSVGen.h"
using namespace std;



int main()
{
    /*int bar[100000] = {};
    for (int i = 0; i < 100000; i++) {
        bar[i] = getRand(0, 1000);
    }
    
    radixSort(bar,100000);
    printArray(bar, 100000);
*/


    //makeCSV();
     
    Player* players;
    players = getPlayerData();
         
    radixSort(players, 100000, 1);
    for (int i = 0; i < 1000; i++) {
        cout << players[i].stats[1] << endl;
    }
}


