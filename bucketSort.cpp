#include "bucketSort.h"
#include "linkedList.h"

void bucketSort(Player* players, int stat) {
	int low = 0, high = 0;

	switch (stat) {
	case 0:
		low = 15;
		high = 40;
		break;
	case 1:
		low = 100;
		high = 1000;
		break;
	case 2:
		low = 30;
		high = 91;
		break;
	case 3:
		low = 500;
		high = 900;
		break;
	case 4:
		low = 0;
		high = 500;
		break;
	case 5:
		low = 0;
		high = 1200;
		break;
	case 6:
		low = 100;
		high = 300;
		break;
	case 7:
		low = 0;
		high = 100;
		break;
	case 8:
		low = 0;
		high = 50;
		break;
	case 9:
		low = 0;
		high = 15;
		break;
	default:
		cout << "Invalid input for \"stat\" field of bucket sort" << endl;
		break;
	}
	bucketSortHelper(players, low, high, stat);
}

void bucketSortHelper(Player* players, int low, int high, int stat) {
	linkedList* buckets = new linkedList[high - low];
	//adding players to buckets
	cout << "Creating Buckets.." << endl;

	for (int i = 0; i < 100000; i++) {
		buckets[players[i].stats[stat] - low].addPlayer(players[i], stat);
	}

	//recombining into final sorted list
	cout << "Recombining..." << endl;
	node* root;
	int index = 0;
	for (int i = 0; i < high - low; i++) {
		root = buckets[i].root;
		while (root != nullptr) {
			players[index] = root->value;
			root = root->next;
			index++;
		}
	}
	cout << "Sorted." << endl;
}