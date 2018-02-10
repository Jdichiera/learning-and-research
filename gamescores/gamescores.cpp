#include <iostream>
using namespace std;

int scoreAverage(int a, int b, int c){
	int total_score = a + b + c;
	int average = total_score / 3;
	return average;
}
int main()
{
	int score1 = 0;
	int score2 = 0;
	int score3 = 0;
	int average = 0;

	cout << "Enter score 1" << endl;
	cin >> score1;
	cout << "Enter score 2" << endl;
	cin >> score2;
	cout << "Enter score 3" << endl;
	cin >> score3;
	average = scoreAverage(score1, score2, score3);
	cout << "The average is : " << average << endl;
	return 0;
}
