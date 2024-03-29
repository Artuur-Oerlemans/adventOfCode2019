// day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

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

std::vector<int> getReadParameters(std::vector<int> instructions, int memory[], int instructionPointer) {
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
			result[i] = memory[instructionPointer + i + 1];
		}
		else {
			result[i] = memory[memory[instructionPointer + i + 1]];
		}
	}
	return result;
}

int* runCode(int memory[]) {
	int instructionPointer = 0;
	std::vector<int> instructions = extractInstructions(memory[instructionPointer]);
	while (instructions[0] != 99) {

		std::vector<int> readParameters = getReadParameters(instructions, memory, instructionPointer);

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
	return memory;
}

void printMemory(int memory[]) {
	std::cout << sizeof(memory) / sizeof(memory[0])<< std::endl;
	for (int i = 0; i < sizeof(memory) / sizeof(memory[0]); i++)
	{
		std::cout << memory[i] << ',';
	}
}

int main()
{ 
	int memory[] = { 3,225,1,225,6,6,1100,1,238,225,104,0,1102,17,65,225,102,21,95,224,1001,224,-1869,224,4,224,1002,223,8,223,101,7,224,224,1,224,223,223,101,43,14,224,1001,224,-108,224,4,224,102,8,223,223,101,2,224,224,1,223,224,223,1101,57,94,225,1101,57,67,225,1,217,66,224,101,-141,224,224,4,224,102,8,223,223,1001,224,1,224,1,224,223,223,1102,64,34,225,1101,89,59,225,1102,58,94,225,1002,125,27,224,101,-2106,224,224,4,224,102,8,223,223,1001,224,5,224,1,224,223,223,1102,78,65,225,1001,91,63,224,101,-127,224,224,4,224,102,8,223,223,1001,224,3,224,1,223,224,223,1102,7,19,224,1001,224,-133,224,4,224,102,8,223,223,101,6,224,224,1,224,223,223,2,61,100,224,101,-5358,224,224,4,224,102,8,223,223,101,3,224,224,1,224,223,223,1101,19,55,224,101,-74,224,224,4,224,102,8,223,223,1001,224,1,224,1,224,223,223,1101,74,68,225,4,223,99,0,0,0,677,0,0,0,0,0,0,0,0,0,0,0,1105,0,99999,1105,227,247,1105,1,99999,1005,227,99999,1005,0,256,1105,1,99999,1106,227,99999,1106,0,265,1105,1,99999,1006,0,99999,1006,227,274,1105,1,99999,1105,1,280,1105,1,99999,1,225,225,225,1101,294,0,0,105,1,0,1105,1,99999,1106,0,300,1105,1,99999,1,225,225,225,1101,314,0,0,106,0,0,1105,1,99999,107,677,677,224,102,2,223,223,1006,224,329,1001,223,1,223,1008,226,677,224,102,2,223,223,1006,224,344,1001,223,1,223,7,226,677,224,102,2,223,223,1005,224,359,1001,223,1,223,8,226,226,224,102,2,223,223,1006,224,374,1001,223,1,223,1007,226,226,224,102,2,223,223,1006,224,389,101,1,223,223,8,677,226,224,1002,223,2,223,1005,224,404,101,1,223,223,1108,677,226,224,102,2,223,223,1006,224,419,1001,223,1,223,1108,226,677,224,102,2,223,223,1006,224,434,101,1,223,223,1108,677,677,224,1002,223,2,223,1005,224,449,101,1,223,223,1008,677,677,224,1002,223,2,223,1006,224,464,101,1,223,223,7,677,226,224,1002,223,2,223,1006,224,479,101,1,223,223,108,677,677,224,1002,223,2,223,1005,224,494,101,1,223,223,107,226,677,224,1002,223,2,223,1006,224,509,101,1,223,223,107,226,226,224,102,2,223,223,1006,224,524,1001,223,1,223,1107,226,677,224,1002,223,2,223,1006,224,539,101,1,223,223,1008,226,226,224,102,2,223,223,1006,224,554,1001,223,1,223,8,226,677,224,1002,223,2,223,1006,224,569,101,1,223,223,1007,677,677,224,102,2,223,223,1005,224,584,1001,223,1,223,1107,677,226,224,1002,223,2,223,1006,224,599,101,1,223,223,7,226,226,224,1002,223,2,223,1005,224,614,101,1,223,223,108,677,226,224,1002,223,2,223,1005,224,629,1001,223,1,223,108,226,226,224,1002,223,2,223,1005,224,644,101,1,223,223,1007,677,226,224,1002,223,2,223,1006,224,659,101,1,223,223,1107,226,226,224,102,2,223,223,1005,224,674,1001,223,1,223,4,223,99,226 };
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
