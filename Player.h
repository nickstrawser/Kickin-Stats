#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Player {
	string first;
	string last;
	int age, matches, min, goals, shots, assists, penalties, pAtt, yellow, red;
	Player(string first, string last, int age, int matches, int min, int goals, int shots, int assists, int penalties, int pAtt, int yellow, int red);
	Player();
	void print();
};