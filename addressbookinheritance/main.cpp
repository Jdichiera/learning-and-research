/* 
 * Author: Jeramy Dichiera
 * Created on October 7, 2017, 12:01 PM
 * File:   main.cpp
 *
 */

#include <cstdlib>
#include <iostream>
#include "record.h"
#include <vector>

void initAddressBook(std::vector<Record> &addressBook){
	for (std::size_t i{ 0 }; i < 10; i++) {
		try {
			Record newRecord(i + 1, "", "", 0, "","");
			addressBook.push_back(newRecord);
		}
		catch (...) {
			std::cout << "Exception Occurred - Unable to instantiate record class...";
		}
    }
}
void addUpdateRecords(std::vector<Record> &addressBook){
	//TODO :
	// Prevent user from entering out of bounds
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
    addressBook[record - 1].updateFirstName(stringInput);
    std::cout << "\nInput new last name";
    std::cout << "\n>:";
    std::cin >> stringInput;
    addressBook[record - 1].updateLastName(stringInput);
    std::cout << "\nInput new phone number";
    std::cout << "\n>:";
    std::cin >> stringInput;
    addressBook[record - 1].updateTelephonenumber(stringInput);
    std::cout << "\nInput new age";
    std::cout << "\n>:";
    std::cin >> intInput;
    addressBook[record - 1].updateAge(intInput);
	std::cout << "\nInput new employer name";
	std::cout << "\n>:";
	std::cin >> stringInput;
	addressBook[record - 1].updateEmployer(stringInput);
}

void displayRecords(std::vector<Record> addressBook){
	for (Record record : addressBook) {
		record.printRecord();
	}
    std::cout << "\nDisplay Records";
}

int main(int argc, char** argv) {
	
    int input = 0;
	std::vector<Record> addressBook;
    bool exit = false;
    
    initAddressBook(addressBook);
    while(!exit){
        std::cout << "\n--== Address Book ==-- ";
        std::cout << "\n  1. Add or Update Record ";
        std::cout << "\n  2. Display All Records ";
        std::cout << "\n  9. Exit Program ";
        std::cin >> input;
        switch(input){
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

