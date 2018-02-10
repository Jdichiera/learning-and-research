#ifndef SOLDIERCHILDMISSLE_H
#define SOLDIERCHILDMISSLE_H
#include <string>
#include <vector>
#include <iostream>
#include "soldier.h"
class SoldierChildMissle : Soldier {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	SoldierChildMissle();
	virtual void printInfo();
	std::vector<std::string> getSoldierAbilities();
};
#endif // !SOLDIERCHILDMISSLE_H
