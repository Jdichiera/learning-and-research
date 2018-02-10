
#include "record.h"

/* 
 * File:   record.cpp
 * Author: Jeramy Dichiera
 *
 * Created on October 7, 2017, 12:07 PM
 */
#include "record.h"
#include <iostream>

Record::Record(){
    recordNumber = 0;
    firstName = "";
    lastName = "";
    age = 0;
    telephoneNumber = "";
}
Record::Record(int newRecordNumber, std::string newFirstName, std::string newLastName,
            int newAge, std::string newTelephoneNumber){
    recordNumber = newRecordNumber;
    firstName = newFirstName;
    lastName = newLastName;
    age = newAge;
    telephoneNumber = newTelephoneNumber;
}
int Record::getRecordNumber() {
    return recordNumber; 
}
std::string Record::getFirstName() {
    return firstName; 
}
std::string Record::getLastName(){
    return lastName;
}
void Record::setFirstName(std::string newFirstName){
    firstName = newFirstName;
}
void Record::setLastName(std::string newLastName){
    lastName = newLastName;
}

int Record::getAge(){
    return age;
}
void Record::setAge(int newAge){
    age = newAge;
}

std::string Record::getTelephoneNumber(){
    return telephoneNumber;
}
void Record::setTelephoneNumber(std::string newTelephoneNumber){
    telephoneNumber = newTelephoneNumber;
}

void Record::printRecord(){
    std::cout << "\n\t-- Record " << recordNumber << " --";
    std::cout << "\n\t  Name : " << lastName << " " << firstName;
    std::cout << "\n\t  Age : " << age;
    std::cout << "\n\t  Number : " << telephoneNumber;
}
