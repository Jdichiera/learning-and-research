// Filename		: merge-sort.cpp
// Author		: Jeramy Dichiera
// Created		: 07/18/2017
// Description	: Annotated example of a list merge-sort using function templates.

// A merge sort takes an unsorted list and breaks it down over and over until the main
// list has been broken down into a list of a single element. The main list is then
// rebuilt from the ground up by comparing the elements stored in the substrings.
// For example, if we have a string with 4 integers, 4, 3, 2, 1. That main string would
// be broken down into two substrings. Substring1 will contain integers 4, 3 
// and substring2 will contain integers 2, 1. Now, those substrings will be broken down
// into additional substrings with a single element. 
// Substring1-a contains 4
// Substring1-b contains 3
// Substring2-a contains 2
// Substring2-a contains 1
// Now that we have substring lists of single elements, we compare the elements and find
// the smaller one. Substring1-a and substring1-b are compared, and the lesser of the 
// values is written back to the main list. The process continues until the original
// list has been rewritten back in the correct order.

#include <iostream>
#include <cstdlib>
#include <list>			// std::list
#include <string>		// cout string types


// Create a template for the merge-sort. The template allows us to create a function that 
// is not bound by specific data types.
template<typename E>

// We are passing in references to a list of type E. 
// Parameters passed by reference can be altered by the function.
void MergeSort(std::list<E>& myList) {
	// Create an iterator for the list of type E.
	// typedef allows us to declare an alias for some object. 
	// Example, I can use the typedef to create an alias for what would normally be a
	// long item to type out.
	//		typedef unsigned long uLong
	// I am telling my application that for the remainder of this scope, I would like
	// to use uLong in the place of typing unsigned long. Using the typedef in this way
	// allows me to type
	//		ulong num = 99;
	// Instead of typing 
	//		unsigned long num = 99;
	// In the case of our example, we are adding syntactic sugar to our program by 
	// creating an alias to the list iterator. Doing this allows us to type
	//		Itor
	// instead of
	//		std::list<E>::iterator
	// Later in our program	
	typedef typename std::list<E>::iterator Itor;

	// Get the length of the list
	int listSize = myList.size();

	// If the list is one element long, then it is already as sorted as it is going to be
	// No need to try and sort anything, so we can exit from our function.
	if (listSize <= 1) {
		return;
	}

	// Create two lists of type E. These lists will be used to subdivide our main list.
	std::list<E> subList1;
	std::list<E> subList2;

	// Create our iterator for our list and set it to the beginning of the list.
	// If we did not use the typedef above, we would have to declare an iterator this way
	//		std::list<E>::iterator iterato = myList.begin();
	// This sets the listIterator variable to the address of the first element in myList
	Itor listIterator = myList.begin();

	/*Split the main list into two smaller lists. Since our iterator is pointing to 
	  the address of the first element in the list, we will need to dereference it using
	  the dereference operator *. Additionally, the ++ moves the iterator to the next
	  element in the list.
	  	subList1.push_back(*listIterator++);
	  copies the value of the current element pointed to by the iterator into subList1,
	  and then increments the iterator to point at the next element, getting it ready
	  for the next loop.
	  For the first sublist we start at the first element in the main list and copy each
	  element to our first sublist until we hit the middle of the main list.*/
	for (int i = 0; i < listSize/2; i++) {
		subList1.push_back(*listIterator++);
	}

	// For the second sublist we start at the halfway point in our main array and copy
	// each element to our second sublist. We have essentially cut our main list in half.
	for (int i = listSize /2; i < listSize; i++) {
		subList2.push_back(*listIterator++);
	}

	//PrintList(subList1, "subList1");
	//PrintList(subList2, "subList2");
	// Empty out our main list. we will fill it again from our sub lists later.
	myList.clear();

	// Recursively call the MergeSort function on the sublists we just created. This will
	// break each list down into smaller and smaller lists, until we are left with a
	// a single element.
	MergeSort(subList1);
	MergeSort(subList2);

	// Merge the lists back together
	Merge(subList1, subList2, myList);
}

// Redeclaring template temp datatypes for our Merge function
template<typename E>

// the Merge function takes two sublists and merges them into a main list. We are 
// reassembling the list that we broke apart in the MergeSort function.
void Merge(std::list<E>& subList1, std::list<E>& subList2, std::list<E> &myList) {
	// Declare a typedef for our iterator
	typedef typename std::list<E>::iterator Itor;

	// Create iterators for our two sublists. Set those iterators to point at the address
	// of our two sublists.
	Itor subList1Iterator = subList1.begin();
	Itor subList2Iterator = subList2.begin();

	// While the iterator for sublist 1 and the iterator for sublist 2 are not at the end
	// of the lists. Once we hit the end of either list we stop.
	while (subList1Iterator != subList1.end() && subList2Iterator != subList2.end()) {

		// Compare the values of the two substrings, and push the lowest value back onto
		// the main list. Just like in the MergeSort function, we are working with the
		// iterators by dereferencing them and then pointing the iterator at the next
		// element.
		if (*subList1Iterator < *subList2Iterator) {
			myList.push_back(*subList1Iterator++);
		}
		else {
			myList.push_back(*subList2Iterator++);
		}
	}

	// If one of the lists is larger than the other, we may break out of the previous
	// while loop while still having elements remaining in one of the sublists. The next
	// two while loops will add any remaining elements to the main list.
	while (subList1Iterator != subList1.end()) {
		myList.push_back(*subList1Iterator++);
	}

	while (subList2Iterator != subList2.end()) {
		myList.push_back(*subList2Iterator++);
	}
}

// Prints out a list of type E
template<typename E>
void PrintList(std::list<E> myList, std::string listName) {
	// Print out the values of the list. Note this is using the C++11 auto and for loop
	std::cout << "\nValues stored in " << listName;
	std::cout << "\n-----------------------------\n";
	for (auto number : myList) {
		std::cout << number << "  ";
	}
	std::cout << "\n-----------------------------";
}

void main() {

	std::list<int> myNumberList{5, 3, 7, 2, 10, 8, 9, 1, 4};
	std::list<std::string> myStringList{"a", "b", "z", "q", "n", "l", "k", "w", "p", "o" };

	std::cout << "\n--Unsorted list of ints:";
	PrintList(myNumberList, "myNumberList");
	MergeSort(myNumberList);
	std::cout << "\n\n--Sorted list of ints:";
	PrintList(myNumberList, "myNumberList");

	std::cout << "\n\n\n--Unsorted list of strings:";
	PrintList(myStringList, "myStringList");
	MergeSort(myStringList);
	std::cout << "\n\n--Sorted list of strings:";
	PrintList(myStringList, "myStringList");

	std::cout << std::endl;
	system("pause");
}