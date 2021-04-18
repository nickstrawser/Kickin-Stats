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