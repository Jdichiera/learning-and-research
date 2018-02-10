// Filename     : virtual-pet.cpp
// Author       : Jeramy Dichiera
// Created      : 07/25/2017
// Description  : This program simulates a simple vuirtual pet. Each turn, the pet may 
//					get bored, or hungry, and it's mood may change. The owner must 
//					take care of the pet by feeding, talking, and playing with it.

#include <iostream>
#include <cstdlib> // system("pause");

class Pet {
public:
	Pet(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat();
	void Play();
	void PrintFace();

private:
	int hunger;
	int boredom;
	int GetMood() const;
	void PassTime(int time = 1);
};

Pet::Pet(int hunger, int boredom) {
	this->hunger = hunger;
	this->boredom = boredom;
}

inline int Pet::GetMood() const {
	return (this->hunger + this->boredom);
}

void Pet::Eat() {
	std::cout << "You feed your pet some snacks ...";
	this->hunger -= 4;
	PassTime();
}

void Pet::Play() {
	std::cout << "You play a game with your pet ...";
	this->boredom -= 4;
	PassTime();
}

void Pet::PassTime(int time) {
	this->hunger += time;
	this->boredom += time;
}

void Pet::Talk() {
	std::cout << "Hello, I'm your pet and I feel " << "H: " << this->hunger << " B: " << this->boredom;
	int mood = GetMood();
	if (mood > 15)
	{
		std::cout << "mad.\n";
	}
	else if (mood > 10)
	{
		std::cout << "frustrated.\n";
	}
	else if (mood > 5)
	{
		std::cout << "okay.\n";
	}
	else
	{
		std::cout << "happy.\n";
	}

	PassTime();
}

void Pet::PrintFace() {
	int mood = GetMood();
	if (mood > 15)
	{
		std::cout << "|(*=*)|\n";
	}
	else if (mood > 10)
	{
		std::cout << "(-.-)\n";
	}
	else if (mood > 5)
	{
		std::cout << "-('-')-\n";
	}
	else
	{
		std::cout << "\\(^o^)/\n";
	}
}
int main() {
	Pet pet;

	int choice = 1;
	while (choice != 0)
	{
		std::cout << "\n--==Virtual Pet==--\n\n";
		pet.PrintFace();
		std::cout << "\n1 - Talk to pet\n";
		std::cout << "2 - Play with pet\n";
		std::cout << "3 - Feed pet\n";
		std::cout << "\n\n5 - Quit\n";

		std::cout << "Choice: ->";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			pet.Talk();
			break;
		case 2:
			pet.Play();
			break;
		case 3:
			pet.Eat();
			break;
		case 5:
			std::cout << "Good-bye.\n";
			choice = 0;
			break;
		default:
			std::cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	}
	system("pause");
	return 0;
}