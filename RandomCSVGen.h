#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int getRand(unsigned int min, unsigned int max);
string getName();
void getStats(unsigned int& age, unsigned int& matches, unsigned int& min, unsigned int& goals, unsigned int& shots, unsigned int& assists, unsigned int& penalties, unsigned  int& pAtt, unsigned int& yellow, unsigned int& red);
void makeCSV();