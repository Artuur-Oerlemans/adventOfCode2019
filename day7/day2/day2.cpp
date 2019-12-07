// day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

std::vector<int> extractInstructions(int instructionsInt) {
	std::vector<int> output(4,0);
	int opcode = instructionsInt % 100;
	instructionsInt = instructionsInt / 100;

	output[0] = opcode;
	for (int i = 1; instructionsInt != 0; i++)
	{
		output[i] = instructionsInt % 10;
		instructionsInt = instructionsInt / 10;
	}
	return output;
}

std::vector<int> getReadParameters(std::vector<int> instructions, vector<int>* memory, int instructionPointer) {
	int numberOfParams;
	if (instructions[0] == 1 
		|| instructions[0] == 2 
		|| instructions[0] == 5 
		|| instructions[0] == 6
		|| instructions[0] == 7
		|| instructions[0] == 8) {
		numberOfParams = 2;
	}
	else if (instructions[0] == 4) {
		numberOfParams = 1;
	}
	else {
		numberOfParams = 0;
	}
	std::vector<int> result(numberOfParams, 0);
	for (int i = 0; i < numberOfParams; i++) {
		if (instructions[i + 1]) {
			result[i] = (*memory)[instructionPointer + i + 1];
		}
		else {
			result[i] = (*memory)[(*memory)[instructionPointer + i + 1]];
		}
	}
	return result;
}

void runCode(vector<int> memory) {
	int instructionPointer = 0;
	std::vector<int> instructions = extractInstructions(memory[instructionPointer]);
	while (instructions[0] != 99) {

		std::vector<int> readParameters = getReadParameters(instructions, &memory, instructionPointer);

		switch (instructions[0]) {
		case 1:
			memory[memory[instructionPointer + 3]] = readParameters[0] + readParameters[1];
			instructionPointer += 4;
			break;
		case 2:
			memory[memory[instructionPointer + 3]] = readParameters[0] * readParameters[1];
			instructionPointer += 4;
			break;
		case 3:
			std::cin >> memory[memory[instructionPointer +1]];
			instructionPointer += 2;
			break;
		case 4:
			std::cout << readParameters[0]<<std::endl;
			instructionPointer += 2;
			break;
		case 5:
			if (readParameters[0] != 0) {
				instructionPointer = readParameters[1];
			}
			else {
				instructionPointer += 3;
			}
			break;
		case 6:
			if (readParameters[0] == 0) {
				instructionPointer = readParameters[1];
			}
			else {
				instructionPointer += 3;
			}
			break;
		case 7:
			memory[memory[instructionPointer + 3]] = readParameters[0] < readParameters[1] ? 1 : 0;
			instructionPointer += 4;
			break;
		case 8:
			memory[memory[instructionPointer + 3]] = readParameters[0] == readParameters[1] ? 1 : 0;;
			instructionPointer += 4;
			break;
		} 
		instructions = extractInstructions(memory[instructionPointer]);
		std::cout << "bleep" << std::endl;
	}
}

vector<int> readInput(string adress) {
	vector<int> memory = {};
	ifstream file;
	file.open(adress);

	if (!file) {
		throw "file couldn't be opened";
	}

	string input;
	getline(file, input);
	file.close();

	stringstream inputStream(input);
	while (inputStream.good())
	{
		string substr;
		getline(inputStream, substr, ',');
		memory.push_back(stoi(substr));
	}
	return memory;
}

int main()
{ 
	vector<int> memory = readInput("../testInputDay5.txt");
	runCode(memory);
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
