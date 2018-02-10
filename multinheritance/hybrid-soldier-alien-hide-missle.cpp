#include "hybrid-soldier-alien-hide-missle.h"

HybridSoldierAlienHideMissle::HybridSoldierAlienHideMissle() : AlienChildHide(), SoldierChildMissle()
{
	ability = "Hide and Missle (Derived from Alien and Soldier child classes)";
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

void HybridSoldierAlienHideMissle::printInfo()
{
	std::cout << "\n--== Hybrid Child : Hide Missle ==--";
	std::cout << "\nDerived from classes: SoldierChildMissle and AlienChildHide";
	std::cout << "\n=Combined Abilities=\n";
	for (std::string ability : abilitiesList) {
		std::cout  << ability << std::endl;
	}
}
