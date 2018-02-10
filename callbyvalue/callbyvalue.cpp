/*
callbyvalue.cpp
Dec 20, 2016
udichje
*/

#include <iostream>
using namespace std;
void addFive(int a, int b)
{
	cout << "--==Entering addFive function==--" << endl;
	cout << "a and B before adding 5: a = " << a << " b = " << b << endl;
	a += 5;
	b += 5;
	cout << "a and B after adding 5: a = " << a << " b = " << b << endl;
	cout << "--==Leaving addFive function==--" << endl;

}
int main(){
	int a = 0;
	int b = 0;
	cout << "a and B before function : a = " << a << " b = " << b << endl;
	addFive(a, b);
	cout << "a and B after function : a = " << a << " b = " << b << endl;

	return 0;
}
