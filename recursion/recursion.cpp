#include <iostream>
#include <math.h>

bool IsPrime(int number, unsigned divisor) {
	//bool isPrime = false;
	if (number < 2) {
		//std::cout << std::endl << number << " is not prime.";
		//isPrime = false;
		return false;
	}

	if (divisor == 1) {
		std::cout << std::endl << number << " is prime.";
		//isPrime = true;
		return true;
	}
	else {
		if (number % divisor == 0) {
			//std::cout << std::endl << number << " is not prime.";
			//isPrime = false;
			return false;
		}
		else {
			return IsPrime(number, --divisor);
		}
	}


}

void main() {
	int number = 2;
	int numberArray[50];
	for (int i = 0; i < 50; i++) {
		numberArray[i] = i + 1;
	}

	for (int i = 0; i < 50; i++) {
		IsPrime(numberArray[i], numberArray[i] / 2);
	}


	system("pause");
}					