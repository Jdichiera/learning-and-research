#include "hybrid-soldier-alien-jump-gun.h"

HybridSoldierAlienJumpGun::HybridSoldierAlienJumpGun() : AlienChildJump(), SoldierChildGun()
{
	ability = "Jump and Gun (Derived from Alien and Soldier child classes)";
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

void HybridSoldierAlienJumpGun::printInfo()
{
	std::cout << "\n--== Hybrid Child : Jump Gun ==--";
	std::cout << "\nDerived from classes: SoldierChildGun and AlienChildJump";
	std::cout << "\n=Combined Abilities=\n";
	for (std::string ability : abilitiesList) {
		std::cout << ability << std::endl;
	}
}
