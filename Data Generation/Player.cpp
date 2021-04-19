#include "Player.h"

Player::Player(string first, string last, int age, int matches, int min, int goals, int shots, int assists, int penalties, int pAtt, int yellow, int red) {
	this->first = first;
	this->last = last;
	this->age = age;
	this->stats[0] = age;
	this->matches = matches;
	this->stats[1] = matches;
	this->min = min;
	this->stats[2] = min;
	this->goals = goals;
	this->stats[3] = goals;
	this->shots = shots;
	this->stats[4] = shots;
	this->assists = assists;
	this->stats[5] = assists;
	this->penalties = penalties;
	this->stats[6] = penalties;
	this->pAtt = pAtt;
	this->stats[7] = pAtt;
	this->yellow = yellow;
	this->stats[8] = yellow;
	this->red = red;
	this->stats[9] = red;
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
	cout << "Age FROM ARRAY: " << stats[0] << endl;
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