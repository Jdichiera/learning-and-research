#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>

class Soldier {
private:
	std::string ability;

public:
	Soldier();
	std::string getAbility();
	virtual void printInfo();
};
#endif // !SOLDIER_H
