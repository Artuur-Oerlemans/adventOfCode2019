// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string> 
using namespace std;

int main()
{
    cout <<('8'<'0')<< endl; 
	int numberOfPasswords = 0;

	for (int i = 137683; i <= 596253; i++) {
		string digits = to_string(i);
		bool ascending = true;
		bool doubleInt = false;
		for (int j = 0; j < 5 && ascending; j++) {
			ascending = digits[j] <= digits[j + 1];
			if (digits[j] == digits[j + 1]) {
				bool onlyDouble = true;
				if (j != 0)
					onlyDouble = digits[j - 1] != digits[j];
				if (j!=4)
					onlyDouble = digits[j +1] != digits[j+2] && onlyDouble;
				doubleInt = onlyDouble || doubleInt;
			}
		}
		if (ascending && doubleInt) {
			numberOfPasswords++;
		}
	}
	cout << numberOfPasswords << endl;

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
