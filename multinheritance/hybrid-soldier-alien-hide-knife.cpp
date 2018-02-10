#include "hybrid-soldier-alien-hide-knife.h"

HybridSoldierAlienHideKnife::HybridSoldierAlienHideKnife() : AlienChildHide(), SoldierChildKnife()
{
	ability = "Hide and Knife (Derived from Alien and Soldier child classes)";
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

void HybridSoldierAlienHideKnife::printInfo()
{
	std::cout << "\n--== Hybrid Child : Hide Knife ==--";
	std::cout << "\nDerived from classes: SoldierChildKnife and AlienChildHide";
	std::cout << "\n=Combined Abilities=\n";
	for (std::string ability : abilitiesList) {
		std::cout << ability << std::endl;
	}
}
