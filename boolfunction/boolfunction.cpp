/*
boolfunction.cpp
Dec 20, 2016
udichje
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int number;
bool guess(int);

int main(){
	int usernum;
	srand(time(0));
	number = rand() % 50 + 1;
	cout << "Guess a number between 1 and 50" << endl;
	cin >> usernum;
	while(guess(usernum) != true)
	{
		cin >> usernum;
	}
	cout << "You guessed it!" << endl;

	return 0;
}

bool guess(int num)
{
	if(num == number)
		return true;
	if(num > number)
		cout << "Too high" << endl << "Try again:" << endl;
	else
		cout << "Too low" << endl << "Try again:" << endl;
	return false;
}
