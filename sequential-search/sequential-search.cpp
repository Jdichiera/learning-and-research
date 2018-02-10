// Filename     : sequential-search.cpp
// Author       : Jeramy Dichiera
// Created      : 08/09/2017
// Description  : An example of the sequential search. Additional function reverses the
//					search so that the search begins with the final element.

#include <iostream>

void SearchArrayForwards(int theArray[], int searchNum, int arrayLength) {
	int index = -1;
	for (int i = 0; i <= arrayLength; i++) {
		if (theArray[i] == searchNum) {
			std::cout << "\nSearching index " << i  << "(" << theArray[i] << ")" 
				<< " for element " << searchNum << "... search successful.";
			index = i;
		}
		else {
			std::cout << "\nSearching index " << i << "(" << theArray[i] << ")" 
				<< " for element " << searchNum << "... search unsuccessful.";
		}
	}
	if (index > 0) {
		std::cout << "\nThe element " << searchNum << " was found at index" << index;
	}
	else {
		std::cout << "\nThe element " << searchNum << "  was not found in this array.";
	}
}

void SearchArrayBackwards(int theArray[], int searchNum, int arrayLength) {
	int index = -1;
	for (int i = arrayLength; i >= 0; i--) {
		if (theArray[i] == searchNum) {
			std::cout << "\nSearching index " << i << "(" << theArray[i] << ")" 
				<< " for element " << searchNum << "... search successful.";
			index = i;
		}
		else {
			std::cout << "\nSearching index " << i << "(" << theArray[i] << ")" 
				<< " for element " << searchNum << "... search unsuccessful.";
		}
	}
	if (index > 0) {
		std::cout << "\nThe element " << searchNum << " was found at index" << index;
	}
	else {
		std::cout << "\nThe element " << searchNum << "  was not found in this array.";
	}
}

int main() {
	int myArray[7]{ 1, 5, 4, 8, 2, 9, 10 };
	int length = sizeof(myArray) / sizeof(myArray[0]);
	std::cout << "\n\nArray: ";
	for (int i = 0; i < length; i++) {
		std::cout << myArray[i] << ", ";
	}
	std::cout << "\n\nSearching array forwards ... " << std::endl;
	SearchArrayForwards(myArray, 5, length);
	std::cout << "\n\nSearching array backwards ... " << std::endl;
	SearchArrayBackwards(myArray, 5, length);
	system("pause");
	return 0;
}