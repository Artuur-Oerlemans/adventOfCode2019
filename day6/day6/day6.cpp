// day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
using namespace std;

struct Orbits
{
	vector<string> directOrbits;
	int indirectOrbits = -1;
};


map<string, Orbits> readInputStar1(string adress) {
	map<string, Orbits> directOrbits;
	ifstream file;
	file.open(adress);

	if (!file)
	{
		throw "file couldn't be opened";
	}

	string line;
	do {
		getline(file, line);
		if (directOrbits.count(line.substr(0, 3))) {
			directOrbits[line.substr(0, 3)].directOrbits.push_back(line.substr(4, 3));
		}
		else {
			directOrbits[line.substr(0, 3)].directOrbits = { line.substr(4, 3) };
		}
		
	} while (!file.eof());

	file.close();

	cout << "done reading star 1" << endl;
	return directOrbits;
}

map<string, string> readInputStar2(string adress) {
	map<string, string> orbitting;
	ifstream file;
	file.open(adress);

	if (!file)
	{
		throw "file couldn't be opened";
	}

	string line;
	do {
		getline(file, line);
		orbitting[line.substr(4, 3)] = { line.substr(0, 3) };

	} while (!file.eof());

	file.close();

	cout << "done reading star 2" << endl;
	return orbitting;
}

int indirectOrbits(map<string, Orbits>* directOrbits, string planet) {
	if (directOrbits->count(planet) == 0) {
		return 0;
	}
	else {
		if ((*directOrbits)[planet].indirectOrbits == -1) {
			int numIndirectOrbits = 0;
			numIndirectOrbits += (*directOrbits)[planet].directOrbits.size();
			for (string orbittingPlanet : (*directOrbits)[planet].directOrbits) {
				numIndirectOrbits += indirectOrbits(directOrbits, orbittingPlanet);
			}
			(*directOrbits)[planet].indirectOrbits = numIndirectOrbits;
		}
		return (*directOrbits)[planet].indirectOrbits;
	}
}

void star1(string adress) {

	int orbits = 0;
	map<string, Orbits> directOrbits = readInputStar1(adress);

	//Friend and I both misread that there COM would be the thing everything orbits around
	for (std::map<string, Orbits>::iterator it = directOrbits.begin(); it != directOrbits.end(); ++it)
		orbits += indirectOrbits(&directOrbits, it->first);
	cout << "start 1, number of (in)direct orbits " << orbits << endl;
}

vector<string> pathToCOM(map<string, string> orbitting, string start) {
	vector<string> path = { };
	string atPlanet = start;


	while (atPlanet != "COM") {
		path.push_back(orbitting[atPlanet]);
		atPlanet = orbitting[atPlanet];
	}
	return path;
}

void star2(string adress) {
	map<string, string> orbitting = readInputStar2(adress);
	vector<string> pathSANtoCOM = pathToCOM(orbitting, "SAN");
	vector<string> pathYOUtoCOM = pathToCOM(orbitting, "YOU");
	
	while (pathSANtoCOM[pathSANtoCOM.size()-1] == pathYOUtoCOM[pathYOUtoCOM.size()-1]) {
		pathSANtoCOM.pop_back();
		pathYOUtoCOM.pop_back();
	}

	int distanceSANtoCOM = pathSANtoCOM.size() + pathYOUtoCOM.size();

	cout << "star 2, distance between SAN and YOU " << distanceSANtoCOM << endl;
}

int main()
{
	//First time that both stars could use a different readInput function
	star1("../inputDay6.txt");
	star2("../inputDay6.txt");

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
