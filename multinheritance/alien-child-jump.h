#ifndef ALIENCHILDJUMP_H
#define ALIENCHILDJUMP_H
#include "alien.h"
#include <string>
#include <iostream>
#include <vector>
class AlienChildJump : Alien {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	AlienChildJump();
	std::vector<std::string> getAlienAbilities();
	virtual void printInfo();
};
#endif // !ALIENCHILDJUMP_H
