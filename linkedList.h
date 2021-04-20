#pragma once
#include "Player.h"

struct node {
	node* next;
	Player value;
	node();
	node(Player &val);
	node(Player &val, node* n);
};

//this linked list keeps items in sorted order, each new item is placed using insertion sort
struct linkedList {
	node* root;
	linkedList();
	linkedList(Player &val);
	void addPlayer(Player &val, int a);
};