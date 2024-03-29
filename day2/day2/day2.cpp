// day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int* runCode(int memory[]) {
	int instructionPointer = 0;
	while (memory[instructionPointer] != 99) {
		if (memory[instructionPointer] == 1) {
			memory[memory[instructionPointer + 3]] = memory[memory[instructionPointer + 1]] + memory[memory[instructionPointer + 2]];
		}
		else if (memory[instructionPointer] == 2) {
			memory[memory[instructionPointer + 3]] = memory[memory[instructionPointer + 1]] * memory[memory[instructionPointer + 2]];
		}
		instructionPointer += 4;
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
	int originalMemory[] = { 1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,9,1,19,1,9,19,23,1,23,5,27,2,27,10,31,1,6,31,35,1,6,35,39,2,9,39,43,1,6,43,47,1,47,5,51,1,51,13,55,1,55,13,59,1,59,5,63,2,63,6,67,1,5,67,71,1,71,13,75,1,10,75,79,2,79,6,83,2,9,83,87,1,5,87,91,1,91,5,95,2,9,95,99,1,6,99,103,1,9,103,107,2,9,107,111,1,111,6,115,2,9,115,119,1,119,6,123,1,123,9,127,2,127,13,131,1,131,9,135,1,10,135,139,2,139,10,143,1,143,5,147,2,147,6,151,1,151,5,155,1,2,155,159,1,6,159,0,99,2,0,14,0 };
	int memory[sizeof(originalMemory)/sizeof(originalMemory[0])];
	std::copy(std::begin(originalMemory), std::end(originalMemory), std::begin(memory));
	std::cout << memory[1] <<  std::endl;
	std::cout << (memory[1] != 19690720) << std::endl;
	for (int i = 0; i < 100 && memory[0]!= 19690720; i++)
	{
		for (int j = 0; j < 100 && memory[0] != 19690720; j++)
		{
			std::copy(std::begin(originalMemory), std::end(originalMemory), std::begin(memory));
			memory[1] = i;
			memory[2] = j;
			runCode(memory);
			std::cout << memory[0] << std::endl;
			if (memory[0] == 19690720) {
				std::cout << i * 100 + j;
			}
	
		}
	}
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
