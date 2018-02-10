/*  
 * Author: Jeramy Dichiera
 * Created on October 7, 2017, 12:01 PM
 * File:   main.cpp
 *
 */

#include <cstdlib>
#include <iostream>
#include <array>
#include "record.h"

const std::size_t ARRAYSIZE{ 10 };

int getIntInput() {
	int input = 0;
	std::cin >> input;
	return input;
}
std::string getStringInput() {
	std::string input = "";
	std::cin >> input;
	return input;
}
void initAddressBook(std::array<Record, ARRAYSIZE> addressBook){
	for (std::size_t i{ 0 }; i < addressBook.size(); ++i) {
            try{
                Record newRecord(i + 1, "", "", 0,"");
                addressBook[i] = newRecord;
            }
            catch (...){
                std::cout << "Exception Occurred - Unable to instantiate record class...";
            }
        
        
    }
}
void addUpdateRecords(std::array<Record, ARRAYSIZE> &addressBook){
    int record = 0;
    int intInput = 0;
    std::string stringInput = "";

    std::cout << "\nWhich record would you like to update? (1 - 10)";
    std::cout << "\n>:";
    record = getIntInput();
    std::cout << "\nEditing record " << record;
    addressBook[record - 1].printRecord();
    std::cout << "\nInput new first name";
    std::cout << "\n>:";
	stringInput = getStringInput();
    addressBook[record - 1].setFirstName(stringInput);
    std::cout << "\nInput new last name";
    std::cout << "\n>:";
	stringInput = getStringInput();
    addressBook[record - 1].setLastName(stringInput);
    std::cout << "\nInput new phone number";
    std::cout << "\n>:";
	stringInput = getStringInput();
    addressBook[record - 1].setTelephoneNumber(stringInput);
    std::cout << "\nInput new age";
    std::cout << "\n>:";
    intInput = getIntInput();
    addressBook[record - 1].setAge(intInput);
}

void displayRecords(std::array<Record, ARRAYSIZE> addressBook){
	for (std::size_t i{0}; i < addressBook.size(); ++i) {
        addressBook[i].printRecord();
    }
    std::cout << "\nDisplay Records";
}

int main(int argc, char** argv) {
	
    int input = 0;
	std::array<Record, ARRAYSIZE> addressBook;
    bool exit = false;
    
    initAddressBook(addressBook);
    while(!exit){
        std::cout << "\n--== Address Book ==-- ";
        std::cout << "\n  1. Add or Update Record ";
        std::cout << "\n  2. Display All Records ";
        std::cout << "\n  9. Exit Program ";
		input = getIntInput();
        //handleInput(input);
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

