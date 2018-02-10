#ifndef HYBRIDSOLDIERALIENHIDEMISSLE_H
#define HYBRIDSOLDIERALIENHIDEMISSLE_H
#include "alien-child-hide.h"
#include "soldier-child-missle.h"
#include <string>
#include <vector>
class HybridSoldierAlienHideMissle :AlienChildHide, SoldierChildMissle {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	HybridSoldierAlienHideMissle();
	void printInfo();
};
#endif // !HYBRIDSOLDIERALIENHIDEMISSLE_H
