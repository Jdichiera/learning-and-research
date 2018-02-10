 //Filename     : hangman.cpp
 //Author       : Jeramy Dichiera
 //Created      : 08/01/2017
 //Description  : A simple implementation of the word guessing game Hangman.

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>


struct GameWord {
	std::string word;
	std::string hint;
};

void FixCase(char &letter) {
	if (!isupper(letter)) {
		letter = toupper(letter);
	}
}
void DisplayLogo() {
	std::cout << "\n--== HANGMAN ==--";
	std::cout << "\n--=============--";
	std::cout << "\n The rules are simple. Guess letters in the word before you hang.";
}


void DisplayHangman(int wrongGuessCount, std::string playerWord, std::string hint) {
	std::cout << "\n    _______";
	std::cout << "\n    ||    |";
	std::cout << "\n    ||    |";

	if (wrongGuessCount == 0) {

		std::cout << "\n    ||";
		std::cout << "\n    ||";
		std::cout << "\n    ||";
	}
	if (wrongGuessCount == 1) {

		std::cout << "\n    ||    @";
		std::cout << "\n    ||";
		std::cout << "\n    ||";
	}
	if (wrongGuessCount == 2) {
		std::cout << "\n    ||    [--]";
		std::cout << "\n    ||    ";
		std::cout << "\n    ||";

	}
	if (wrongGuessCount == 3) {

		std::cout << "\n    ||    [..]";
		std::cout << "\n    ||   /--\\";
		std::cout << "\n    ||";
	}
	if (wrongGuessCount == 4) {

		std::cout << "\n    ||   /[..]/";
		std::cout << "\n    ||    --";
		std::cout << "\n    ||";
	}
	if (wrongGuessCount == 5) {

		std::cout << "\n    ||   \/[oo]/";
		std::cout << "\n    ||    --";
		std::cout << "\n    ||    |";
	}
	if (wrongGuessCount == 6) {

		std::cout << "\n    ||    [xx]";
		std::cout << "\n    ||   /--\\";
		std::cout << "\n    ||    ||";
	}
	std::cout << "\n    ||";
	std::cout << "\n    ||";
	std::cout << "\n/========================\\";
	std::cout << "\n Word: " << playerWord;
	if (wrongGuessCount >= 3) {
		std::cout << "\n Hint: " << hint;
	}
	std::cout << "\n|________________________|";
}
void DisplayWrongGuessCount(int wrongGuessCount) {
	std::cout << "\n\nWrong Guesses : " << wrongGuessCount;
}

void DisplayPlayerGuessList(std::vector<char> playerGuessList) {
	std::cout << "\nLetters Guessed : ";
	for (auto letter : playerGuessList) {
		std::cout << letter << " ";
	}
}

void UpdatePlayerWord(char guessLetter, std::string &playerWord, std::string gameWord) {
	for (int i = 0; i < gameWord.length(); i++) {
		if (guessLetter == gameWord[i]) {
			playerWord[i] = gameWord[i];
		}
	}
}

void CheckDuplicateGuess(char &playerGuessLetter, std::vector<char> &playerGuessList) {
	FixCase(playerGuessLetter);
	std::vector<char>::iterator foundPosition;
	foundPosition = std::find(playerGuessList.begin(), playerGuessList.end(), playerGuessLetter);
	bool duplicateGuess =  foundPosition != playerGuessList.end();
	if (duplicateGuess) {
		std::cout << "\nYou already guessed that ...";
	}
	else {
		playerGuessList.push_back(playerGuessLetter);
		std::sort(playerGuessList.begin(), playerGuessList.end());
	}
}

void CheckPlayerGuess(char guessLetter, std::string gameWord, int &wrongGuessCount) {
	int found = gameWord.find(guessLetter);
	if (found == std::string::npos) {
		wrongGuessCount++;
	}
}

bool CheckGameWin(std::string playerWord, std::string gameWord) {
	return playerWord == gameWord;
}

void ClearPlayerWord(std::string &playerWord, std::string gameWord) {
	std::cout << "\nLength: " << gameWord.size() << std::endl;
	for (int i = 0; i < gameWord.length(); i++) {
		playerWord += "-";
	}
}

void GetPlayerGuess(char &playerGuess) {
	std::cout << "\n\n Your Guess ->";
	std::cin >> playerGuess;
}

void WinGame(std::string gameWord, int wrongGuessCount) {
	std::cout << "\n\nYou Won!!!";
	std::cout << "\nThe secret word was " << gameWord;
	std::cout << "\nYou guessed the word with " << wrongGuessCount << " wrong guesses.";
}

void LoseGame(std::string gameWord, int wrongGuessCount) {
	std::cout << "\n\nYou Lost!!!";
	std::cout << "\nThe secret word was " << gameWord;
	std::cout << "\nBetter luck next time ...";
}

TEST_CASE("Check win - true") {
	std::string testString = "bananna";
	REQUIRE(CheckGameWin("word", "word") == true);
}
TEST_CASE("Check win - false") {
	std::string testString = "bananna";
	REQUIRE(CheckGameWin("word", "w0rd") == false);
}

void FillGameList(std::vector<GameWord> &gameWordList) {
	const int SIZE = 3;
	std::string words[SIZE]{"ARRAY", "DOOR", "WATER"};
	std::string hints[SIZE]{ "A type of collection", "Close the _", "A nice drink of _" };
	GameWord gameWord;
	for (int i = 0; i < SIZE; i++) {
		gameWord.word = words[i];
		gameWord.hint = hints[i];
		gameWordList.push_back(gameWord);
	}
	std::random_shuffle(gameWordList.begin(), gameWordList.end());
}

GameWord SelectGameWord(std::vector<GameWord> &gameWordList) {
	GameWord gameWord;
	gameWord = gameWordList[0];
	gameWordList.erase(gameWordList.begin());
	return gameWord;
}

int main(int argc, char *argv[]) {
	if (argc == 2) {

		int result = Catch::Session().run(argc, argv);
		return (result < 0xff ? result : 0xff);
	}
	else {
		srand(static_cast<unsigned int>(time(0)));
		bool gameOver = false;
		int wrongGuessCount = 0;
		char playerGuessLetter;

		std::vector<GameWord> gameWordList;
		std::vector<char> playerGuessList;
		GameWord gameWord;
		std::string playerWord;

		FillGameList(gameWordList);
		
		gameWord = SelectGameWord(gameWordList);
		ClearPlayerWord(playerWord, gameWord.word);

		DisplayLogo();

		while (!gameOver) {
			DisplayHangman(wrongGuessCount, playerWord, gameWord.hint);
			DisplayWrongGuessCount(wrongGuessCount);
			DisplayPlayerGuessList(playerGuessList);
			GetPlayerGuess(playerGuessLetter);
			
			CheckDuplicateGuess(playerGuessLetter, playerGuessList);
			CheckPlayerGuess(playerGuessLetter, gameWord.word, wrongGuessCount);
			if (wrongGuessCount > 6) {
				LoseGame(gameWord.word, wrongGuessCount);
				gameOver = true;
			}
			else {
				UpdatePlayerWord(playerGuessLetter, playerWord, gameWord.word);
				if (CheckGameWin(playerWord, gameWord.word)) {
					WinGame(gameWord.word, wrongGuessCount);
					gameOver = true;
				}
			}
		}
	}
		return 0;
}