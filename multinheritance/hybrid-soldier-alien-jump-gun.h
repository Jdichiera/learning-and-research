#ifndef HYBRIDSOLDIERALIENJUMPGUN_H
#define HYBRIDSOLDIERALIENJUMPGUN_H
#include "alien-child-jump.h"
#include "soldier-child-gun.h"
#include <string>
#include <vector>
class HybridSoldierAlienJumpGun :AlienChildJump, SoldierChildGun {
private:
	std::string ability;
	std::vector<std::string> abilitiesList;
public:
	HybridSoldierAlienJumpGun();
	void printInfo();
};
#endif // !HYBRIDSOLDIERALIENJUMPGUN_H
