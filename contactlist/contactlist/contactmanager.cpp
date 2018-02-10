/*
Author: Jeramy Dichiera
Creation Date : 11/05/17
Modification Date : 11/06/17
FileName: contactmanager.cpp
Purpose: The main file for the ContactManager program
Input: None
Output: None
Exceptions: None
*/

#include "contact.h"
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <fstream>

/*
DisplayMenu()
Purpose : Displays the main menu for the program.
Input : None
Output : a return code to successfully close the program when control is returned to the main function.
*/
int displayMenu();
/*
DisplayShortCollection()
Purpose : Prints out a list of the items stored in the contact manager vector
Input : A vector of contact objects
Output : None
*/
void displayShortCollection(std::vector<Contact> collection);
/*
AddContact()
Purpose : Allows users to add in a contact to the contacts vector
Input : None
Output : None, but an object will be added to the vector at the end of the function
*/
void addContact();
/*
RemoveContact()
Purpose : Allows users to remove a contact from the contacts vector
Input : None
Output : None, but an object will be removed from the vector at the end of the function
*/
void removeContact();
/*
UpdateContact()
Purpose : Allows users to add in a contact to the contacts vector
Input : None
Output : None, but an object will be added to the vector at the end of a function
*/
void updateContact();
/*
getUpdateDecision()
Purpose : Allows the user to enter a decision for updating 
Input : None
Output : Returns a bool for the users decision for updating the contact
*/
bool getUpdateDecision();
/*
GetIntInput()
Purpose : Allows the user to enter integer type input
Input : None
Output : The integer input that the user entered
*/
int getIntInput();
/*
GetStringInput()
Purpose : Allows the user to enter string type input
Input : None
Output : The string input that the user entered
*/
std::string getStringInput();
/*
ViewContact()
Purpose : Displays all of the current contact information saved in the Contacts vector
Input : None
Output : None
*/
void viewContacts();
/*
QuitProgram()
Purpose : Allows the user to quit the program
Input : None
Output : None
*/
void quitProgram();
/*
Load()
Purpose : Loads a save file that holds contact information from the previous file load.
Input : A text file saved in the program folder
Output : None
*/
void load();
/*
Save()
Purpose : Writes the vector collection of Contact objects to a save file.
Input : None
Output : A text file saved in the program folder.
*/
void save();

// A global vector that stores the collection of Contact objects
std::vector<Contact> contactList;


int main() {
	load();
	displayMenu();
}

int displayMenu() {
	int menuSelection = 0;
	std::cout << "\n--== Main Menu ==--" << std::endl;
	std::cout << "1. Add New Contact" << std::endl;
	std::cout << "2. Remove Contact" << std::endl;
	std::cout << "3. Update Contact" << std::endl;
	std::cout << "4. View Contact List" << std::endl;
	std::cout << "5. Quit Contact Manager" << std::endl;
	std::cout << "Please make a selection between 1 and 5" << std::endl;
	std::cin >> menuSelection;

	switch (menuSelection) {
	case 1:
		addContact();
		break;
	case 2:
		removeContact();
		break;
	case 3:
		updateContact();
		break;
	case 4:
		viewContacts();
		break;
	case 5:
		quitProgram();
		return 0;
		break;
	default:
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
	displayMenu();
}

void displayShortCollection(std::vector<Contact> collection) {
	int counter = 1;
	std::cout << std::endl;
	for (Contact contact : collection) {
		std::cout << "( " << counter << " ) ";
		contact.shortInfo();
		std::cout << std::endl;
		counter++;
	}
}

void addContact() {
	int collectionNumber;
	std::string telephoneNumber;
	std::string firstName;
	std::string lastName;
	int employeeNumber;
	std::string programTeam;

	std::cout << "\n--== Add ==--" << std::endl;
	std::cout << "\nEnter Collection Number: ";
	std::cout << "\n:> ";
	std::cin >> collectionNumber;
	std::cout << "\nEnter Telephone Number: ";
	std::cout << "\n:> ";
	std::cin.ignore();
	std::getline(std::cin, telephoneNumber);
	std::cout << "\nEnter First Name: ";
	std::cout << "\n:> ";
	std::cin.ignore();
	std::getline(std::cin, firstName);
	std::cout << "\nEnter Last Name: ";
	std::cout << "\n:> ";
	std::cin.ignore();
	std::getline(std::cin, lastName);
	std::cout << "\nEnter Employee Number: ";
	std::cout << "\n:> ";
	std::cin >> employeeNumber;
	std::cout << "\nEnter Program Team: ";
	std::cout << "\n:> ";
	std::cin.ignore();
	std::getline(std::cin, programTeam);
	Contact newContact(collectionNumber, telephoneNumber, firstName, lastName, employeeNumber, programTeam);
	contactList.push_back(newContact);
}

void removeContact() {
	int selection;
	std::cout << "\n--== Remove ==--" << std::endl;
	displayShortCollection(contactList);
	std::cout << "\nWhich record would you like to remove?" << std::endl;
	std::cout << "\n:> ";
	std::cin >> selection;
	std::cout << "Removing record";
	contactList.erase(contactList.begin() + (selection - 1));
}

void updateContact() {
	int selection;
	std::cout << "\n--== Update ==--" << std::endl;
	displayShortCollection(contactList);
	std::cout << "\nWhich record would you like to update?" << std::endl;
	std::cout << "\n:> ";
	std::cin >> selection;
	std::cout << "\nUpdating contact";
	contactList[selection - 1].shortInfo();
	std::cout << "\n---------";

	std::cout << "\nCurrent Contact Number : " << contactList[selection - 1].getContactNumber();
	if (getUpdateDecision()) {
		contactList[selection - 1].setContactNumber(getIntInput());
	}

	std::cout << "\nCurrent First Name : " << contactList[selection - 1].getFirstName();
	if (getUpdateDecision()) {
		contactList[selection - 1].setFirstName(getStringInput());
	}

	std::cout << "\nCurrent Last Name : " << contactList[selection - 1].getLastName();
	if (getUpdateDecision()) {
		contactList[selection - 1].setLastName(getStringInput());
	}

	std::cout << "\nCurrent Telephone Number : " << contactList[selection - 1].getPhoneNumber();
	if (getUpdateDecision()) {
		contactList[selection - 1].setPhoneNumber(getStringInput());
	}

	std::cout << "\nCurrent Employee Number : " << contactList[selection - 1].getEmployeeNumber();
	if (getUpdateDecision()) {
		contactList[selection - 1].setEmployeeNumber(getIntInput());
	}

	std::cout << "\nCurrent Employee Program Team : " << contactList[selection - 1].getProgramTeam();
	if (getUpdateDecision()) {
		contactList[selection - 1].setProgramTeam(getStringInput());
	}
}

bool getUpdateDecision() {
	char decision;
	std::cout << "\nUpdate? (Y/N)";
	std::cout << "\n:> ";
	std::cin >> decision;
	if (toupper(decision) == 'Y') {
		return true;
	}
	return false;
}

int getIntInput() {
	int intInput;
	std::cout << "\nEnter new information: ";
	std::cout << "\n:> ";
	std::cin >> intInput;
	return intInput;
}

std::string getStringInput() {
	std::string stringInput;
	std::cout << "\nEnter new information: ";
	std::cout << "\n:> ";
	std::cin.ignore();
	std::getline(std::cin, stringInput);
	return stringInput;
}

void viewContacts() {
	std::cout << "\n\n--==Contact List==--\n";
	for (Contact contact : contactList) {
		contact.displayInfo();
		std::cout << std::endl;
	}
	std::cout << "\n\n--==End Contact List==--\n\n";
}

void quitProgram() {
	std::cout << "\n--== Quit Program ==--" << std::endl;

	char decision;
	std::cout << "Do you want to quit?" << std::endl;
	std::cin >> decision;
	if (toupper(decision) == 'Y') {
		save();
	}
};

void load() {
	std::string saveFile = "savefile.txt";
	Contact tempContact(0,"","","",0,"");
	std::string line;
	std::ifstream file;
	file.open("savefile.txt");
	while (std::getline(file, line)) {
		int recordLength = 5;
		int i = 0;

		int contactNumber;
		std::string phoneNumber;
		std::string firstName;
		std::string lastName;
		int employeeNumber;
		std::string programTeam;

		std::size_t pos = 0;
		std::string tempArray[6];
		std::string delimiter = ";";

		while (((pos = line.find(delimiter)) != std::string::npos) && (i < recordLength)) {
			tempArray[i] = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			i++;
		}
		contactNumber = std::stoi(tempArray[0]);
		phoneNumber = tempArray[1];
		firstName = tempArray[2];
		lastName = tempArray[3];
		employeeNumber = std::stoi(tempArray[4]);
		programTeam = tempArray[5];

		tempContact.setContactNumber(contactNumber);
		tempContact.setPhoneNumber(phoneNumber);
		tempContact.setFirstName(firstName);
		tempContact.setLastName(lastName);
		tempContact.setEmployeeNumber(employeeNumber);
		tempContact.setProgramTeam(programTeam);

		contactList.push_back(tempContact);
	}
	file.close();
}

void save() {
	std::string saveFile = "savefile.txt";
	std::cout << "\n--== Save ==--" << std::endl;
	std::ofstream writeFile;

	writeFile.open(saveFile);

	for (Contact contact : contactList) {
		writeFile << contact.getContactNumber() << ";" << contact.getPhoneNumber() << ";"
			<< contact.getFirstName() << ";" << contact.getLastName() << ";"
			<< contact.getEmployeeNumber() << ";" << contact.getProgramTeam() << ";" << std::endl;
	}
	writeFile.close();
}