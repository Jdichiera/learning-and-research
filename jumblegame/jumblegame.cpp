/*Jumble game
 * Classic word unscrambling game
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int points = 0;
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
			{"wall", "Bang your head against something"},
			{"glasses" , "These might help you see better"},
			{"labored", "labored"},
			{"persistent", "Keep trying"},
			{"jumble" , "its what this game is all about"}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];
	points = theWord.size();

	string jumble = theWord;
	int length = jumble.size();
	for(int i = 0; i < length; ++i){
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint\n";
	cout << "the jumble is : " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "guit"))
	{
		if(guess == "hint")
		{
			points -= 5;
			cout << theHint;
		}
		else
		{
			cout << "Sorry, try again";
		}
			cout << "\n\nYour guess: ";
			cin >> guess;
	}
	if(guess == theWord)
	{
		cout << "\nThats it!\n";
		cout << "\nYou got " << points << " points\n";
		cout << "\nThanks for playing.\n";
		return 0;
	}
}
