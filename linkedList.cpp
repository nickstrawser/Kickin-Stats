#include "linkedList.h"

node::node() {
	value = Player();
	next = nullptr;
}

node::node(Player &val) {
	value = val;
	next = nullptr;
}

node::node(Player &val, node* n) {
	value = val;
	next = n;
}

linkedList::linkedList() {
	root = nullptr;
}

linkedList::linkedList(Player &val) {
	root = new node(val);
}

void linkedList::addPlayer(Player &val, int a) {
	if (root == nullptr) {
		root = new node(val);
		return;
	}

	//seeing if its less than root
	if (val.stats[a] < root->value.stats[a]) {
		root = new node(val, root);
		return;
	}

	//find correct spot for new player
	node* temp = root;
	while (temp->next != nullptr) {
		if (temp->next->value.stats[a] > val.stats[a]) {
			temp->next = new node(val, temp->next);
			return;
		}
		temp = temp->next;
	}
	temp->next = new node(val);
}