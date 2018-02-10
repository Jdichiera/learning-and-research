#include <iostream>
using namespace std;

int main(){
	int selection = 0;
	enum difficulty {EASY, MEDIUM, HARD, IMPOSSIBLE};
	cout << "--==Menu==--"<< endl;
	cout << "1. Easy " << endl;
	cout << "2. Medium " << endl;
	cout << "3. Hard " << endl;
	cout << "4. Impossible " << endl;
	cout << "--========--" << endl;
	cout << "Please choose a difficulty" << endl;
	cout << "Selection : ";
	cin >> selection;
	switch(selection)
	{
		case 1:
			cout << "You chose Easy" << endl;
			break;
		case 2:
			cout << "You chose Medium" << endl;
			break;
		case 3:
			cout << "You chose Hard" << endl;
			break;
		case 4:
			cout << "You chose Impossible" << endl;
			break;
		default:
			cout << "Not an option" << endl;

	}

	return 0;
}
