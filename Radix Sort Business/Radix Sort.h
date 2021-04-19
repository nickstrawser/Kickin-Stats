#pragma once
#include "Data Gen/getPlayerData.h"
#include "Data Gen/RandomCSVGen.h"
#include "Data Gen/Player.h"
using namespace std;
void radixSort(Player* players, int arrsize, int stat);
void countSort(Player* players, int arrsize, int stat, int pTen);
void printArray(int arr[], int size);
int getRand(unsigned int min, unsigned int max);