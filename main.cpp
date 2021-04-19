#include "RandomCSVGen.h"
#include "Player.h"
#include "getPlayerData.h"
#include "bucketSort.h"
#include "linkedList.h"

int main() {
    makeCSV();
    
    Player* players;
    players = getPlayerData();

    bucketSort(players, 1);

    for (int i = 0; i < 1000; i++) {
        players[i].print();
    }

    return 0;
}