// Filename     : insertion-sort.cpp
// Author       : Jeramy Dichiera
// Created      : 07/24/2017
// Description  : An example of the insertion sort

#include <iostream>
#include <math.h>

void InsertionSort(int array[], int length) {
	int j;
	int temp;

	// In the main for loop, the inner loop iterator (j) is set to the same position as 
	// the outer loop iterator (i).
	for (int i = 0; i < length; i++) {
		j = i;

		// While the inner loop iterator is not at the beginning of the array AND
		// the value of the current element is less than the value of the next previous
		// element, swap the current and previous elements. This while loop will continue
		// until the smaller element is placed either at the beginning of the array, or
		// at an array index where it is larger than the element one index before it.
		// Personally I see this as a small element 'bubbling' backwards until it is at
		// an appropriate spot in the array.
		while (j > 0 && array[j] < array[j - 1]) {
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}
}

void PrintArray(int array[], int length) {
	std::cout << "\nPrint Array\n";
	for (int i = 0; i < length; i++) {
		std::cout << " " <<  array[i];
	}
	std::cout << std::endl;
}
int main() {
	int array[10] = { 10, 5, 3, 6, 7, 2, 4, 9, 8, 1 };
	int length = sizeof(array)/sizeof(array[0]);
	
	PrintArray(array, length);
	InsertionSort(array, length);
	PrintArray(array, length);
	return 0;
}
