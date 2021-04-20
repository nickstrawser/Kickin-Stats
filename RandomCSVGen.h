#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int getRand(int min, int max);
string getName();
void getStats(int& age, int& matches, int& min, int& goals, int& shots, int& assists, int& penalties,  int& pAtt, int& yellow, int& red);
void makeCSV();