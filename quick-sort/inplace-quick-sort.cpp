// Filename     : inplace-quick-sort.cpp
// Author       : Jeramy Dichiera
// Created      : 07/19/2017
// Description  : A noted in-place quick sort example

// The quick sort method performs the following sequence to sort a collection
// 1. Divide the collection along a specific element called a pivot (generally the last
//		element in the collection).
// 2. Copy all elements from the main collection into three new collections and empty the 
//		original collection.
//		subcollection 1 will store elements less than the pivot
//		subcollection 2 will store elements equal to the pivot
//		subcollection 3 will store elements greater than the pivot
// 3. Recursively call the divide function on subcollection 1 and 3 (the greater and the 
//		smaller collections.) until they are broken down to a single element.
// 4. Recombine the broken down and sorted elements into the main collection. Since we
//		broke down the collections into sorted subcollections, when we reassemble the 
//		main collection by copying the elements from the subcollections back into the 
//		main collection it will be in ascending order.
//
// A sorting method is said to be in-place if it uses a very small amount of memory outside
// of the memory needed to store the main collection. Breaking the main collectiond down
// into subcollections adds additional memory since we are creating (potentially many)
// new collections. Instead of creating new collections, we can use the original collection
// and scan to the left and right of a pivot point, instead of breaking the collection
// down into smaller collections. We will create the example using vectors, but this could 
// also be used with arrays and other objects.

// TODO : median of three to select pivot point
#include <cstdlib>
#include <iostream> // print to console
#include <vector>	// use vectors
#include <utility>	// use swap

// Create a template for the sorting functions to allow us to use this on different data types
template <typename E>

// The quickSort function takes our vector, looks at the size of the vector, and then
// passes the vector to our sorting utility function.
void QuickSort(std::vector<E> &myVector) {

	// Grab the size of the vector. This is purely for syntactic sugar
	int vectorSize = myVector.size();

	// If the vector is just a single element, then it is already as sorted as it will be
	if (vectorSize <= 1) {
		return;
	}

	QuickSortSteps(myVector, 0, vectorSize - 1);
}

// Create a template for our QuickSortSteps function.
template <typename E>

// When looking at our vector we have a specific search size that does not include the 
// pivot point. For example, if we have a 5 element array, the last element will be a
// pivot, leaving us with 4 elements that are sortable.
// Within those 4 sortable elements we have 'edges', which are the far left and right 
// elements of our search size. We have the left edge and sort size as parameters
// in our function so we can call this function recursively.
void QuickSortSteps(std::vector<E> &myVector, int vectorLeftBound, int vectorRightBound) {

	// If the left edge (position 0) is >= our vectorSortSize then we know the vector
	// is as small as it is going to be.
	if (vectorLeftBound >= vectorRightBound) {
		return;
	}

	// Set the pivot point to be the last element in the sort size. Note that we are using
	// our template data type E.
	E pivot = myVector[vectorRightBound];

	// The left edge of the vector is the element position at the beginning. 
	int vectorLeftEdge = vectorLeftBound;

	// Our right edge is the sort size -1. This places the right edge immediately before
	// the pivot point, which is the last element in the vector.
	int vectorRightEdge = vectorRightBound - 1;

	// While the vectorLeftEdge is less than or equal to the vectorRightEdge
	while (vectorLeftEdge <= vectorRightEdge) {
		while (vectorLeftEdge <= vectorRightEdge && pivot >= myVector[vectorLeftEdge]) {
			vectorLeftEdge++;
		}
		while (vectorRightEdge >= vectorLeftEdge && myVector[vectorRightEdge] >= pivot) {
			vectorRightEdge--;
		}
		if (vectorLeftEdge < vectorRightEdge) {
			std::swap(myVector[vectorLeftEdge], myVector[vectorRightEdge]);
		}
	}

	std::swap(myVector[vectorLeftEdge], myVector[vectorRightBound]);
	
	QuickSortSteps(myVector, vectorLeftBound, vectorLeftEdge - 1);

	QuickSortSteps(myVector, vectorLeftEdge + 1, vectorRightBound);
}

template <typename E>
void Print(std::vector<E> myVector) {
	std::cout << "==== " << std::endl;
	for (auto i : myVector) {
		std::cout << " " << i << " " ;
	}
	std::cout << "\n==== " << std::endl;
}
void main() {
	std::vector<int> myVector = { 1, 5, 4, 6, 2, 10, 3 };
	std::cout << std::endl;
	Print(myVector);

	QuickSort(myVector);
	std::cout << std::endl;
	Print(myVector);

	std::cout << std::endl;
	system("pause");
}