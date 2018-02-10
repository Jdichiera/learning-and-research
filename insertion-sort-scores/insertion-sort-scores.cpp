// Filename     : insertion-sort-scores.cpp
// Author       : Jeramy Dichiera
// Created      : 07/25/2017
// Description  : Allows the user to input 10 numeric scores with values between 50 and 100.
//					After inputting the scores they will be sorted using a insertion sort.


#include <iostream>

void InputScores(int scoresArray[], int arraySize) {
	int input = 0;

	std::cout << "\nPlease enter the scores for " << arraySize << " student scores.";
	for (int i = 0; i < arraySize; i++) {
		std::cout << "\nScore #" << i + 1 << ":";
		while (!(std::cin >> input) || (input <50) || (input > 100)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "The input was not between 50 and 100 ...  Try again: ";
		}
		scoresArray[i] = input;
	}
}


void PrintArray(int myArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		std::cout << "\nScore #" << i + 1 << ": " << myArray[i];
	}
}


void InsertionSort(int array[], int length) {
	int j;
	int temp;

	for (int i = 0; i < length; i++) {
		j = i;
		while (j > 0 && array[j] < array[j - 1]) {
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}
}


void main() {
	int scoresArray[10] = { 0 };
	int arraySize;

	arraySize = sizeof(scoresArray) / sizeof(scoresArray[0]);

	std::cout << "\n\t--== Insertion Score Sorter ==--\n";
	InputScores(scoresArray, arraySize);
	std::cout << "You input : ";
	PrintArray(scoresArray, arraySize);
	std::cout << "\nSorting scores ...\n";
	InsertionSort(scoresArray, arraySize);
	std::cout << "\nThe scores in descending order are: ";
	PrintArray(scoresArray, arraySize);
	std::cout << std::endl;
	system("pause");

}