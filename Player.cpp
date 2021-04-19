#include "Player.h"

Player::Player(string first, string last, int age, int matches, int min, int goals, int shots, int assists, int penalties, int pAtt, int yellow, int red) {
	this->first = first;
	this->last = last;
	this->age = age;
	this->matches = matches;
	this->min = min;
	this->goals = goals;
	this->shots = shots;
	this->assists = assists;
	this->penalties = penalties;
	this->pAtt = pAtt;
	this->yellow = yellow;
	this->red = red;
	stats[0] = age;
	stats[1] = matches;
	stats[2] = min;
	stats[3] = goals;
	stats[4] = shots;
	stats[5] = assists;
	stats[6] = penalties;
	stats[7] = pAtt;
	stats[8] = yellow;
	stats[9] = red;
}

Player::Player() {
	first = "";
	last = "";
	age = 0;
	matches = 0;
	min = 0;
	goals = 0;
	shots = 0;
	assists = 0;
	penalties = 0;
	pAtt = 0;
	yellow = 0;
	red = 0;
}

void Player::print() {
	cout << "First: " << first << endl;
	cout << "Last: " << last << endl;
	cout << "Age: " << age << endl;
	cout << "Matches: " << matches << endl;
	cout << "Minutes: " << min << endl;
	cout << "Goals: " << goals << endl;
	cout << "Shots: " << shots << endl;
	cout << "Assists: " << assists << endl;
	cout << "Penalties: " << penalties << endl;
	cout << "Penalty Attempts: " << pAtt << endl;
	cout << "Yellow Cards: " << yellow << endl;
	cout << "Red Cards: " << red << endl;
	cout << endl;
}