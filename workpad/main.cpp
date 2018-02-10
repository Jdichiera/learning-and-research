#include <limits> // find limits of data structures
#include <iostream>
#include <iomanip>

int main() {
	double input = 0;
	/*std::cout << "\nInteger limit : " << std::numeric_limits<int>::max();
	std::cout << "\nlong limit : " << std::fixed << std::numeric_limits<long>::max();
	std::cout << "\nFloat limit : " << std::fixed << std::setprecision(0) << std::numeric_limits<float>::max();
	std::cout << "\ndouble limit : " << std::fixed << std::numeric_limits<double>::max() << std::endl;*/
	std::cout << "\nEnter a float -> ";

	// Entering
	std::cin.clear();
	std::cin >> input;
	std::cin.ignore();
	std::cout << "\nInput : " << std::fixed << std::setprecision(0) << input;
	system("pause");
	return 0;
}