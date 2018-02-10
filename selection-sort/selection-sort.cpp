// Filename     : selection-sort.cpp
// Author       : Jeramy Dichiera
// Created      : 07/19/2017
// Description  : A noted selection sort example using an array.

// A selection sort is probably the most simple sorting process, and works well for small
// amounts of data.
// Here are the main steps
//	1. Start at the beginning of the collection
//	2. Compare the first element to each additional element.
//	3. If a smaller value is found, swap the first element with the element holding the 
//		smaller value
//	4. If we have swapped, or we reach the end of the collection, start the process again with the 
//		second element.
//	5. Continue this process until we are at the end of the collection.

#include <iostream>
void SelectionSort(int myArray[], int arraySize) {
	int minimumValue;
	int tempNumber;

	for (int i = 0; i < arraySize - 1; i++) {
		minimumValue = i;
		for (int j = i + 1; j < arraySize; j++) {
			if (myArray[j] < myArray[minimumValue]) {
				minimumValue = j;
			}
			if (minimumValue != i) {
				tempNumber = myArray[i];
				myArray[i] = myArray[minimumValue];
				myArray[minimumValue] = tempNumber;
			}
		}
	}
}

void PrintArray(int myArray[], int arraySize) {
	std::cout << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << myArray[i];
	}
}

void main() {
	int myArray[10] = { 10, 5, 3, 4, 2, 9, 7, 8, 6, 1 };
	PrintArray(myArray, 10);
	SelectionSort(myArray, 10);
	PrintArray(myArray, 10);
	system("pause");
}

