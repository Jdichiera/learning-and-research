/*
* Author: Jeramy Dichiera
* Created on October 7, 2017, 12:01 PM
* File:   main.cpp
*
*/

#include <cstdlib>
#include <iostream>
#include "record.h"

void initAddressBook(Record addressBook[]) {
	for (int i = 0; i < 10; i++) {
		Record newRecord(i + 1, "", "", 0, "");
		addressBook[i] = newRecord;
	}
}
void addUpdateRecords(Record addressBook[]) {
	int record = 0;
	int intInput = 0;
	std::string stringInput = "";
	std::cout << "\nWhich record would you like to update? (1 - 10)";
	std::cout << "\n>:";
	std::cin >> record;
	std::cout << "\nEditing record " << record;
	addressBook[record - 1].printRecord();
	std::cout << "\nInput new first name";
	std::cout << "\n>:";
	std::cin >> stringInput;
	addressBook[record - 1].setFirstName(stringInput);
	std::cout << "\nInput new last name";
	std::cout << "\n>:";
	std::cin >> stringInput;
	addressBook[record - 1].setLastName(stringInput);
	std::cout << "\nInput new phone number";
	std::cout << "\n>:";
	std::cin >> stringInput;
	addressBook[record - 1].setTelephoneNumber(stringInput);
	std::cout << "\nInput new age";
	std::cout << "\n>:";
	std::cin >> intInput;
	addressBook[record - 1].setAge(intInput);
}

void displayRecords(Record addressBook[]) {
	for (int i = 0; i < 10; i++) {
		addressBook[i].printRecord();
	}
	std::cout << "\nDisplay Records";
}

void handleInput(int selection) {

}
int main(int argc, char** argv) {
	int input = 0;
	Record addressBook[10];
	bool exit = false;

	initAddressBook(addressBook);
	while (!exit) {
		std::cout << "\n--== Address Book ==-- ";
		std::cout << "\n  1. Add or Update Record ";
		std::cout << "\n  2. Display All Records ";
		std::cout << "\n  9. Exit Program ";
		std::cin >> input;
		//handleInput(input);
		switch (input) {
		case 1:
			addUpdateRecords(addressBook);
			break;
		case 2:
			displayRecords(addressBook);
			break;
		case 9:
			exit = true;
			break;
		}
	}
	return 0;
}

