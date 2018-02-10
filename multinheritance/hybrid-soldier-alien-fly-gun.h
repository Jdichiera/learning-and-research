#ifndef HYBRIDSOLDIERALIENFLYGUN_H
#define HYBRIDSOLDIERALIENFLYGUN_H
#include "alien-child-fly.h"
#include "soldier-child-gun.h"
#include <string>
#include <vector>
class HybridSoldierAlienFlyGun :AlienChildFly, SoldierChildGun {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	HybridSoldierAlienFlyGun();
	void printInfo();
};
#endif // !HYBRIDSOLDIERALIENFLYGUN_H
