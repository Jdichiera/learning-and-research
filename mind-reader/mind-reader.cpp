// Filename     : mind-reader.cpp
// Author       : Jeramy Dichiera
// Created      : 07/24/2017
// Description  : A simple guessing game. The computer will generate a number between
//					1 and 100. The player will attempt to guess the number and the
//					computer will tell the player if they are high or low. If the player
//					guesses the number correctly, the computer will congratulate the 
//					player and tell them how many tries they used.

#include <iostream>
#include <cstdlib>
#include <ctime>

void Greeting() {
	std::cout << "\n\n--== Mind Reader ==--";
	std::cout << "\n=====================" << std::endl;
	std::cout << "\nI will think of a number between 1 and 100." << "\nTry to guess the "
		<< "number in as few tries as possible!!" << std::endl;
	std::cout << "\n\nThinking of a number ...... got it!" << std::endl;
}

int GenerateNumber() {
	// TODO : Get a better seed. maybe something like http://bit.ly/2tuh6K9
	srand(time(NULL));
	int number = rand() % 100 + 1;
	return number;
}

bool CheckGuessCorrect(int playerGuess, int secretNumber) {
	bool guessIsCorrect = false;
	if (playerGuess == secretNumber) {
		guessIsCorrect = true;
	}
	return guessIsCorrect;
}

void PlayerWon(int secretNumber, int guessCounter) {
	std::cout << "\nCorrect!! the secret number is " << secretNumber;
	std::cout << "\nYou guessed it in " << guessCounter << " tries!!";
}

void CheckGuessHighLow(int playerGuess, int secretNumber) {
	std::cout << "\nSorry, guess again ...";
	if (playerGuess < secretNumber) {
		std::cout << "\nMaybe try a higher number this time.";
	}
	else {
		std::cout << "\nWhy not try a lower number?";
	}
}

bool PlayerGuess(int secretNumber, int &guessCounter) {
	int playerGuess = 0;
	bool numberGuessed = false;

	std::cout << "\n\nGuess #" << guessCounter << ": ";
	std::cin >> playerGuess;
	numberGuessed = CheckGuessCorrect(playerGuess, secretNumber);
	
	if (numberGuessed == true) {
		PlayerWon(secretNumber, guessCounter);
	}
	else {
		guessCounter++;
		CheckGuessHighLow(playerGuess, secretNumber);
	}
	return numberGuessed;
}


int main()
{
	bool gameOver = false;
	int secretNumber = GenerateNumber();
	int guessCounter = 1;

	std::cout << "\n\n--" << secretNumber << std::endl;

	while (!gameOver){
		gameOver = PlayerGuess(secretNumber, guessCounter);
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}
