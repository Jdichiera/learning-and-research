#ifndef SOLDIERCHILDGUN_H
#define SOLDIERCHILDGUN_H
#include <string>
#include <vector>
#include <iostream>
#include "soldier.h"
class SoldierChildGun : Soldier {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	SoldierChildGun();
	virtual void printInfo();
	std::vector<std::string> getSoldierAbilities();
};
#endif // !SOLDIERCHILDGUN_H
