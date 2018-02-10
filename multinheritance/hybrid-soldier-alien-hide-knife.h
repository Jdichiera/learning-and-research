#ifndef HYBRIDSOLDIERALIENHIDEKNIFE_H
#define HYBRIDSOLDIERALIENHIDEKNIFE_H
#include "alien-child-hide.h"
#include "soldier-child-knife.h"
#include <string>
#include <vector>
class HybridSoldierAlienHideKnife :AlienChildHide, SoldierChildKnife {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	HybridSoldierAlienHideKnife();
	void printInfo();
};
#endif // !HYBRIDSOLDIERALIENHIDEKNIFE_H
