#include "hybrid-soldier-alien-fly-gun.h"

HybridSoldierAlienFlyGun::HybridSoldierAlienFlyGun() : AlienChildFly(), SoldierChildGun()
{
	ability = "Fly and Gun (Derived from Alien and Soldier child classes)";
	abilitiesList.push_back(ability);
	std::vector<std::string> alienAbilities = getAlienAbilities();
	std::vector<std::string> soldierAbilities = getSoldierAbilities();
	for (std::string ability : alienAbilities) {
		abilitiesList.push_back(ability);
	}
	for (std::string ability : soldierAbilities) {
		abilitiesList.push_back(ability);
	}
}

void HybridSoldierAlienFlyGun::printInfo()
{
	std::cout << "\n--== Hybrid Child : Fly Gun ==--";
	std::cout << "\nDerived from classes: SoldierChildGun and AlienChildFly";
	std::cout << "\n=Combined Abilities=\n";
	for (std::string ability : abilitiesList) {
		std::cout << ability << std::endl;
	}
}
