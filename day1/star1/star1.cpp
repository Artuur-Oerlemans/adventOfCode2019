#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> readInput(string);

int calcFuelPerModule(int);

int calcFuelPerMass(int);

void part1(vector<int>);

void part2(vector<int>);

int main()
{

	vector<int> modulesMass = readInput("../inputDay1.txt");
	
	part1(modulesMass);
	part2(modulesMass);
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

	file.close();
	return input;
}

void part1(vector<int> modulesMass) {
	int totalFuel = 0;
	
	for (const int &mass : modulesMass) {
		totalFuel += calcFuelPerMass(mass);
	}

	cout << "Part 1: fuel per for modules (fuel excluded): " << totalFuel << endl;
}

void part2(vector<int> modulesMass) {
	int totalFuel = 0;

	for (const int &mass : modulesMass) {
		totalFuel += calcFuelPerModule(mass);
	}

	cout << "Part 2: fuel per for modules (fuel included): " << totalFuel << endl;
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

