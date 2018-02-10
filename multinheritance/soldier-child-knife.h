#ifndef SOLDIERCHILDKNIFE_H
#define SOLDIERCHILDKNIFE_H
#include <string>
#include <vector>
#include <iostream>
#include "soldier.h"
class SoldierChildKnife : Soldier{
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	SoldierChildKnife();
	virtual void printInfo();
	std::vector<std::string> getSoldierAbilities();
};
#endif // !SOLDIERCHILDKNIFE_H
