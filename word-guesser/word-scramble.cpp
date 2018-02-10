// Filename     : word-scramble.cpp
// Author       : Jeramy Dichiera
// Created      : 07/27/2017
// Description  : A word unscrambling game. The computer will present a scrambled word
//					and the player must unscramble it.

#include <algorithm> // random shuffle
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

struct GameWord {
	std::string scrambledWord;
	std::string word;
	std::string hint;
};

std::vector<GameWord> GenerateWordList() {
	std::cout << "\n\nGenerating word list ...";
	// Should be incremented as the word dictionary is increased
	const int NUM_WORDS = 5;
	GameWord gameWord;
	std::vector<GameWord> gameWords;
	std::string words[NUM_WORDS] =
	{
		"persistent",
		"jump",
		"king",
		"trashbag",
		"dictionary"
	};
	std::string hints[NUM_WORDS] =
	{
		"Keep at it.",
		"Leap into the air.",
		"Ruler of the land.",
		"Lines the trash can",
		"Look up the meaning for words"

	};

	for (int i = 0; i < NUM_WORDS; i++) {
		gameWord.scrambledWord = words[i];
		std::random_shuffle(gameWord.scrambledWord.begin(), gameWord.scrambledWord.end());
		gameWord.word = words[i];
		gameWord.hint = hints[i];
		gameWords.push_back(gameWord);
	}
	return gameWords;
}
void DisplayIntro() {
	std::cout << "\n\n\t --== Word Scramble ==--";
	std::cout << "\n==================================================";
	std::cout << "\nIn this game I will display a scrambled word that \nyou must unscramble.";
	std::cout << "\n\nTry to guess the word in as few tries as possible!";
	std::cout << "\n==================================================\n";
}

void DisplayWord(GameWord word) {
	std::cout << "\n\nThe scrambled word is :";
	std::cout << "\n=================================";
	std::cout << "\n\t" << word.scrambledWord;
	std::cout << "\n=================================\n";
}


void DisplayHint(GameWord word) {
	//std::cout << "\n\nThe scrambled word is :";
	//std::cout << "\n=================================";
	//std::cout << "\n\t" << word.word;
	std::cout << "\n--==Hint: " <<  word.hint << " ==--";
	//std::cout << "\n=================================\n";
}
std::string GetGuess(int guessCount) {
	std::string guess;
	std::cout << "\n\nType the word below.";
	std::cout << "\n(type ? for a hint at the penalty of one guess)";
	std::cout << "\n(type quit to exit the game)";
	std::cout << "\n\nGuess #" << guessCount << ":->";
	std::cin >> guess;
	return guess;
}

bool CheckGuess(std::string guess, GameWord word) {
	if (guess == "?") {
		DisplayHint(word);
	}

	if (guess == "quit") {
		std::cout << "\nQuitting game ... ";
		exit(0);
	}

	if (guess == word.word) {
		return true;
	}
	return false;
}

void WinMessage(int guessCount, GameWord word) {
	std::cout << "\n=================================";
	std::cout << "\n\t" << word.scrambledWord << " --> " << word.word;
	std::cout << "\n\nYou guessed correct in " << guessCount << " tries!!";
	std::cout << "\n=================================\n";
}

void PlayGame() {
	int guessCount = 0;
	bool guessCorrect = false;
	std::vector<GameWord> gameWords = GenerateWordList();
	int choice = (rand() % gameWords.size());

	DisplayIntro();
	GameWord word = gameWords[choice];
	while (!guessCorrect) {
		guessCount++;
		DisplayWord(word);
		guessCorrect = CheckGuess(GetGuess(guessCount), word);
	}
	WinMessage(guessCount, word);
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	PlayGame();
	return 0;
}