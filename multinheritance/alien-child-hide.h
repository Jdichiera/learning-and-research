#ifndef ALIENCHILDHIDE_H
#define ALIENCHILDHIDE_H
#include "alien.h"
#include <string>
#include <iostream>
#include <vector>
class AlienChildHide : Alien {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	AlienChildHide();
	std::vector<std::string> getAlienAbilities();
	virtual void printInfo();
};
#endif // !ALIENCHILDHIDE_H
