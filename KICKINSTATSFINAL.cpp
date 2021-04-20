// KICKINSTATSFINAL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include "Player.h"
#include "Radix Sort.h"
#include "getPlayerData.h"
#include "RandomCSVGen.h"
#include "bucketSort.h"
#include <thread>
#include <chrono>

using namespace std;

void printTopTen(Player* players, int stat);
void medianValue(Player* players, int stat);

int main()
{
    makeCSV();
    Player* players;
    players = getPlayerData();

    int userInput = 0;

    while (userInput != -1) {
        cout << "Welcome to Kickin' Stats! Select which stat you would like to compare players by." << endl;

        cout << "1. Matches \n2. Average Minutes Played \n3. Goals \n4. Shots \n5. Assists \n6. Penalties Scored \n7. Penalties Attempted \n8. Yellow Cards \n9. Red Cards" << endl;

        cin >> userInput;
        if (userInput == -1)
            break;
        int stat = userInput;

        cout << "What would you like to do with this stat?" << endl;
        cout << "1. Radix Sort \n2. Bucket Sort \n3. Display Median \n" << endl;
        cin >> userInput;
        if (userInput == 1) {
            auto t1 = chrono::high_resolution_clock::now();
            radixSort(players, 100000, stat);
            auto t2 = chrono::high_resolution_clock::now();
            printTopTen(players, stat);
            auto ms_int = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
            //chrono::duration<double, std::milli> ms_double = t2 - t1;
            cout << "Time for Radix Sort: " << ms_int.count() << " ms \n";
            cout << endl;
        }
        else if (userInput == 2) {
            auto t1 = chrono::high_resolution_clock::now();
            bucketSort(players, stat);
            auto t2 = chrono::high_resolution_clock::now();
            printTopTen(players, stat);
            auto ms_int = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
            //chrono::duration<double, std::milli> ms_double = t2 - t1;
            cout << "Time for Bucket Sort: " << ms_int.count() << " ms \n";
            cout << endl;
        }
        else if (userInput == 3) {
            medianValue(players, stat);
        }
        else {
            break;
        }

    }

}


void printTopTen(Player* players, int stat) {
    printf("%-13s %-13s %3s ", "First Name", "Last Name", "Age");

    switch (stat) {
    case 1:
        printf("%7s \n", "Matches");
        break;
    case 2:
        printf("%7s \n", "Minutes");
        break;
    case 3:
        printf("%7s \n", "Goals");
        break;
    case 4:
        printf("%7s \n", "Shots");
        break;
    case 5:
        printf("%7s \n", "Assists");
        break;
    case 6:
        printf("%7s \n", "Penalties Made");
        break;
    case 7:
        printf("%7s \n", "Penalties Attempted");
        break;
    case 8:
        printf("%7s \n", "Yellow Cards");
        break;
    case 9:
        printf("%7s \n", "Red Cards");
        break;
    }
    for (int i = 10; i > 0; i--) {
        players[i + 99989].print(stat);
    }
    cout << endl;
}


void medianValue(Player* players, int stat) {
    cout << "The median value for ";
    switch (stat) {
    case 1:
        cout << "matches played is ";
        break;

    case 2:
        cout << "average minutes played per game is ";
        break;
    case 3:
        cout << "goals scored is ";
        break;
    case 4:
        cout << "shots taken is ";
        break;
    case 5:
        cout << "assists made is ";
        break;
    case 6:
        cout << "penalties scored is ";
        break;
    case 7:
        cout << "penalties taken is ";
        break;
    case 8:
        cout << "yellow cards received is ";
        break;
    case 9: 
        cout << "red cards received is ";
        break;
    default:
        cout << "There is no median for this stat.";
    }
    if (stat > 0 && stat < 10) {
        cout << players[50000].stats[stat] << endl;
    }
    cout << endl;
}