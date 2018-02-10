/*High Scores
 * Demonstrates algorithms from STL
 * Unsure why RND is not working.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int myrandom (int i) { return std::rand()%i;}

int main()
{

	srand(unsigned (time(NULL)));
	vector<int>::const_iterator iter;
	cout << "Creating score list";
	vector<int> scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);
	scores.push_back(455);
	scores.push_back(32);
	scores.push_back(6776);
	scores.push_back(789);

//	cout << "\nHigh Scores:\n";
//
//	for (iter = scores.begin(); iter != scores.end(); ++iter)
//	{
//		cout << *iter << endl;
//	}
//	cout << "\nFinding a score.";
//	int score;
//	cout <<"\nEnter a score to find: ";
//	cin >> score;
//
//	iter = find(scores.begin(), scores.end(), score);
//	if(iter != scores.end())
//	{
//		cout << "Score found.\n";
//	}
//	else
//	{
//		cout << "Score not found.\n";
//	}

	cout << "\nRandomizing scores.";
	random_shuffle(scores.begin(), scores.end(), myrandom);

	cout<< "\nHigh Scores:\n";
	for(iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}

//	cout << "\nSorting scores.";
//	sort(scores.begin(), scores.end());
//	cout << "\nHigh Scores:\n";
//	for(iter = scores.begin(); iter != scores.end(); ++iter)
//	{
//		cout << *iter << endl;
//	}

	return 0;
}
