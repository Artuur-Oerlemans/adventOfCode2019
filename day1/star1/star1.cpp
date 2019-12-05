// header
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> readInput(string);

int calcFuelPerModule(int);

int calcFuelPerMass(int);

int main()
{
	int totalFuel = 0;

	vector<int> modulesMass = readInput("../inputDay1.txt");
	

	for (const int &mass: modulesMass){
		totalFuel += calcFuelPerModule(mass);
	}

    cout << totalFuel << endl;
}

vector<int> readInput(string adress) {
	vector<int> input;
	ifstream file;
	file.open(adress);

	if (!file)
	{
		throw "file couldn't be opened";
	}

	string line;
	do {
		getline(file, line);
		input.push_back(stoi(line));
	} while (!file.eof());
	return input;
}

int calcFuelPerModule(int mass) {
	int fuelModule = 0;
	int fuelNotAddedYet = calcFuelPerMass(mass);

	while (fuelNotAddedYet > 0) {
		fuelModule += fuelNotAddedYet;
		fuelNotAddedYet = calcFuelPerMass(fuelNotAddedYet);
	}
	return (fuelModule);
}

int calcFuelPerMass(int mass) {
	return (mass / 3) - 2;
}

