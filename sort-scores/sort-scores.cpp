// Filename     : sort-scores.cpp
// Author       : Jeramy Dichiera
// Created      : 07/20/2017
// Description  : Allows the user to input 10 numeric scores with values between 50 and 100.
//					After inputting the scores they will be sorted using a selection sort.


#include <iostream>

void InputScores(int scoresArray[], int arraySize) {
	int input = 0;

	std::cout << "\nPlease enter the scores for " << arraySize << " student scores.";
	for (int i = 0; i < arraySize; i++){
		std::cout << "\nScore #" << i + 1 << ":";
		while (!(std::cin >> input) || (input <50) || ( input > 100) ) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "The input was not between 50 and 100 ...  Try again: ";
		}
		scoresArray[i] = input;
	}
}

void swap(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void PrintArray(int myArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		std::cout << "\nScore #" << i + 1 << ": " << myArray[i];
	}
}

void SortScores(int scoresArray[], int arraySize) {
	int smallestNumPosition;
	
	for (int i = 0; i < arraySize - 1; i++) {
		smallestNumPosition = i;
		for (int j = i + 1; j < arraySize; j++) {
			if (scoresArray[j] < scoresArray[smallestNumPosition]) {
				smallestNumPosition = j;
			}
		}
			swap(&scoresArray[smallestNumPosition], &scoresArray[i]);
	}
}


void main() {
	int scoresArray[10] = { 0 };
	int arraySize; 

	arraySize = sizeof(scoresArray) / sizeof(scoresArray[0]);

	std::cout << "\n\t--== Score Sorter ==--";
	InputScores(scoresArray, arraySize);
	std::cout << "You input : ";
	PrintArray(scoresArray, arraySize);
	std::cout << "\nSorting scores ...";
	SortScores(scoresArray, arraySize);
	std::cout << "\nThe scores in descending order are: ";
	PrintArray(scoresArray, arraySize);
}