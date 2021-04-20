#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Player {
	string first;
	string last;
	int stats[10];
	int age, matches, min, goals, shots, assists, penalties, pAtt, yellow, red;
	Player(string first, string last, int age, int matches, int min, int goals, int shots, int assists, int penalties, int pAtt, int yellow, int red);
	Player();
	void print(int stat);
};