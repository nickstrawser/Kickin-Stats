#pragma once
#include "Player.h"

using namespace std;

void bucketSort(Player* players, int stat);
void bucketSortHelper(Player* players, int low, int high, int stat);