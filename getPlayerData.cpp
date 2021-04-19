#include "getPlayerData.h"


Player* getPlayerData() {
	ifstream file("playerData.csv");
	if (!file.is_open()) throw runtime_error("Couldn't open file");

	string first, last, line, end;
	int age, matches, min, goals, shots, assists, penalties, pAtt, yellow, red, index;
	Player* out = new Player[100000];
	string* data;

	index = 0;

	getline(file, line);

	while (getline(file,line)) {
		data = breakLine(line);

		first = data[0];
		last = data[1];
		age = stoi(data[2]);
		matches = stoi(data[3]);
		min = stoi(data[4]);
		goals = stoi(data[5]);
		shots = stoi(data[6]);
		assists = stoi(data[7]);
		penalties = stoi(data[8]);
		pAtt = stoi(data[9]);
		yellow = stoi(data[10]);
		red = stoi(data[11]);

		out[index] = Player(first, last, age, matches, min, goals, shots, assists, penalties, pAtt, yellow, red);
		index++;

	}
	cout << "Finished Reading File" << endl;

	return out;
}

string* breakLine(string line) {
	string* out = new string[12];
	int count = 0;

	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ',') {
			out[count] = line.substr(0, i);
			count++;
			line = line.substr(i + 1);
			i = 0;
		}
	}
	out[count] = line;
	return out;
}