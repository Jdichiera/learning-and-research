#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	int number = 0;
	int computer_guess = 0;
	int tries = 0;

	cout << "Welcome to Numberguesser" << endl;
	cout << "In this game, you will choose a number and the computer will try to guess it" << endl;
	cout << "Please enter a number between 1 and 100 : " << endl;
	cin >> number;

	//Seed RNG
	srand(time(0));

	//Get computers guess
	tries++;
	computer_guess = rand() % 100 + 1;
	cout << "Attempt #" << tries << " : The computer guesses : " << computer_guess << endl;
	while (computer_guess != number || tries < 10)
	{
		if(computer_guess < number){
			cout << "Sorry computer, too low!" << endl;
			computer_guess = rand() % (100 - computer_guess + 1) + computer_guess;
			cout << "Attempt #" << tries << " : The computer guesses : " << computer_guess << endl;
		}
		else if(computer_guess > number){
					cout << "Sorry computer, too high!" << endl;
					computer_guess = rand() % (computer_guess - 0 + 1) + 1;
					cout << "Attempt #" << tries << " : The computer guesses : " << computer_guess << endl;
				}
		tries++;
	}
	cout << "You guessed it! " << number << " = " << computer_guess << endl;

	return 0;
}
