#include "employer.h"
class Service : public Employer {

private:

	int z;

public:

	void print() {
		std::cout << "I am service";
	}

};