#include "RandomCSVGen.h"



int getRand(int min, int max) {
    int diff = max - min;
    return rand() % diff + min;
}

string getName() {
    char cons[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z' };   //21
    char vowels[] = { 'a','e','i','o','u' }; //5
    string out = "";
    for (int i = 0; i < getRand(3, 13); i++) {

        if (out.length() == 0) {
            int temp = getRand(0, 2);
            if (temp == 0) {
                out += vowels[getRand(0, 5)];
            }
            else {
                out += cons[getRand(0, 21)];
            }
            out[0] = toupper(out[0]);
        }
        else if (out.length() % 2 == 0) {
            out += cons[getRand(0, 21)];
        }
        else {
            out += vowels[getRand(0, 5)];
        }

    }
    return out;
}

void getStats(int& age, int& matches, int& min, int& goals, int& shots, int& assists, int& penalties,  int& pAtt, int& yellow, int& red) {
    age = getRand(15, 40);
    matches = getRand(300, 1000);
    min = getRand(30, 91);
    shots = getRand(500, 900);
    goals = getRand(0, 500);
    assists = getRand(0, 1200);
    pAtt = getRand(100, 300);
    penalties = getRand(0, 100);
    yellow = getRand(0, 50);
    red = getRand(0, 15);
}

void makeCSV()
{
    srand(time(NULL));
    ofstream myFile("playerData.csv");

    myFile << "First,Last,Age,Matches Played,Min,Goals,Shots,Assists,Penalties Made,Penalties Attempted,Yellow Cards,Red Cards\n";

    int age, matches, min, goals, shots, assists, penalties, pAtt, yellow, red;
    getStats(age, matches, min, goals, shots, assists, penalties, pAtt, yellow, red);

    for (int i = 0; i < 100000; i++) {
        getStats(age, matches, min, goals, shots, assists, penalties, pAtt, yellow, red);

        myFile << getName() << "," << getName() << "," << age << "," << matches << "," << min << "," << goals << "," << shots << "," << assists << "," << penalties << "," << pAtt << "," << yellow << "," << red << "\n";
    }
    myFile.close();
    cout << "Finished Writing File" << endl;
}