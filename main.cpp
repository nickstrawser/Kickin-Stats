#include "RandomCSVGen.h"
#include "Player.h"
#include "getPlayerData.h"
#include "bucketSort.h"
#include "linkedList.h"

int main() {
    //makeCSV();
    
    Player* players;
    players = getPlayerData();

    bucketSort(players, 1);

    printf("%-13s %-13s %3s %7s \n", "First Name", "Last Name", "Age", "Stat");
    for (int i = 0; i < 10; i++) {
        players[i].print(1);
    }

    return 0;
}