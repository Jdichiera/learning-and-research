#ifndef HYBRIDSOLDIERALIENFLYKNIFE_H
#define HYBRIDSOLDIERALIENFLYKNIFE_H
#include "alien-child-fly.h"
#include "soldier-child-knife.h"
#include <string>
#include <vector>
class HybridSoldierAlienFlyKnife :AlienChildFly, SoldierChildKnife {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	HybridSoldierAlienFlyKnife();
	void printInfo();
};
#endif // !HYBRIDSOLDIERALIENFLYKNIFE_H
