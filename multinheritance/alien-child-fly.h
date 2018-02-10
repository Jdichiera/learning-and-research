#ifndef ALIENCHILDFLY_H
#define ALIENCHILDFLY_H
#include "alien.h"
#include <string>
#include <iostream>
#include <vector>
class AlienChildFly : Alien {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	AlienChildFly();
	std::vector<std::string> getAlienAbilities();
	virtual void printInfo();
};
#endif // !ALIENCHILDFLY_H
